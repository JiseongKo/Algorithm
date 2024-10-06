#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N = 50000;

// Global variables
int N;
vector<vector<int>> adj;
bool removed_flag[50001];
int size_subtree[50001];
bool is_prime_arr[50001];
vector<int> primes;
int count_arr_global[50001];

// Function to compute primes using sieve of Eratosthenes
void sieve(int max_limit) {
    fill(is_prime_arr, is_prime_arr + max_limit + 1, true);
    is_prime_arr[0] = is_prime_arr[1] = false;
    for(int i=2;i<=max_limit;i++){
        if(is_prime_arr[i]){
            primes.push_back(i);
            for(int j=2*i; j<=max_limit; j+=i){
                is_prime_arr[j] = false;
            }
        }
    }
}

// Function to compute the size of each subtree
int compute_size(int u, int parent){
    size_subtree[u] =1;
    for(auto &v: adj[u]){
        if(v != parent && !removed_flag[v]){
            size_subtree[u] += compute_size(v, u);
        }
    }
    return size_subtree[u];
}

// Function to find the centroid
int find_centroid(int u, int parent, int total_size){
    for(auto &v: adj[u]){
        if(v != parent && !removed_flag[v] && size_subtree[v] > total_size /2){
            return find_centroid(v, u, total_size);
        }
    }
    return u;
}

// Function to collect distances from centroid
void collect_distances(int u, int parent, int depth, vector<int> &distances){
    distances.push_back(depth);
    for(auto &v: adj[u]){
        if(v != parent && !removed_flag[v]){
            collect_distances(v, u, depth +1, distances);
        }
    }
}

// Global variable to store total pairs
ll total_pairs =0;

// Centroid Decomposition function
void centroid_decompose(int u){
    // Step 1: compute size
    compute_size(u, -1);
    // Step 2: find centroid
    int c = find_centroid(u, -1, size_subtree[u]);
    // Step 3: mark centroid as removed
    removed_flag[c] = true;
    // Step 4: initialize count_arr
    // Reset count_arr_global
    // We'll track used distances to reset later
    vector<int> used_d;
    count_arr_global[0] =1;
    used_d.push_back(0);
    int max_count_dist =0;
    // Step 5: iterate through each subtree
    for(auto &v: adj[c]){
        if(!removed_flag[v]){
            vector<int> distances;
            collect_distances(v, c, 1, distances);
            // For each distance in this subtree
            for(auto &d: distances){
                // Find the first prime >=d
                // Using lower_bound
                auto it = lower_bound(primes.begin(), primes.end(), d);
                while(it != primes.end()){
                    int p = *it;
                    int d_prime = p - d;
                    if(d_prime <0){
                        ++it;
                        continue;
                    }
                    if(d_prime > max_count_dist){
                        break;
                    }
                    total_pairs += count_arr_global[d_prime];
                    ++it;
                }
            }
            // After counting, add the distances to count_arr_global
            for(auto &d: distances){
                if(count_arr_global[d] ==0){
                    used_d.push_back(d);
                }
                count_arr_global[d] +=1;
                if(d > max_count_dist){
                    max_count_dist =d;
                }
            }
        }
    }
    // Step 6: reset count_arr_global
    for(auto &d: used_d){
        count_arr_global[d] =0;
    }
    // Step 7: recurse on each subtree
    for(auto &v: adj[c]){
        if(!removed_flag[v]){
            centroid_decompose(v);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // Read N
    cin >> N;
    adj.assign(N+1, vector<int>());
    // Read edges
    for(int i=0;i<N-1;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // Compute primes up to N
    sieve(N);
    // Perform centroid decomposition
    centroid_decompose(1);
    // Calculate the probability
    double probability = (double) total_pairs / ((ll)N * (N-1) /2);
    // Output with 6 decimal places
    cout << fixed << setprecision(10) << probability;
}
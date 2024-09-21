#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 1e9;

// Hungarian Algorithm for Maximum Weight Matching in Bipartite Graphs
// Adapted for 1-based indexing
struct Hungarian {
    int n;
    vector<vector<int>> cost; // cost matrix
    vector<int> u, v; // potential
    vector<int> p, way; // matching

    Hungarian(int size) : n(size), cost(size + 1, vector<int>(size + 1, 0)),
                         u(size + 1, 0), v(size + 1, 0),
                         p(size + 1, 0), way(size + 1, 0) {}

    // Add cost for edge (i, j)
    void add_edge(int i, int j, int w){
        cost[i][j] = w;
    }

    // Returns the maximum weight and the matching as a vector where match[j] = i means i is matched to j
    pair<int, vector<int>> solve() {
        for(int i = 1; i <= n; ++i){
            p[0] = i;
            int j0 = 0;
            vector<int> minv(n + 1, INF);
            vector<bool> used(n + 1, false);
            vector<int> way_temp(n + 1, 0);
            int i0 = i;
            int j1;
            do{
                used[j0] = true;
                int i1 = p[j0];
                int delta = INF;
                int j2 = 0;
                for(int j = 1; j <= n; ++j){
                    if(!used[j]){
                        int cur = u[i1] + v[j] - cost[i1][j];
                        if(cur < minv[j]){
                            minv[j] = cur;
                            way_temp[j] = j0;
                        }
                        if(minv[j] < delta){
                            delta = minv[j];
                            j2 = j;
                        }
                    }
                }
                for(int j = 0; j <= n; ++j){
                    if(used[j]){
                        u[p[j]] -= delta;
                        v[j] += delta;
                    }
                    else{
                        minv[j] -= delta;
                    }
                }
                j0 = j2;
            } while(p[j0] != 0);
            
            do{
                int j1 = way_temp[j0];
                p[j0] = p[j1];
                j0 = j1;
            } while(j0 != 0);
        }

        // Calculate the total weight
        int total_weight = 0;
        for(int j = 1; j <= n; ++j){
            if(p[j] != 0){
                total_weight += cost[p[j]][j];
            }
        }

        // Build the matching
        vector<int> match(n + 1, 0); // match[j] = i
        for(int j = 1; j <= n; ++j){
            match[j] = p[j];
        }

        return {total_weight, match};
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    int K = max(N, M);
    Hungarian hungarian(K);
    // Initialize all costs to 0
    // Read employee capabilities
    for(int i = 1; i <= N; ++i){
        int cnt;
        cin >> cnt;
        for(int c = 0; c < cnt; ++c){
            int job, salary;
            cin >> job >> salary;
            // Assign W[i][j] = 100000 + salary
            hungarian.add_edge(i, job, 100000 + salary);
        }
    }
    // For padding, if K > N or K > M, the unused edges remain 0
    // Solve the Hungarian algorithm
    pair<int, vector<int>> result = hungarian.solve();
    int total_W = result.first;
    vector<int> match = result.second;
    // Count the number of real matches and sum their salaries
    int match_count = 0;
    long long total_salary = 0;
    for(int j = 1; j <= M; ++j){
        int i = match[j];
        if(i >=1 && i <= N){
            // Check if this edge was real (cost[i][j] >= 100000)
            if(hungarian.cost[i][j] >= 100000){
                match_count++;
                total_salary += (hungarian.cost[i][j] - 100000);
            }
        }
    }
    cout << match_count << "\n" << total_salary;
}

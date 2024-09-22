#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Hopcroft-Karp algorithm for Bipartite Matching
class HopcroftKarp {
public:
    int n; // Number of nodes on left
    int m; // Number of nodes on right
    vector<vector<int>> adj; // Adjacency list for left nodes
    vector<int> pair_U; // pair_U[u] = v matched with u
    vector<int> pair_V; // pair_V[v] = u matched with v
    vector<int> dist;    // Distance in BFS

    HopcroftKarp(int left_size, int right_size) {
        n = left_size;
        m = right_size;
        adj.assign(n, vector<int>());
        pair_U.assign(n, -1);
        pair_V.assign(m, -1);
        dist.assign(n + 1, 0);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    bool bfs() {
        queue<int> q;
        // Initialize distances
        for(int u = 0; u < n; u++) {
            if(pair_U[u] == -1) {
                dist[u] = 0;
                q.push(u);
            }
            else {
                dist[u] = INT32_MAX;
            }
        }
        dist[n] = INT32_MAX;

        while(!q.empty()) {
            int u = q.front(); q.pop();
            if(u < n) {
                for(auto &v : adj[u]) {
                    if(pair_V[v] == -1) {
                        if(dist[n] == INT32_MAX) {
                            dist[n] = dist[u] + 1;
                        }
                    }
                    else if(dist[pair_V[v]] == INT32_MAX) {
                        dist[pair_V[v]] = dist[u] + 1;
                        q.push(pair_V[v]);
                    }
                }
            }
        }
        return dist[n] != INT32_MAX;
    }

    bool dfs(int u) {
        if(u != n) {
            for(auto &v : adj[u]) {
                if(pair_V[v] == -1 || (dist[pair_V[v]] == dist[u] + 1 && dfs(pair_V[v]))) {
                    pair_U[u] = v;
                    pair_V[v] = u;
                    return true;
                }
            }
            dist[u] = INT32_MAX;
            return false;
        }
        return true;
    }

    int maxMatching() {
        int matching = 0;
        while(bfs()) {
            for(int u = 0; u < n; u++) {
                if(pair_U[u] == -1) {
                    if(dfs(u)) {
                        matching++;
                    }
                }
            }
        }
        return matching;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> sticks(N);
    for(auto &x : sticks) cin >> x;

    // Partition sticks into even and odd
    vector<int> left; // even
    vector<int> right; // odd
    for(auto &x : sticks){
        if(x % 2 == 0) left.push_back(x);
        else right.push_back(x);
    }

    int L = left.size();
    int R = right.size();

    // If no possible pairs
    if(L == 0 || R == 0){
        cout << "0";
        return 0;
    }

    // Initialize Hopcroft-Karp
    HopcroftKarp hk(L, R);

    // Build adjacency list
    for(int i = 0; i < L; i++){
        for(int j = 0; j < R; j++){
            int a = left[i];
            int b = right[j];
            // Check gcd(a,b) ==1
            if(__gcd(a, b) != 1) continue;
            // Check if a^2 + b^2 is a perfect square
            ll sum = (ll)a * a + (ll)b * b;
            double sq = sqrt((double)sum);
            ll c = round(sq);
            if(c * c == sum){
                hk.addEdge(i, j);
            }
        }
    }

    // Get maximum matching
    int matching = hk.maxMatching();

    cout << matching;
}

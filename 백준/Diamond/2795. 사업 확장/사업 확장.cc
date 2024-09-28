#include <bits/stdc++.h>
using namespace std;

// Function to perform BFS and find the shortest path from start to end
bool bfs(int start, int end, const vector<vector<int>> &graph, vector<int> &path) {
    int N = graph.size();
    vector<int> parent(N, -1);
    queue<int> q;
    q.push(start);
    parent[start] = -2; // Mark the start node

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for(auto &neighbor : graph[current]) {
            if(parent[neighbor] == -1) {
                parent[neighbor] = current;
                q.push(neighbor);
                if(neighbor == end) break;
            }
        }
    }

    if(parent[end] == -1) return false; // No path found

    // Reconstruct the path from end to start
    vector<int> temp;
    int node = end;
    while(node != -2) {
        temp.push_back(node);
        node = parent[node];
    }
    // Reverse to get the path from start to end
    path.assign(temp.rbegin(), temp.rend());
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    // Nodes are 1-based. We'll use 0-based indexing in the code.
    vector<vector<int>> graph(N+1, vector<int>());
    for(int i=0;i<M;i++){
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
    }

    int min_S = N; // Initialize with maximum possible value

    for(int v=1; v<=N; v++){
        // Check reachability conditions
        vector<int> path1, path2, path3, path4;
        bool cond1 = bfs(1, v, graph, path1);
        bool cond2 = bfs(v, 2, graph, path2);
        bool cond3 = bfs(2, v, graph, path3);
        bool cond4 = bfs(v, 1, graph, path4);

        if(cond1 && cond2 && cond3 && cond4){
            // Create a set to store unique nodes
            unordered_set<int> S;
            for(auto &node : path1) S.insert(node);
            for(auto &node : path2) S.insert(node);
            for(auto &node : path3) S.insert(node);
            for(auto &node : path4) S.insert(node);
            // Update the minimal S
            min_S = min(min_S, (int)S.size());
        }
    }

    cout << min_S;
}

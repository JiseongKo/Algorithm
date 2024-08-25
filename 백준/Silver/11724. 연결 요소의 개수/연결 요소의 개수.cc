#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[1001];
int visited[1001];

void DFS(int v) {
    visited[v] = 1;
    for (int i = 0; i < graph[v].size(); i++) {
        int nv = graph[v][i];
        if (visited[nv] == 0)
            DFS(nv);
    }
}

int main() {
    int N, M, u, v;
    int r = 0;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        if (visited[i] == 0) {
            r++;
            DFS(i);
        }
    }

    cout << r << '\n';
    return 0;
}
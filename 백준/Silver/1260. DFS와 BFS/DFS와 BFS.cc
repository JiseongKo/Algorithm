#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

vector<int> graph[1001];
bool visited[1001];
vector<int> dfs_result;
vector<int> bfs_result;

void bfs(int start_vertex) {
    queue<int> q;
    q.push(start_vertex);
    visited[start_vertex] = true;
    while (!q.empty()) {
        int current_vertex = q.front();
        q.pop();
        bfs_result.push_back(current_vertex);

        for (int i = 0; i < graph[current_vertex].size(); i++) {
            int next_vertex = graph[current_vertex][i];
            if (!visited[next_vertex]) {
                q.push(next_vertex);
                visited[next_vertex] = true;
            }
        }
    }
}

void dfs(int current_vertex) {
    visited[current_vertex] = true;
    dfs_result.push_back(current_vertex);

    for (int i = 0; i < graph[current_vertex].size(); i++) {
        int next_vertex = graph[current_vertex][i];
        if (!visited[next_vertex]) {
            dfs(next_vertex);
        }
    }
}

int main() {
    int N, M, V;
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        graph[vertex1].push_back(vertex2);
        graph[vertex2].push_back(vertex1);
    }

    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(V);
    memset(visited, false, sizeof(visited));
    bfs(V);

    for (int i = 0; i < dfs_result.size(); i++) {
        cout << dfs_result[i] << ' ';
    }
    cout << endl;

    for (int i = 0; i < bfs_result.size(); i++) {
        cout << bfs_result[i] << ' ';
    }

    return 0;
}
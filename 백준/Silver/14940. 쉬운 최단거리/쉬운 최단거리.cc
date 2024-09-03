#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, m, dis = 0;
    cin >> n >> m;
    vector<vector<int> > map(n, vector<int>(m));
    vector<vector<int> > distance(n, vector<int>(m));
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    queue<pair<int, int> > q;

    // 방향 벡터 (상, 하, 좌, 우)
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    // 입력 받기 및 초기 익은 토마토 큐에 추가
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                distance[i][j] = dis;
                visited[i][j] = true;
                q.push(make_pair(i, j));
            }
        }
    }

    // BFS 탐색
    while (!q.empty()) {
        int size = q.size();
        dis++;
        for (int i = 0; i < size; ++i) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    if (map[nx][ny] == 1 && !visited[nx][ny]) {
                        distance[nx][ny] = dis;
                        visited[nx][ny] = true;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (distance[i][j] == 0)
                if (map[i][j] == 1)
                    distance[i][j] = -1;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << distance[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int> > maze(N, vector<int>(M));
    vector<vector<bool> > visited(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++) {
            maze[i][j] = row[j] - '0';
        }
    }

    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    visited[0][0] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == N - 1 && y == M - 1) {
            cout << maze[x][y] << endl;
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                if (maze[nx][ny] == 1 && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    maze[nx][ny] = maze[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    return 0;
}
#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int M, N, H;
    cin >> M >> N >> H;
    vector<vector<vector<int> > > box(H, vector<vector<int> >(N, vector<int>(M)));
    queue<tuple<int, int, int> > q;
    int unripeCount = 0;

    // 방향 벡터 (상, 하, 좌, 우, 위, 아래)
    int dx[] = {0, 0, 0, 0, -1, 1};
    int dy[] = {0, 0, -1, 1, 0, 0};
    int dz[] = {-1, 1, 0, 0, 0, 0};

    // 입력 받기 및 초기 익은 토마토 큐에 추가
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> box[i][j][k];
                if (box[i][j][k] == 1) {
                    q.push(make_tuple(i, j, k)); // 익은 토마토 위치 큐에 추가
                } else if (box[i][j][k] == 0) {
                    unripeCount++; // 익지 않은 토마토 개수 카운트
                }
            }
        }
    }

    // 모든 토마토가 이미 익은 경우
    if (unripeCount == 0) {
        cout << 0 << endl;
        return 0;
    }

    int days = 0;

    // BFS 탐색
    while (!q.empty()) {
        int size = q.size();
        days++;
        for (int i = 0; i < size; ++i) {
            tuple<int, int, int> point = q.front();
            int z = get<0>(point);
            int x = get<1>(point);
            int y = get<2>(point);
            q.pop();

            for (int d = 0; d < 6; ++d) {
                int nz = z + dz[d];
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nz >= 0 && nz < H && nx >= 0 && nx < N && ny >= 0 && ny < M && box[nz][nx][ny] == 0) {
                    box[nz][nx][ny] = 1; // 익게 함
                    q.push(make_tuple(nz, nx, ny));
                    unripeCount--; // 익지 않은 토마토 개수 감소
                }
            }
        }
    }

    // 남은 익지 않은 토마토가 있는 경우
    if (unripeCount > 0) {
        cout << -1 << endl;
    } else {
        cout << days - 1 << endl; // 첫날부터 1일 증가하므로 하루 빼줌
    }

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<char> > picture;
vector<vector<bool> > visited;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, char color, bool colorBlind) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny]) {
            if (colorBlind) {
                if ((color == 'R' || color == 'G') && (picture[nx][ny] == 'R' || picture[nx][ny] == 'G')) {
                    dfs(nx, ny, color, colorBlind);
                }
                else if (picture[nx][ny] == color) {
                    dfs(nx, ny, color, colorBlind);
                }
            } else {
                if (picture[nx][ny] == color) {
                    dfs(nx, ny, color, colorBlind);
                }
            }
        }
    }
}

int countRegions(bool colorBlind) {
    visited.assign(N, vector<bool>(N, false));
    int regionCount = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                dfs(i, j, picture[i][j], colorBlind);
                regionCount++;
            }
        }
    }

    return regionCount;
}

int main() {
    cin >> N;
    picture.assign(N, vector<char>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> picture[i][j];
        }
    }

    int normalVision = countRegions(false);
    int colorBlindVision = countRegions(true);

    cout << normalVision << " " << colorBlindVision << endl;

    return 0;
}
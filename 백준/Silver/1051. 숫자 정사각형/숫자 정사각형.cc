#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<string> grid(N);
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }
    
    int max_size = 1; // 최소 정사각형 크기는 1
    
    // 모든 좌표 (i, j)를 정사각형의 왼쪽 위 꼭짓점으로 탐색
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // 정사각형 크기를 1부터 가능한 최대 크기까지 탐색
            for (int k = 1; i + k < N && j + k < M; k++) {
                // 각 꼭짓점이 같은 숫자인지 확인
                if (grid[i][j] == grid[i][j + k] && 
                    grid[i][j] == grid[i + k][j] && 
                    grid[i][j] == grid[i + k][j + k]) {
                    max_size = max(max_size, (k + 1) * (k + 1)); // 정사각형의 넓이
                }
            }
        }
    }
    
    cout << max_size << endl;
    
    return 0;
}

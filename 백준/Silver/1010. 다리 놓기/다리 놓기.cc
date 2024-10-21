#include <iostream>
using namespace std;

// 조합을 계산하는 함수
long long combination(int n, int r) {
    if (r == 0 || n == r) return 1;
    long long result = 1;
    for (int i = 1; i <= r; ++i) {
        result *= n--;
        result /= i;
    }
    return result;
}

int main() {
    int T; // 테스트 케이스의 수
    cin >> T;

    while (T--) {
        int N, M; // 서쪽과 동쪽 사이트의 수
        cin >> N >> M;

        // 서쪽 N개를 동쪽 M개 중에서 선택하는 경우의 수 계산
        cout << combination(M, N) << endl;
    }

    return 0;
}

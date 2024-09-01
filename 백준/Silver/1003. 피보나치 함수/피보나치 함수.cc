#include <iostream>
using namespace std;

int main() {
    int T, N;
    cin >> T;

    // 0과 1의 호출 횟수를 저장할 배열
    int dp[41][2] = {0};

    // 초기값 설정
    dp[0][0] = 1; // fibonacci(0)일 때 0은 1번 호출, 1은 0번 호출
    dp[0][1] = 0;
    dp[1][0] = 0; // fibonacci(1)일 때 0은 0번 호출, 1은 1번 호출
    dp[1][1] = 1;

    // DP 테이블 채우기
    for (int i = 2; i <= 40; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
        dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
    }

    // 테스트 케이스 처리
    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << dp[N][0] << " " << dp[N][1] << endl;
    }

    return 0;
}
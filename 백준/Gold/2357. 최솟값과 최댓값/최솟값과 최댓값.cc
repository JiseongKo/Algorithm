#include <bits/stdc++.h>
using namespace std;

int main(){
    // 빠른 입출력을 위해 설정
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    vector<int> A(N+1);
    for(int i=1; i<=N; ++i){
        cin >> A[i];
    }
    
    // 로그 테이블 미리 계산
    int LOG = 0;
    while((1 << LOG) <= N) LOG++;
    vector<int> log_table(N+1);
    log_table[1] = 0;
    for(int i=2; i<=N; ++i){
        log_table[i] = log_table[i/2] + 1;
    }
    
    // Sparse Table 생성 (최소값과 최대값용)
    vector<vector<int>> st_min(LOG, vector<int>(N+1));
    vector<vector<int>> st_max(LOG, vector<int>(N+1));
    
    // 초기 단계(k=0)
    for(int i=1; i<=N; ++i){
        st_min[0][i] = A[i];
        st_max[0][i] = A[i];
    }
    
    // 각 단계별로 Sparse Table 채우기
    for(int k=1; k<LOG; ++k){
        for(int i=1; i + (1<<k) -1 <= N; ++i){
            st_min[k][i] = min(st_min[k-1][i], st_min[k-1][i + (1 << (k-1))]);
            st_max[k][i] = max(st_max[k-1][i], st_max[k-1][i + (1 << (k-1))]);
        }
    }
    
    // 쿼리 처리
    string output = "";
    for(int q=0; q<M; ++q){
        int a, b;
        cin >> a >> b;
        int length = b - a + 1;
        int k = log_table[length];
        int min_val = min(st_min[k][a], st_min[k][b - (1 << k) +1]);
        int max_val = max(st_max[k][a], st_max[k][b - (1 << k) +1]);
        // 결과를 문자열에 저장
        output += to_string(min_val) + " " + to_string(max_val) + "\n";
    }
    // 모든 결과를 한 번에 출력
    cout << output;
}

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

// Function to compute the number of valid assignments when K > 0
long long count_assignments_K_positive(int N, int K) {
    // dp_prev[a][lastB][cUsed]
    // a: 0..K-1
    // lastB: 0 or 1
    // cUsed: 0 or 1
    vector<vector<vector<long long>>> dp_prev(K, vector<vector<long long>>(2, vector<long long>(2, 0)));
    dp_prev[0][0][0] = 1;
    vector<vector<vector<long long>>> dp_next(K, vector<vector<long long>>(2, vector<long long>(2, 0)));

    for(int i = 0; i < N; ++i){
        // Reset dp_next
        for(int a = 0; a < K; ++a){
            for(int lastB = 0; lastB <=1; ++lastB){
                for(int cUsed =0; cUsed <=1; ++cUsed){
                    dp_next[a][lastB][cUsed] =0;
                }
            }
        }
        // Transition
        for(int a =0; a < K; ++a){
            for(int lastB =0; lastB <=1; ++lastB){
                for(int cUsed=0; cUsed <=1; ++cUsed){
                    long long val = dp_prev[a][lastB][cUsed];
                    if(val ==0) continue;
                    // Assign to A
                    int a_new = (a +1) % K;
                    int lastB_new =0;
                    int cUsed_new = cUsed;
                    dp_next[a_new][lastB_new][cUsed_new] = (dp_next[a_new][lastB_new][cUsed_new] + val) % MOD;
                    // Assign to B
                    if(lastB ==0){
                        a_new = a;
                        lastB_new =1;
                        cUsed_new = cUsed;
                        dp_next[a_new][lastB_new][cUsed_new] = (dp_next[a_new][lastB_new][cUsed_new] + val) % MOD;
                    }
                    // Assign to C
                    a_new = a;
                    lastB_new =0;
                    cUsed_new =1;
                    dp_next[a_new][lastB_new][cUsed_new] = (dp_next[a_new][lastB_new][cUsed_new] + val) % MOD;
                }
            }
        }
        // Swap dp_prev and dp_next
        dp_prev.swap(dp_next);
    }

    long long ans =0;
    for(int lastB =0; lastB <=1; ++lastB){
        ans = (ans + dp_prev[0][lastB][1]) % MOD;
    }
    return ans;
}

// Function to compute the number of valid assignments when K == 0
long long count_assignments_K_zero(int N){
    // dp_prev[lastB][cUsed]
    // lastB: 0 or1
    // cUsed:0 or1
    vector<vector<long long>> dp_prev(2, vector<long long>(2, 0));
    dp_prev[0][0] =1;
    vector<vector<long long>> dp_next(2, vector<long long>(2, 0));

    for(int i =0; i < N; ++i){
        // Reset dp_next
        for(int lastB =0; lastB <=1; ++lastB){
            for(int cUsed=0; cUsed <=1; ++cUsed){
                dp_next[lastB][cUsed] =0;
            }
        }
        // Transition
        for(int lastB =0; lastB <=1; ++lastB){
            for(int cUsed=0; cUsed <=1; ++cUsed){
                long long val = dp_prev[lastB][cUsed];
                if(val ==0) continue;
                // Assign to B
                if(lastB ==0){
                    int lastB_new =1;
                    int cUsed_new = cUsed;
                    dp_next[lastB_new][cUsed_new] = (dp_next[lastB_new][cUsed_new] + val) % MOD;
                }
                // Assign to C
                int lastB_new =0;
                int cUsed_new =1;
                dp_next[lastB_new][cUsed_new] = (dp_next[lastB_new][cUsed_new] + val) % MOD;
            }
        }
        // Swap dp_prev and dp_next
        dp_prev.swap(dp_next);
    }

    long long ans =0;
    for(int lastB =0; lastB <=1; ++lastB){
        ans = (ans + dp_prev[lastB][1]) % MOD;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    long long ans =0;
    if(K >0){
        ans = count_assignments_K_positive(N, K);
    }
    else{
        ans = count_assignments_K_zero(N);
    }
    cout << ans;
}

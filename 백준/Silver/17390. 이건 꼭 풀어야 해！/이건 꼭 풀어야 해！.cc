#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, Q, L, R;
    cin >> N >> Q;
    vector<int> A(N);
    vector<int> S(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    sort(A.begin(), A.end());
    S[0] = A[0];
    for (int i = 1; i < N; i++)
        S[i] = S[i-1] + A[i];
    for (int i = 0; i < Q; i++) {
        cin >> L >> R;
        if (L == 1)
            cout << S[R-1] << '\n';
        else
            cout << S[R-1] - S[L-2] << '\n';
    }
    return 0;
}
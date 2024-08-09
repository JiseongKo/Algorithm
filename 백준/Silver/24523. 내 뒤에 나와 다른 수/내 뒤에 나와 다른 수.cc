#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, idx = -1;
    cin >> N;
    vector<int> A(N);
    vector<int> R(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    R[N-1] = idx;
    for (int i = N-2; i >= 0; i--) {
        if (A[i] != A[i+1])
            idx = i+2;
        R[i] = idx;
    }
    for (int i = 0; i < N; i++)
        cout << R[i] << ' ';
    return 0;
}
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, t, A = 0, s = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> t;
        A += t;
    }
    for (int i = 1; i < N; i++) {
        s += i;
    }
    cout << A - s;
    return 0;
}
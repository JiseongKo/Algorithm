#include <iostream>
using namespace std;

int main() {
    int T, N, M, a, b;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        for (int j = 0; j < M; j++)
            cin >> a >> b;
        cout << N-1 << '\n';
    }
    return 0;
}
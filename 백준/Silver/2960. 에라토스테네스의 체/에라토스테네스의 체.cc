#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<int> v(N+1, 1);
    vector<int> d;

    for (int i = 2; i < N+1; i++) {
        for (int j = i; j < N+1; j += i)
            if (v[j]) {
                d.push_back(j);
                v[j] = 0;
            }
    }

    cout << d[K-1];

    return 0;
}
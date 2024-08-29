#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    int s = 0;
    bool p;

    cin >> M >> N;

    vector<int> a;

    for (int i = M; i <= N; i++) {
        if (i == 1)
            continue;
        p = true;
        for (int j = 2; j <= sqrt(i); j++)
            if (i%j == 0) {
                p = false;
                break;
            }
        if (p)
            a.push_back(i);
    }

    if (a.empty()) {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < a.size(); i++)
        s += a[i];

    cout << s << '\n' << a[0];
    return 0;
}
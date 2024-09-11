#include <iostream>
using namespace std;

int main() {
    int N, c = 0, r = 2, add = 2;
    bool odd = false;
    cin >> N;

    while (c != N-1) {
        r += add;
        c++;
        if (odd) {
            odd = false;
            add++;
            continue;
        }
        if (add % 2 == 1) {
            odd = true;
            continue;
        }
        add++;
    }

    cout << r << endl;
    return 0;
}
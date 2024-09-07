#include <iostream>
using namespace std;

int paper[129][129];
int white = 0, blue = 0;

void check(int x, int y, int k) {
    bool cut = false;
    int fc = paper[x][y];
    for (int i = x; i < x + k; i++) {
        for (int j = y; j < y + k; j++) {
            if (paper[i][j] != fc) {
                cut = true;
                break;
            }
        }

        if (cut)
            break;
    }
    if (cut) {
        check(x, y, k / 2);
        check(x, y + k / 2, k / 2);
        check(x + k / 2, y, k / 2);
        check(x + k / 2, y + k / 2, k / 2);
    } else {
        if (fc == 0)
            white++;
        else
            blue++;
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }
    check(0, 0, N);
    cout << white << endl << blue << endl;
    return 0;
}
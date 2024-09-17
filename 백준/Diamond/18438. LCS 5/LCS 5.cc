#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> LCSLength(const string &X, int x_start, int x_end, const string &Y, int y_start, int y_end, bool reverse) {
    int x_len = x_end - x_start + 1;
    int y_len = y_end - y_start + 1;
    vector<int> curr(y_len + 1, 0);
    vector<int> prev(y_len + 1, 0);

    if (!reverse) {
        for (int i = x_start; i <= x_end; ++i) {
            for (int j = 1; j <= y_len; ++j) {
                if (X[i] == Y[y_start + j - 1]) {
                    curr[j] = prev[j - 1] + 1;
                } else {
                    curr[j] = max(curr[j - 1], prev[j]);
                }
            }
            swap(prev, curr);
        }
    } else {
        for (int i = x_end; i >= x_start; --i) {
            for (int j = 1; j <= y_len; ++j) {
                if (X[i] == Y[y_end - j + 1]) {
                    curr[j] = prev[j - 1] + 1;
                } else {
                    curr[j] = max(curr[j - 1], prev[j]);
                }
            }
            swap(prev, curr);
        }
    }
    return prev;
}

string LCS(const string &X, int x_start, int x_end, const string &Y, int y_start, int y_end) {
    if (x_start > x_end) {
        return "";
    }
    if (x_start == x_end) {
        for (int j = y_start; j <= y_end; ++j) {
            if (X[x_start] == Y[j]) {
                return string(1, X[x_start]);
            }
        }
        return "";
    }
    int x_mid = (x_start + x_end) / 2;

    vector<int> l1 = LCSLength(X, x_start, x_mid, Y, y_start, y_end, false);
    vector<int> l2 = LCSLength(X, x_mid + 1, x_end, Y, y_start, y_end, true);

    int y_len = y_end - y_start + 1;
    int max_len = -1;
    int y_split = y_start;
    for (int j = 0; j <= y_len; ++j) {
        int total = l1[j] + l2[y_len - j];
        if (total > max_len) {
            max_len = total;
            y_split = y_start + j;
        }
    }

    string left = LCS(X, x_start, x_mid, Y, y_start, y_split - 1);
    string right = LCS(X, x_mid + 1, x_end, Y, y_split, y_end);
    return left + right;
}

int main() {
    string X, Y;
    getline(cin, X);
    getline(cin, Y);

    string lcs = LCS(X, 0, X.size() - 1, Y, 0, Y.size() - 1);
    cout << lcs.size() << endl;
    cout << lcs << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> w(2*n);
    vector<int> r;
    for (int i = 0; i < 2*n; i++)
        cin >> w[i];
    sort(w.begin(), w.end());
    for (int i = 0; i < n; i++)
        r.push_back(w[i] + w[2*n-1-i]);
    sort(r.begin(), r.end());
    cout << r[0];
    return 0;
}
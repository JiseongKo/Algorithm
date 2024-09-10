#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int distSq(pair<int, int> p1, pair<int, int> p2) {
    return (p1.first - p2.first) * (p1.first - p2.first) +
           (p1.second - p2.second) * (p1.second - p2.second);
}

bool isSquare(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3, pair<int, int> p4) {
    vector<int> dists;
    dists.push_back(distSq(p1, p2));
    dists.push_back(distSq(p1, p3));
    dists.push_back(distSq(p1, p4));
    dists.push_back(distSq(p2, p3));
    dists.push_back(distSq(p2, p4));
    dists.push_back(distSq(p3, p4));

    sort(dists.begin(), dists.end());

    return (dists[0] > 0 && dists[0] == dists[1] && dists[1] == dists[2] && dists[2] == dists[3]
            && dists[4] == dists[5]);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        pair<int, int> p1, p2, p3, p4;
        cin >> p1.first >> p1.second;
        cin >> p2.first >> p2.second;
        cin >> p3.first >> p3.second;
        cin >> p4.first >> p4.second;

        if (isSquare(p1, p2, p3, p4)) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = 1e9;
int N;
vector<vector<int>> cost;
vector<int> u, v, p, way;

int main() {
    cin >> N;
    cost.assign(N + 1, vector<int>(N + 1));
    u.assign(N + 1, 0);
    v.assign(N + 1, 0);
    p.assign(N + 1, 0);
    way.assign(N + 1, 0);
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> cost[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        vector<int> minv(N + 1, INF);
        vector<bool> used(N + 1, false);
        int j0 = 0;
        p[0] = i;

        do {
            used[j0] = true;
            int i0 = p[j0], delta = INF, j1;
            for (int j = 1; j <= N; j++) {
                if (!used[j]) {
                    int cur = cost[i0][j] - u[i0] - v[j];
                    if (cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if (minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }

            for (int j = 0; j <= N; j++) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    minv[j] -= delta;
                }
            }
            j0 = j1;
        } while (p[j0] != 0);

        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }

    cout << -v[0] << endl;

    return 0;
}

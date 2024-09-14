#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int selectCandidates(vector<pair<int, int > >& applicants, int N) {
    sort(applicants.begin(), applicants.end());

    int selected = 0;
    int bestInterviewRank = N + 1;

    for (int i = 0; i < N; ++i) {
        if (applicants[i].second < bestInterviewRank) {
            selected++;
            bestInterviewRank = applicants[i].second;
        }
    }

    return selected;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<pair<int, int > > applicants(N);

        for (int i = 0; i < N; ++i) {
            cin >> applicants[i].first >> applicants[i].second;
        }

        cout << selectCandidates(applicants, N) << endl;
    }

    return 0;
}
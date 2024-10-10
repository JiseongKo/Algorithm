#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct Interval {
    int start, end, index;
};

bool compareByEnd(const Interval &a, const Interval &b) {
    return a.end < b.end;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Interval> rowIntervals(n);
    vector<Interval> colIntervals(n);
    for (int i = 0; i < n; ++i) {
        int ai, bi, ci, di;
        cin >> ai >> bi >> ci >> di;
        rowIntervals[i] = {ai, ci, i};
        colIntervals[i] = {bi, di, i};
    }

    // Assign rows
    sort(rowIntervals.begin(), rowIntervals.end(), compareByEnd);
    set<int> availableRows;
    for (int i = 1; i <= n; ++i) {
        availableRows.insert(i);
    }
    vector<int> assignedRows(n);
    for (const auto &interval : rowIntervals) {
        auto it = availableRows.lower_bound(interval.start);
        if (it == availableRows.end() || *it > interval.end) {
            cout << "NIE\n";
            return 0;
        }
        assignedRows[interval.index] = *it;
        availableRows.erase(it);
    }

    // Assign columns
    sort(colIntervals.begin(), colIntervals.end(), compareByEnd);
    set<int> availableCols;
    for (int i = 1; i <= n; ++i) {
        availableCols.insert(i);
    }
    vector<int> assignedCols(n);
    for (const auto &interval : colIntervals) {
        auto it = availableCols.lower_bound(interval.start);
        if (it == availableCols.end() || *it > interval.end) {
            cout << "NIE\n";
            return 0;
        }
        assignedCols[interval.index] = *it;
        availableCols.erase(it);
    }

    // Output the positions in the order of input
    for (int i = 0; i < n; ++i) {
        cout << assignedRows[i] << " " << assignedCols[i] << "\n";
    }

    return 0;
}

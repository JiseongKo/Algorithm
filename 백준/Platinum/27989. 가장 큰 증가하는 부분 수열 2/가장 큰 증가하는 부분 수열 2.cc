#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef int64_t ll;

struct SegmentTree {
    int size;
    vector<ll> tree;

    SegmentTree(int n) {
        size = n;
        tree.resize(4 * n + 4, 0); // Initialize with zeros
    }

    void update(int node, int node_left, int node_right, int idx, ll value) {
        if (idx < node_left || idx > node_right) {
            return; // Out of range
        }
        if (node_left == node_right) {
            tree[node] = max(tree[node], value);
            return;
        }
        int mid = (node_left + node_right) / 2;
        update(2 * node, node_left, mid, idx, value);
        update(2 * node + 1, mid + 1, node_right, idx, value);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    ll query(int node, int node_left, int node_right, int l, int r) {
        if (node_right < l || node_left > r) {
            return 0; // Return minimum value
        }
        if (l <= node_left && node_right <= r) {
            return tree[node];
        }
        int mid = (node_left + node_right) / 2;
        ll left_max = query(2 * node, node_left, mid, l, r);
        ll right_max = query(2 * node + 1, mid + 1, node_right, l, r);
        return max(left_max, right_max);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> unique_A;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        unique_A.push_back(A[i]);
    }

    // Coordinate compression
    sort(unique_A.begin(), unique_A.end());
    unique_A.erase(unique(unique_A.begin(), unique_A.end()), unique_A.end());
    map<ll, int> rank_map;
    for (int i = 0; i < unique_A.size(); ++i) {
        rank_map[unique_A[i]] = i + 1; // Ranks start from 1
    }

    int M = unique_A.size(); // Number of unique elements
    SegmentTree seg_tree(M);

    ll result = 0;
    for (int i = 0; i < N; ++i) {
        int rank_i = rank_map[A[i]];
        ll max_dp = 0;
        if (rank_i > 1) {
            max_dp = seg_tree.query(1, 1, M, 1, rank_i - 1);
        }
        ll DP_i = max_dp + A[i];
        seg_tree.update(1, 1, M, rank_i, DP_i);
        result = max(result, DP_i);
    }

    cout << result << '\n';
    return 0;
}

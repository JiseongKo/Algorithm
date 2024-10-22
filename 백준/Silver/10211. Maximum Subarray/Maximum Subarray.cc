#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMaxSubarraySum(const vector<int>& arr) {
    int max_sum = arr[0];
    int current_sum = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        current_sum = max(arr[i], current_sum + arr[i]);
        max_sum = max(max_sum, current_sum);
    }
    return max_sum;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> X(N);
        for (int i = 0; i < N; i++) {
            cin >> X[i];
        }
        cout << findMaxSubarraySum(X) << endl;
    }
    return 0;
}

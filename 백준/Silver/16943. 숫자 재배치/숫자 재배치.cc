#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string A;
    int B;
    cin >> A >> B;

    // B보다 작은 수를 구해야 하므로 내림차순으로 정렬
    sort(A.begin(), A.end(), greater<char>());

    int maxC = -1;

    do {
        // 순열을 정수로 변환
        if (A[0] != '0') {
            int C = stoi(A);
            if (C < B) {
                maxC = max(maxC, C);
            }
        }
    } while (prev_permutation(A.begin(), A.end()));

    cout << maxC << endl;

    return 0;
}

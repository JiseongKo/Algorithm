#include <iostream>
using namespace std;

int main() {
    unsigned long long S;
    cin >> S;

    unsigned long long sum = 0;
    int N = 0;
    for (int i = 1; sum + i <= S; i++) {
        sum += i;
        N = i;
    }

    cout << N << endl;
    return 0;
}
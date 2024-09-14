#include <iostream>

using namespace std;

int main() {
    long long N;
    cin >> N;

    long long A = N / 3;
    long long Rest = N - A;
    long long B = Rest / 2;
    long long C = Rest - B;

    long long I = A * (B + C) + B * C;
    long long R = N + 1 + I;

    cout << R << endl;

    return 0;
}

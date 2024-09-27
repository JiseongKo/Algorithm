#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;
    
    const int MOD = 1234567;
    long long result = 0;
    long long length = 1;
    long long start = 1;
    
    while (start <= N) {
        long long end = start * 10 - 1;
        if (end > N) end = N;
        result += (end - start + 1) * length;
        result %= MOD;
        length++;
        start *= 10;
    }
    
    cout << result % MOD << endl;
    return 0;
}

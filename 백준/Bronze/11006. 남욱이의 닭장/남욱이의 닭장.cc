#include <iostream>
using namespace std;

int main()
{
    int T, N, M;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> N >> M;
        cout << 2*M-N << ' ' << N-M << endl;
    }
}
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    string S;

    cin >> N >> K;
    cin >> S;
    
    if (K > (N >> 1))
    {
        K = (N >> 1);
    }
    
    int x = 0, y = 0;

    for (int i = 0; i < K; i++)
    {
        for (char c : S)
        {
            if (c == 'U')
                y++;
            else if (c == 'D')
                y--;
            else if (c == 'R')
                x++;
            else if (c == 'L')
                x--;

            if (x == 0 && y == 0)
            {
                cout << "YES" << '\n';
                return 0;
            }
        }
    }

    cout << "NO" << '\n';
    return 0;
}
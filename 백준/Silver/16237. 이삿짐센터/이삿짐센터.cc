#include <iostream>
using namespace std;

int main()
{
    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;

    int baskets = E + D;
    A -= D;

    while (C > 0)
    {
        if (B > 0)
        {
            B--;
            C--;
        }
        else if (A > 0)
        {
            A -= 2;
            C--;
        }
        else
        {
            C--;
        }

        baskets++;
    }

    while (B > 0)
    {
        if (B > 1 && A > 0)
        {
            B -= 2;
            A--;
        }
        else if (B > 0 && A > 0)
        {
            B--;
            A -= 3;
        }
        else
        {
            B -= 2;
        }

        baskets++;
    }

    while (A > 0)
    {
        A -= 5;
        baskets++;
    }

    cout << baskets << endl;

    return 0;
}
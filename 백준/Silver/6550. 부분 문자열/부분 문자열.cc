#include <iostream>
#include <string>

using namespace std;

bool isSubsequence(const string &s, const string &t)
{
    int s_len = s.length();
    int t_len = t.length();

    int i = 0, j = 0;

    while (i < s_len && j < t_len)
    {
        if (s[i] == t[j])
        {
            i++;
        }
        j++;
    }

    return i == s_len;
}

int main()
{
    string s, t;
    while (cin >> s >> t)
    {
        if (isSubsequence(s, t))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}

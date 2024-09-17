#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    string result = "";
    int n = s.size();
    int i = 0;
    bool possible = true;

    while (i < n) {
        if (s[i] == '.') {
            result += '.';
            i++;
        } else {
            int start = i;
            while (i < n && s[i] == 'X') i++;
            int len = i - start;
            
            if (len % 2 != 0) {
                possible = false;
                break;
            }
            
            int count_A = len / 4;
            int count_B = (len % 4) / 2;
            
            for (int j = 0; j < count_A; j++) result += "AAAA";

            for (int j = 0; j < count_B; j++) result += "BB";
        }
    }

    if (possible) {
        cout << result;
    } else {
        cout << "-1";
    }
    
    return 0;
}
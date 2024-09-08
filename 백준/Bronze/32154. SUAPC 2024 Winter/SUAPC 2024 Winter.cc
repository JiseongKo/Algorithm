#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    if (N == 1)
        cout << 11 << endl << 'A' << ' ' << 'B' << ' ' << 'C' << ' ' << 'D' << ' ' << 'E' << ' ' << 'F' << ' ' << 'G' << ' ' << 'H' << ' ' << 'J' << ' ' << 'L' << ' ' << 'M' << endl;
    else if (N == 2 || N == 3)
        cout << 9 << endl << 'A' << ' ' << 'C' << ' ' << 'E' << ' ' << 'F' << ' ' << 'G' << ' ' << 'H' << ' ' << 'I' << ' ' << 'L' << ' ' << 'M' << endl;
    else if (N == 4)
        cout << 9 << endl << 'A' << ' ' << 'B' << ' ' << 'C' << ' ' << 'E' << ' ' << 'F' << ' ' << 'G' << ' ' << 'H' << ' ' << 'L' << ' ' << 'M' << endl;
    else if (N == 5 || N == 6 || N == 7 || N == 8 || N == 9)
        cout << 8 << endl << 'A' << ' ' << 'C' << ' ' << 'E' << ' ' << 'F' << ' ' << 'G' << ' ' << 'H' << ' ' << 'L' << ' ' << 'M' << endl;
    else
        cout << 8 << endl << 'A' << ' ' << 'B' << ' ' << 'C' << ' ' << 'F' << ' ' << 'G' << ' ' << 'H' << ' ' << 'L' << ' ' << 'M' << endl;
    return 0;
}
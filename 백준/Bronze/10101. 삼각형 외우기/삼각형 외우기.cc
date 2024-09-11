#include <iostream>
using namespace std;

int main()
{
    int angle1, angle2, angle3;
    cin >> angle1 >> angle2 >> angle3;

    if (angle1 + angle2 + angle3 != 180)
    {
        cout << "Error" << endl;
    }
    else if (angle1 == angle2 && angle2 == angle3)
    {
        cout << "Equilateral" << endl;
    }
    else if (angle1 != angle2 && angle2 != angle3 && angle3 != angle1)
    {
        cout << "Scalene" << endl;
    }
    else
    {
        cout << "Isosceles" << endl;
    }

    return 0;
}
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    int N, R;
    int maxX = -100, maxY = -100;
    int minX = 100, minY = 100;

    cin >> N >> R;

    vector<int> x(N);
    vector<int> y(N);

    int count;
    int maxCount = 0;
    int resultX, resultY;

    for (int i = 0; i < N; i++)
    {
        cin >> x[i] >> y[i];
        if (x[i] > maxX)
            maxX = x[i];
        if (x[i] < minX)
            minX = x[i];
        if (y[i] > maxY)
            maxY = y[i];
        if (y[i] < minY)
            minY = y[i];
    }

    for (int i = minX; i <= maxX; i++)
    {
        for (int j = minY; j <= maxY; j++)
        {
            count = 0;
            for (int k = 0; k < N; k++)
            {
                if (pow(i - x[k], 2) + pow(j - y[k], 2) <= R * R)
                {
                    count++;
                }
            }
            if (count > maxCount)
            {
                maxCount = count;
                resultX = i;
                resultY = j;
            }
        }
    }

    cout << resultX << " " << resultY << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long get_minimum_distance(vector<int>& points) {
    sort(points.begin(), points.end());
    
    int median = points[points.size() / 2];
    
    long long total_distance = 0;
    for (int point : points) {
        total_distance += abs(point - median);
    }
    
    return total_distance;
}

int main() {
    int n;
    cin >> n;

    vector<int> x_points(n), y_points(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> x_points[i] >> y_points[i];
    }
    
    long long x_min_distance = get_minimum_distance(x_points);
    long long y_min_distance = get_minimum_distance(y_points);
    
    cout << x_min_distance + y_min_distance << endl;
    
    return 0;
}

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Info {
    string name;
    int kor;
    int eng;
    int math;
};

bool condition (Info a, Info b) {
    if (a.kor == b.kor && a.eng == b.eng && a.math == b.math)
        return a.name < b.name;
    else if (a.kor == b.kor && a.eng == b.eng)
        return a.math > b.math;
    else if (a.kor == b.kor)
        return a.eng < b.eng;
    else
        return a.kor > b.kor;
}

int main() {
    int N;
    cin >> N;
    vector<Info> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;

    sort(v.begin(), v.end(), condition);

    for (int i = 0; i < N; i++)
        cout << v[i].name << '\n';

    return 0;
}
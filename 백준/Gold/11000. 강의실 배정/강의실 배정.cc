#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Class {
    int start, end;
};

bool compare(const Class& a, const Class& b) {
    return a.start < b.start;
}

int main() {
    int N;
    cin >> N;
    vector<Class> classes(N);

    for (int i = 0; i < N; i++) {
        cin >> classes[i].start >> classes[i].end;
    }
    
    sort(classes.begin(), classes.end(), compare);
    priority_queue<int, vector<int>, greater<int> > pq;
    pq.push(classes[0].end);

    for (int i = 1; i < N; i++) {
        if (pq.top() <= classes[i].start) {
            pq.pop();
        }
        pq.push(classes[i].end);
    }

    cout << pq.size() << endl;
    return 0;
}
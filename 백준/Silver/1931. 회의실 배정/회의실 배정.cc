#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 회의 정보를 저장할 구조체
struct Meeting {
    int start;
    int end;
};

// 회의를 정렬하기 위한 비교 함수
bool compare(Meeting a, Meeting b) {
    if (a.end == b.end) {
        return a.start < b.start;
    }
    return a.end < b.end;
}

int main() {
    int N;
    cin >> N;
    vector<Meeting> meetings(N);

    // 회의 정보 입력
    for (int i = 0; i < N; ++i) {
        cin >> meetings[i].start >> meetings[i].end;
    }

    // 회의 정렬
    sort(meetings.begin(), meetings.end(), compare);

    // 그리디 알고리즘을 사용하여 최대 회의 개수 찾기
    int count = 0;
    int last_end_time = 0;

    for (int i = 0; i < N; ++i) {
        if (meetings[i].start >= last_end_time) {
            last_end_time = meetings[i].end;
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
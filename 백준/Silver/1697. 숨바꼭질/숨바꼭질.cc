#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int find_fastest_time(int N, int K) {
    vector<bool> visited(100001, false);
    queue<pair<int, int> > q;
    q.push(make_pair(N, 0));
    visited[N] = true;

    while (!q.empty()) {
        int current_position = q.front().first;
        int current_time = q.front().second;
        q.pop();

        if (current_position == K) {
            return current_time;
        }

        int next_positions[3] = {current_position - 1, current_position + 1, current_position * 2};

        for (int i = 0; i < 3; i++) {
            int next_position = next_positions[i];
            if (next_position >= 0 && next_position <= 100000 && !visited[next_position]) {
                visited[next_position] = true;
                q.push(make_pair(next_position, current_time + 1));
            }
        }
    }
    return -1;
}

int main() {
    int N, K;
    cin >> N >> K;
    int result = find_fastest_time(N, K);
    cout << result << endl;
    return 0;
}
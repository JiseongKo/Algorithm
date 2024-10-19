#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    int q;
    cin >> q;

    unordered_map<string, int> in_count;
    unordered_map<string, int> overtime;
    int total_overtime = 0;

    for (int i = 0; i < q; i++) {
        string name, action;
        cin >> name >> action;

        if (action == "+") {
            in_count[name]++;
        } else if (action == "-") {
            if (in_count[name] > 0) {
                in_count[name]--;
            } else {
                overtime[name]++;
                total_overtime++;
            }
        }
    }

    for (const auto& entry : in_count) {
        total_overtime += entry.second;
    }

    cout << total_overtime << endl;

    return 0;
}
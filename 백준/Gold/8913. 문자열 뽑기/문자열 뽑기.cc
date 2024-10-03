#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

typedef vector<pair<char, int>> GroupSequence;

struct VectorHash {
    size_t operator()(const GroupSequence &groups) const {
        size_t hash = 0;
        for (const auto &p : groups) {
            hash ^= hash * 31 + p.first;
            hash ^= hash * 31 + p.second;
        }
        return hash;
    }
};

bool canReduceToEmpty(GroupSequence groups, unordered_map<GroupSequence, bool, VectorHash> &memo) {
    if (groups.empty()) return true;
    if (memo.count(groups)) return memo[groups];

    for (size_t i = 0; i < groups.size(); ++i) {
        if (groups[i].second >= 2) {
            // Remove group at position i
            GroupSequence newGroups;
            // Left part
            for (size_t j = 0; j < i; ++j) {
                newGroups.push_back(groups[j]);
            }
            // Merge if necessary
            if (i > 0 && i + 1 < groups.size() && groups[i - 1].first == groups[i + 1].first) {
                // Merge groups[i - 1] and groups[i + 1]
                newGroups.back().second += groups[i + 1].second;
                for (size_t j = i + 2; j < groups.size(); ++j) {
                    newGroups.push_back(groups[j]);
                }
            } else {
                // No merge
                if (i + 1 < groups.size()) {
                    for (size_t j = i + 1; j < groups.size(); ++j) {
                        newGroups.push_back(groups[j]);
                    }
                }
            }
            if (canReduceToEmpty(newGroups, memo)) {
                memo[groups] = true;
                return true;
            }
        }
    }
    memo[groups] = false;
    return false;
}

GroupSequence createGroupSequence(const string &s) {
    GroupSequence groups;
    if (s.empty()) return groups;
    char currentChar = s[0];
    int length = 1;
    for (size_t i = 1; i < s.size(); ++i) {
        if (s[i] == currentChar) {
            ++length;
        } else {
            groups.emplace_back(currentChar, length);
            currentChar = s[i];
            length = 1;
        }
    }
    groups.emplace_back(currentChar, length);
    return groups;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        unordered_map<GroupSequence, bool, VectorHash> memo;
        GroupSequence groups = createGroupSequence(s);
        bool result = canReduceToEmpty(groups, memo);
        cout << (result ? "1" : "0") << endl;
    }
    return 0;
}

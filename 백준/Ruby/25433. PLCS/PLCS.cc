#include <bits/stdc++.h>
using namespace std;

// Function to generate sieve of Eratosthenes up to max_limit
vector<bool> sieve_of_eratosthenes(int max_limit) {
    vector<bool> is_prime(max_limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for(int p=2; p*p <= max_limit; p++) {
        if(is_prime[p]) {
            for(int multiple = p*p; multiple <= max_limit; multiple += p) {
                is_prime[multiple] = false;
            }
        }
    }
    return is_prime;
}

// Function to compute LCS length using Hunt-Szymanski algorithm
int lcs_length(const string& a, const string& b) {
    // Preprocess b: for each character, store the list of indices where it appears
    vector<vector<int>> char_positions(26, vector<int>());
    for(int k=0; k < b.size(); k++) {
        char_positions[b[k] - 'a'].push_back(k);
    }

    // Vector to store the end positions of LCS of different lengths
    vector<int> dp;

    // Iterate through each character in a
    for(char c : a) {
        // Get the list of positions in b where character c appears
        const vector<int>& positions = char_positions[c - 'a'];
        // Iterate through the positions in reverse order
        for(auto it = positions.rbegin(); it != positions.rend(); it++) {
            int pos = *it;
            // Binary search to find the insertion point
            int idx = lower_bound(dp.begin(), dp.end(), pos) - dp.begin();
            if(idx == dp.size()) {
                dp.push_back(pos);
            }
            else {
                dp[idx] = pos;
            }
        }
    }

    return dp.size();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string A, B, X_str, Y_str;
    cin >> A >> B;
    cin >> X_str >> Y_str;
    char X = X_str[0];
    char Y = Y_str[0];

    // Find the position of X in A and B
    int pos_A = -1, pos_B = -1;
    for(int i=0; i < A.size(); i++) {
        if(A[i] == X){
            pos_A = i;
            break;
        }
    }
    for(int i=0; i < B.size(); i++) {
        if(B[i] == X){
            pos_B = i;
            break;
        }
    }

    // If X is not found in either string, though problem states it's present exactly once
    if(pos_A == -1 || pos_B == -1){
        cout << "-1";
        return 0;
    }

    // Extract and clean prefix and suffix for A
    string A_prefix = A.substr(0, pos_A);
    A_prefix.erase(remove(A_prefix.begin(), A_prefix.end(), Y), A_prefix.end());

    string A_suffix = "";
    if(pos_A +1 < A.size()){
        A_suffix = A.substr(pos_A +1);
        A_suffix.erase(remove(A_suffix.begin(), A_suffix.end(), Y), A_suffix.end());
    }

    // Extract and clean prefix and suffix for B
    string B_prefix = B.substr(0, pos_B);
    B_prefix.erase(remove(B_prefix.begin(), B_prefix.end(), Y), B_prefix.end());

    string B_suffix = "";
    if(pos_B +1 < B.size()){
        B_suffix = B.substr(pos_B +1);
        B_suffix.erase(remove(B_suffix.begin(), B_suffix.end(), Y), B_suffix.end());
    }

    // Compute LCS lengths
    int lcs_prefix = lcs_length(A_prefix, B_prefix);
    int lcs_suffix = lcs_length(A_suffix, B_suffix);

    // Total sum
    int total_sum = lcs_prefix + lcs_suffix + 1;

    // Generate sieve up to 100001
    vector<bool> is_prime = sieve_of_eratosthenes(100001);

    // Find the maximum prime <= total_sum
    int answer = -1;
    if(total_sum >=2){
        for(int p = total_sum; p >=2; p--){
            if(is_prime[p]){
                answer = p;
                break;
            }
        }
    }

    cout << answer;
}

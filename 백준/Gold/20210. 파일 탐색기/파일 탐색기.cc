#include <bits/stdc++.h>
using namespace std;

// Comparator function for natural sort
bool natural_compare(const string& a, const string& b) {
    int i = 0, j = 0;
    int len_a = a.size(), len_b = b.size();

    while (i < len_a && j < len_b) {
        bool is_digit_a = isdigit(a[i]);
        bool is_digit_b = isdigit(b[j]);

        if (is_digit_a && is_digit_b) {
            // Extract full digit blocks
            int start_i = i;
            while (i < len_a && isdigit(a[i])) i++;
            string num_a = a.substr(start_i, i - start_i);

            int start_j = j;
            while (j < len_b && isdigit(b[j])) j++;
            string num_b = b.substr(start_j, j - start_j);

            // Remove leading zeros for numerical comparison
            int first_a = 0;
            while (first_a < num_a.size() && num_a[first_a] == '0') first_a++;
            int first_b = 0;
            while (first_b < num_b.size() && num_b[first_b] == '0') first_b++;

            string trimmed_a = (first_a < num_a.size()) ? num_a.substr(first_a) : "0";
            string trimmed_b = (first_b < num_b.size()) ? num_b.substr(first_b) : "0";

            // Compare numerical values by length
            if (trimmed_a.size() != trimmed_b.size())
                return trimmed_a.size() < trimmed_b.size();

            // If lengths are equal, compare lexicographically
            if (trimmed_a != trimmed_b)
                return trimmed_a < trimmed_b;

            // If numerical values are equal, compare number of leading zeros
            int zeros_a = first_a;
            int zeros_b = first_b;
            if (zeros_a != zeros_b)
                return zeros_a < zeros_b;

            // If both numerical value and leading zeros are equal, continue
        }
        else if (is_digit_a && !is_digit_b) {
            // Digits come before letters
            return true;
        }
        else if (!is_digit_a && is_digit_b) {
            // Letters come after digits
            return false;
        }
        else {
            // Both are letters
            char char_a = a[i++];
            char char_b = b[j++];

            char lower_a = tolower(char_a);
            char lower_b = tolower(char_b);

            if (lower_a != lower_b)
                return lower_a < lower_b;

            // If same letter ignoring case, uppercase comes first
            if (isupper(char_a) != isupper(char_b))
                return isupper(char_a);
            
            // If same case and same letter, continue
        }
    }

    // If one string is exhausted, the shorter string comes first
    return a.size() < b.size();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<string> strings(N);
    for(auto &s: strings) cin >> s;
    
    sort(strings.begin(), strings.end(), natural_compare);
    
    for(const auto &s: strings) cout << s << '\n';
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Fast exponentiation to compute (base^exp) % mod
ll fast_pow_mod(ll base, ll exp, ll mod_val){
    ll res = 1;
    base %= mod_val;
    while(exp >0){
        if(exp &1){
            res = (__int128(res) * base) % mod_val;
        }
        base = (__int128(base) * base) % mod_val;
        exp >>=1;
    }
    return res;
}

// List of odd primes
vector<int> primes = {3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

// Variables to keep track of the best solution
double minimal_log_x = 1e18;
vector<int> best_exponents;

// Recursive function to find the exponents list that minimizes log(x)
void search(int prime_idx, int max_e_plus1, ll n_remaining, double current_log_x, vector<int> &current_exponents){
    if(n_remaining ==1){
        if(current_log_x < minimal_log_x){
            minimal_log_x = current_log_x;
            best_exponents = current_exponents;
        }
        return;
    }
    if(prime_idx >= primes.size()){
        return;
    }
    for(int e_plus1=2; e_plus1 <= min((int)n_remaining, max_e_plus1); e_plus1++){
        if(n_remaining % e_plus1 !=0){
            continue;
        }
        int e = e_plus1 -1;
        double p_log = log((double)primes[prime_idx]);
        double new_log_x = current_log_x + e * p_log;
        if(new_log_x >= minimal_log_x){
            continue;
        }
        current_exponents.push_back(e_plus1);
        search(prime_idx +1, e_plus1, n_remaining / e_plus1, new_log_x, current_exponents);
        current_exponents.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    if(n ==1){
        cout <<1;
        return 0;
    }
    vector<int> current_exponents;
    search(0, n, n, 0.0, current_exponents);
    // Now, best_exponents contains the list of (e_i +1)
    // Compute x mod MOD
    const ll MOD = 1000000009;
    ll result =1;
    for(int i=0; i < best_exponents.size(); i++){
        if(i >= primes.size()){
            // If more exponents than primes, assign to the next primes as needed
            // This should not happen for n <=1e5 with the given primes
            break;
        }
        int e_plus1 = best_exponents[i];
        int e = e_plus1 -1;
        result = (__int128(result) * fast_pow_mod(primes[i], e, MOD)) % MOD;
    }
    cout << result;
}

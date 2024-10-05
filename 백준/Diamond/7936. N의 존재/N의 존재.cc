#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Fast exponentiation
ll powmod(ll a, ll b, ll mod){
    ll res =1;
    a %= mod;
    while(b >0){
        if(b &1){
            res = (__int128(res) * a) % mod;
        }
        a = (__int128(a) * a) % mod;
        b >>=1;
    }
    return res;
}

// BSGS algorithm to find y such that x^y ≡ b mod p
ll BSGS(ll x, ll b, ll p){
    if(b ==1 && x ==1){
        return 0;
    }
    if(x ==0){
        if(b ==0){
            return 1;
        }
        else{
            return -1;
        }
    }
    ll m = ceil(sqrt((double)(p-1)));
    // Baby steps
    vector<pair<ll, ll>> baby;
    ll current =1;
    for(ll j=0; j<m; j++){
        baby.emplace_back(current, j);
        current = (__int128(current) * x) % p;
    }
    // Sort baby steps by value
    sort(baby.begin(), baby.end(), [&](const pair<ll, ll> &a, const pair<ll, ll> &b) -> bool{
        return a.first < b.first;
    });
    // Compute x^{-m} mod p
    ll inv_x = powmod(x, p-2, p);
    ll factor = powmod(inv_x, m, p);
    // Giant steps
    ll giant = b;
    for(ll i=0; i<m; i++){
        // Binary search for giant in baby
        int l=0, r=baby.size()-1;
        while(l <=r){
            int mid = l + (r - l) /2;
            if(baby[mid].first == giant){
                return i * m + baby[mid].second;
            }
            else if(baby[mid].first < giant){
                l = mid +1;
            }
            else{
                r = mid -1;
            }
        }
        giant = (__int128(giant) * factor) % p;
    }
    return -1;
}

// Function to convert a number to string
string to_string_z(ll z){
    string s = "";
    if(z ==0){
        return "0";
    }
    while(z >0){
        s += '0' + (z %10);
        z /=10;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int d;
    cin >> d;
    while(d--){
        ll p, a, m;
        cin >> p >> a >> m;
        if(a ==0){
            // Any n divisible by p
            string s = to_string_z(p);
            cout << "TAK " << s << "\n";
            continue;
        }
        bool found = false;
        // Check x=1
        if(a ==2 % p){
            // n=1 is a solution
            cout << "TAK 1\n";
            continue;
        }
        // Iterate x from2 to min(p-1,1e5)
        ll limit = min(p-1, (ll)100000);
        for(ll x=2; x<=limit; x++){
            // Compute x^m mod p
            ll xm = powmod(x, m, p);
            // Compute b = a -x^m mod p
            ll b = (a - xm) % p;
            if(b <0) b += p;
            if(b ==0){
                continue;
            }
            // Compute discrete log y such that x^y ≡b mod p
            ll y = BSGS(x, b, p);
            if(y !=-1 && y < p-1){
                // Solve n ≡x mod p and n ≡y mod (p-1)
                // n =x +k*p
                // y =n mod (p-1)
                // Thus, y ≡x +k*p mod (p-1)
                // Since p and p-1 are coprime, p ≡1 mod (p-1)
                // Thus, y ≡x +k mod (p-1)
                // So, k ≡ y -x mod (p-1)
                ll k = (y - (x % (p-1)) + (p-1)) % (p-1);
                ll n = x + k * p;
                // Convert n to string
                string s = to_string_z(n);
                cout << "TAK " << s << "\n";
                found = true;
                break;
            }
        }
        if(found){
            continue;
        }
        // After x iteration, check if a==0 was already handled
        // Else, output "NIE"
        cout << "NIE\n";
    }
}

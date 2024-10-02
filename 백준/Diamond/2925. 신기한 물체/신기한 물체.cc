#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Function to compute floor_sum
ll floor_sum_func(ll n, ll m, ll a, ll b){
    ll res = 0;
    while (n > 0){
        if (a >= m){
            res += (n-1)*n/2 * (a / m);
            a %= m;
        }
        if (b >= m){
            res += n * (b / m);
            b %= m;
        }
        ll y_max = a * n + b;
        if (y_max < m)
            break;
        n = y_max / m;
        b = y_max % m;
        swap(m, a);
    }
    return res;
}

// Function to compute sum_mod
ll sum_mod(ll A, ll B, ll m){
    if(m ==0) return 0;
    ll g = gcd(A, B);
    ll c = B / g;
    ll sum_cycles = g * c * (c -1) / 2;
    ll q = m / c;
    ll r = m % c;
    ll sum = q * sum_cycles;
    if(r >0){
        // sum_{k=0}^{r-1} (A*k mod B) = A * r * (r-1)/2 - B * floor_sum(r, B, A, 0)
        ll floor_sum_val = floor_sum_func(r, B, A, 0);
        ll sum_remainder = A * r * (r -1) / 2 - B * floor_sum_val;
        sum += sum_remainder;
    }
    return sum;
}

struct Interval {
    ll end;
    bool assigned;
    ll L_update;
    ll A;
    ll B;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll N, Q;
    cin >> N >> Q;
    // Initialize intervals with [1, N] with no assignment
    map<ll, Interval> intervals;
    intervals[1] = Interval{N, false, 0, 0, 0};
    // Function to split at position x
    auto split = [&](ll x) -> void{
        if(x > N) return;
        auto it = intervals.upper_bound(x);
        if(it == intervals.begin()) return;
        --it;
        ll start = it->first;
        ll end = it->second.end;
        if(start == x) return;
        if(end < x) return;
        // Split into [start, x-1] and [x, end]
        Interval info = it->second;
        it->second.end = x -1;
        intervals[x] = info;
    };
    while(Q--){
        int type;
        cin >> type;
        if(type ==1){
            ll L, R, A, B;
            cin >> L >> R >> A >> B;
            // Assign [L, R] with (L_update = L, A, B)
            split(L);
            split(R+1);
            // Erase intervals in [L, R]
            auto it_start = intervals.lower_bound(L);
            auto it_end = intervals.lower_bound(R+1);
            intervals.erase(it_start, it_end);
            // Insert [L, R]
            intervals[L] = Interval{R, true, L, A, B};
        }
        else{
            ll L, R;
            cin >> L >> R;
            // Query sum from L to R
            split(L);
            split(R+1);
            ll total =0;
            auto it = intervals.lower_bound(L);
            while(it != intervals.end() && it->first <= R){
                ll U = it->first;
                ll V = it->second.end;
                if(it->second.assigned){
                    ll L_update = it->second.L_update;
                    ll A = it->second.A;
                    ll B = it->second.B;
                    ll x1 = max(U, L);
                    ll x2 = min(V, R);
                    ll k_start = x1 - L_update +1;
                    ll k_end = x2 - L_update +1;
                    // sum from k_start to k_end: sum_mod(A,B,k_end+1) - sum_mod(A,B,k_start)
                    ll sum1 = sum_mod(A, B, k_end +1);
                    ll sum2 = sum_mod(A, B, k_start);
                    total += (sum1 - sum2);
                }
                // else, no assignment, add 0
                it++;
            }
            cout << total << "\n";
        }
    }
}

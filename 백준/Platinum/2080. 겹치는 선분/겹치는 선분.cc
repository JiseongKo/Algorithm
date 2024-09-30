#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Function to compute gcd of three numbers
ll gcd3(ll a, ll b, ll c){
    return gcd(gcd(abs(a), abs(b)), abs(c));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    struct Segment {
        ll A, B, C;
        bool vertical;
        ll l, r;
    };
    vector<Segment> segments;
    segments.reserve(N);
    for(int i=0;i<N;i++){
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll A = y2 - y1;
        ll B = -(x2 - x1);
        ll C = (x2 - x1)*y1 - (y2 - y1)*x1;
        // Normalize A, B, C
        ll g = gcd3(A, B, C);
        A /= g;
        B /= g;
        C /= g;
        // Ensure A >=0, or if A==0, B >=0
        if(A < 0 || (A == 0 && B < 0)){
            A = -A;
            B = -B;
            C = -C;
        }
        // Determine if vertical
        bool vertical = (B == 0);
        // Determine projection axis and l, r
        ll l, r;
        if(!vertical){
            // Use x-axis
            l = min(x1, x2);
            r = max(x1, x2);
        }
        else{
            // Use y-axis
            l = min(y1, y2);
            r = max(y1, y2);
        }
        segments.push_back(Segment{A, B, C, vertical, l, r});
    }
    // Sort segments by (A, B, C)
    sort(segments.begin(), segments.end(), [&](const Segment &a, const Segment &b) -> bool{
        if(a.A != b.A) return a.A < b.A;
        if(a.B != b.B) return a.B < b.B;
        return a.C < b.C;
    });
    // Now group segments by (A, B, C) and process each group
    ll total_overlaps = 0;
    int i=0;
    while(i < N){
        int j = i+1;
        while(j < N && segments[j].A == segments[i].A && segments[j].B == segments[i].B && segments[j].C == segments[i].C){
            j++;
        }
        int group_size = j - i;
        if(group_size >=2){
            // Collect l and r
            vector<pair<ll, ll>> lr;
            lr.reserve(group_size);
            for(int k=i; k<j; k++) {
                lr.emplace_back(make_pair(segments[k].l, segments[k].r));
            }
            // Sort by l
            sort(lr.begin(), lr.end(), [&](const pair<ll, ll> &a, const pair<ll, ll> &b) -> bool{
                if(a.first != b.first) return a.first < b.first;
                return a.second < b.second;
            });
            // Sort r's
            vector<ll> rs;
            rs.reserve(group_size);
            for(auto &[a,b] : lr){
                rs.push_back(b);
            }
            sort(rs.begin(), rs.end());
            // Sweep line
            ll overlapping =0;
            int ptr =0;
            int active =0;
            for(int k=0; k<group_size; k++){
                ll current_l = lr[k].first;
                // Move ptr while rs[ptr] <= current_l
                while(ptr < group_size && rs[ptr] <= current_l){
                    active--;
                    ptr++;
                }
                overlapping += active;
                active++;
            }
            total_overlaps += overlapping;
        }
        i = j;
    }
    cout << total_overlaps;
}

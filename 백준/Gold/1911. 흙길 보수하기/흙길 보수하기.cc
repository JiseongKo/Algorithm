#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    ll L;
    cin >> N >> L;
    vector<pair<ll, ll>> puddles(N);
    for(int i=0;i<N;i++) cin >> puddles[i].first >> puddles[i].second;
    
    sort(puddles.begin(), puddles.end(), [&](const pair<ll, ll> &a, const pair<ll, ll> &b) -> bool{
        if(a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    });
    
    ll count =0;
    ll current_end = -1;
    for(int i=0;i<N;i++){
        ll s = puddles[i].first;
        ll e = puddles[i].second;
        if(current_end >= e) continue;
        if(current_end >= s){
            s = current_end;
        }
        // Now need to cover [s, e]
        ll needed = (e - s + L -1)/L;
        count += needed;
        current_end = s + needed * L;
    }
    cout << count;
}

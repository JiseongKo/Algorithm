#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<ll> value(N+1);
    for(int i=1;i<=N;i++) cin>>value[i];
    vector<vector<int>> children(N+1, vector<int>());
    for(int i=2;i<=N;i++){
        int parent;
        cin>>parent;
        children[parent].push_back(i);
    }
    // DP arrays
    vector<ll> dp_included(N+1, 0);
    vector<ll> dp_excluded(N+1, 0);
    // Iterative post-order traversal
    vector<pair<int, bool>> stack;
    stack.emplace_back(1, false);
    // To keep track of processed nodes
    while(!stack.empty()){
        auto [node, processed] = stack.back();
        stack.pop_back();
        if(!processed){
            stack.emplace_back(node, true);
            for(auto it = children[node].rbegin(); it != children[node].rend(); ++it){
                stack.emplace_back(*it, false);
            }
        }
        else{
            ll inc = value[node];
            for(auto &child: children[node]){
                inc += dp_excluded[child];
            }
            dp_included[node] = inc;
            ll exc = 0;
            for(auto &child: children[node]){
                exc += max(dp_included[child], dp_excluded[child]);
            }
            dp_excluded[node] = exc;
        }
    }
    // Compute sum1 and sum2
    ll sum1 = dp_included[1];
    ll sum2 = dp_excluded[1] > 0 ? dp_excluded[1] : 0;
    // Reconstruct list1 (include root)
    vector<int> list1;
    stack.emplace_back(1, true);
    while(!stack.empty()){
        auto [node, include] = stack.back();
        stack.pop_back();
        if(include){
            list1.push_back(node);
            for(auto &child: children[node]){
                stack.emplace_back(child, false);
            }
        }
        else{
            for(auto &child: children[node]){
                if(dp_included[child] > dp_excluded[child]){
                    stack.emplace_back(child, true);
                }
                else{
                    stack.emplace_back(child, false);
                }
            }
        }
    }
    // Reconstruct list2 (exclude root)
    vector<int> list2;
    if(dp_excluded[1] > 0){
        stack.emplace_back(1, false);
        while(!stack.empty()){
            auto [node, include] = stack.back();
            stack.pop_back();
            if(include){
                list2.push_back(node);
                for(auto &child: children[node]){
                    stack.emplace_back(child, false);
                }
            }
            else{
                for(auto &child: children[node]){
                    if(dp_included[child] > dp_excluded[child]){
                        stack.emplace_back(child, true);
                    }
                    else{
                        stack.emplace_back(child, false);
                    }
                }
            }
        }
    }
    // Sort the lists
    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());
    // Output sums
    cout << sum1 << " " << sum2 << "\n";
    // Output list1
    for(auto &x: list1) cout << x << " ";
    cout << "-1\n";
    // Output list2
    if(list2.empty()){
        cout << "-1\n";
    }
    else{
        for(auto &x: list2) cout << x << " ";
        cout << "-1\n";
    }
}

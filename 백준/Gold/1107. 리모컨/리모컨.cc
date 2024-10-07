#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    int M;
    cin >> M;
    vector<bool> broken(10, false);
    for(int i=0;i<M;i++){
        int btn;
        cin >> btn;
        broken[btn] = true;
    }
    
    // Function to check if a channel can be pressed using working buttons
    auto can_press = [&](int num) -> bool{
        if(num == 0){
            return !broken[0];
        }
        while(num > 0){
            int digit = num % 10;
            if(broken[digit]) return false;
            num /= 10;
        }
        return true;
    };
    
    // Initialize the minimum presses to the case where we only use + or -
    int min_presses = abs(N - 100);
    
    // Check all possible channels from 0 to 999999
    // 999999 is chosen to cover the upper bound considering N <= 500,000
    for(int channel=0; channel<=1000000; channel++){
        if(can_press(channel)){
            // Number of button presses is number of digits + the difference
            int presses = to_string(channel).size() + abs(N - channel);
            if(presses < min_presses){
                min_presses = presses;
            }
        }
    }
    
    cout << min_presses;
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 두 단어가 회전 관계인지 확인하는 함수
bool isRotation(const string& a, const string& b) {
    if (a.length() != b.length()) return false;
    string doubled = a + a;
    return doubled.find(b) != string::npos;
}

int main(){
    int N;
    cin >> N;
    vector<string> words(N);
    for(int i=0; i<N; ++i){
        cin >> words[i];
    }

    vector<string> uniqueWords;

    for(int i=0; i<N; ++i){
        bool found = false;
        for(auto &uw : uniqueWords){
            if(isRotation(words[i], uw)){
                found = true;
                break;
            }
        }
        if(!found){
            uniqueWords.push_back(words[i]);
        }
    }

    cout << uniqueWords.size() << endl;
    return 0;
}

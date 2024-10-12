#include <bits/stdc++.h>
using namespace std;

struct Job {
    long long a;
    long long b;
};

// Comparator to sort jobs in increasing order of b_i / a_i
bool cmp(const Job &j1, const Job &j2){
    if(j1.a ==0 && j2.a ==0){
        return false;
    }
    if(j1.a ==0){
        return false; // j1 has infinity, should come after j2
    }
    if(j2.a ==0){
        return true; // j2 has infinity, j1 comes first
    }
    // Compare j1.b / j1.a <= j2.b / j2.a
    // To avoid floating point, compare j1.b * j2.a <= j2.b * j1.a
    return (j1.b * j2.a) < (j2.b * j1.a);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Job> jobs(n);
    for(int i=0;i<n;i++) cin >> jobs[i].a >> jobs[i].b;
    sort(jobs.begin(), jobs.end(), cmp);
    long long T =0;
    for(auto &job: jobs){
        T = (T * (1 + job.a) + job.b) % 40000;
    }
    cout << T;
}

#include <bits/stdc++.h>
using namespace std;
typedef complex<double> cd;
const double PI = acos(-1.0);

// Iterative FFT (Cooley-Turkey) implementation
void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    
    // Bit-reversal ordering
    for(int i=1,j=0;i<n;i++){
        int bit = n >>1;
        while(j>=bit){
            j -= bit;
            bit >>=1;
        }
        if(j < bit)
            j += bit;
        if(i < j)
            swap(a[i], a[j]);
    }
    
    // FFT
    for(int len=2; len<=n; len <<=1){
        double angle = 2*PI / len * (invert ? -1 : 1);
        cd wlen(cos(angle), sin(angle));
        for(int i=0; i<n; i += len){
            cd w(1);
            for(int j=0; j<len/2; ++j){
                cd u = a[i+j];
                cd v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
    
    if(invert){
        for(auto & x: a) x /= n;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> X(N);
    for(auto &x: X) cin >> x;
    vector<int> Y(N);
    for(auto &y: Y) cin >> y;
    
    // Reverse Y
    vector<int> Y_rev(Y.rbegin(), Y.rend());
    // Duplicate Y_rev
    vector<int> Y_dup(2*N, 0);
    for(int i=0; i<2*N; ++i){
        Y_dup[i] = Y_rev[i % N];
    }
    
    // Determine FFT size S >= 3N
    int S = 1;
    while(S < (int)(X.size() + Y_dup.size())) S <<=1;
    
    // Prepare A and B
    vector<cd> A(S, 0), B(S, 0);
    for(int i=0; i<X.size(); ++i){
        A[i] = (double)X[i];
    }
    for(int i=0; i<Y_dup.size(); ++i){
        B[i] = (double)Y_dup[i];
    }
    
    // Perform FFT on A and B
    fft(A, false);
    fft(B, false);
    
    // Multiply point-wise
    for(int i=0; i<S; ++i){
        A[i] *= B[i];
    }
    
    // Inverse FFT
    fft(A, true);
    
    // Extract convolution result
    // C[k] = convolution[k + N -1], for k=0 to N-1
    // Ensure that k + N -1 < A.size()
    // Since Y_dup is 2N, and X is N, convolution size is 3N -1 <= S
    // So k + N -1 <= 3N -2 <= S -1
    // Now, find the maximum C[k]
    long long maxS = LLONG_MIN;
    for(int k=0; k<N; ++k){
        int idx = k + N -1;
        if(idx >= (int)A.size()) break;
        // Round to nearest integer
        long long val = round(A[idx].real());
        if(val > maxS) maxS = val;
    }
    
    cout << maxS;
}

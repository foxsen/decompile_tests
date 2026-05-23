#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K; cin >> N >> K;
    vector<int> A(N), B(N);
    for (int i=0; i<N; i++) cin >> A[i];
    int S = accumulate(A.begin(), A.end(), 0);
    vector<int> divisors;
    for (int i=1; i*i<=S; i++) {
        if (S % i == 0) {
            divisors.push_back(i);
            if (i*i != S) divisors.push_back(S / i);
        }
    }
    sort(divisors.begin(), divisors.end(), greater<int>());
    for (int d: divisors) {
        for (int i=0; i<N; i++) B[i] = A[i] % d;
        sort(B.begin(), B.end());
        int move = N - accumulate(B.begin(), B.end(), 0) / d; 
        if (accumulate(B.begin(), B.begin() + move, 0) <= K) {
            cout << d << endl;
            return 0;
        }
    }
}
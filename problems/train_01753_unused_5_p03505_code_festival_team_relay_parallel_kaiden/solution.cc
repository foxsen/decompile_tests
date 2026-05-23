#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

int main() {
    ll K, A, B;
    cin >> K >> A >> B;

    if (K <= A) {
        cout << 1 << endl;
    } else if (A - B <= 0) {
        cout << -1 << endl;
    } else {
        ll t = K - A;
        cout << (t + (A - B) - 1) / (A - B) * 2 + 1 << endl;
    }
}
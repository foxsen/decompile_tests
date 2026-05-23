#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = (a); i <= (b); ++i)
#define ll long long

int main() {
    while(1) {
        ll n, x, y;
        cin >> n >> x >> y;
        if(!n) return 0;
        string s = "LR";
        x--, y--;
        vector<int> v(n);
        rep(i, n) {
            v[i] = (x < (1LL << (n - 1 - i)));
            if(v[i])
                x = x ^ ((1LL << (n - 1 - i)) - 1);
            else
                x -= 1LL << (n - 1 - i);
        }
        for(int i = n - 1; i + 1; --i) {
            int t = (y < (1LL << i) ^ v[i]) > 0;
            if(y >= (1LL << i)) {
                y ^= 1LL << i;
                if(t) y ^= (1LL << i) - 1;
            } else if(!t)
                y ^= (1LL << i) - 1;
            cout << s[t];
        }
        cout << endl;
    }
}

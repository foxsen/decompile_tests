#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
int T;
ll fac[N], inv[N];
const ll mod = 998244353;

ll qpow(ll x, ll y) {
    ll ret = 1;
    x %= mod;
    while (y) {
        if(y & 1) ret = ret * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ret;
}

ll C(ll n, ll m) {
    return fac[n] * inv[n - m] % mod * inv[m] % mod;
}

void init(int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }
    inv[n] = qpow(fac[n], mod - 2);
    for (int i = n; i >= 1; --i) {
        inv[i - 1] = inv[i] * i % mod;
    }
}
void solve() {
    int n, zero = 0, grp = 0, pre = -1;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') zero++;
        else if (i && s[i - 1] == '1' && pre != i - 1) {
            pre = i;
            grp++;
        }
    }
    //cout << zero << ' ' << grp << '\n';
    cout << C(zero + grp, grp) << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    init(N - 1);
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
// Words are flowing out like endless rain into a paper cup
// They slither while they pass they slip away across the universe
// Pools of sorrow, waves of joy are drifting through my open mind
// Possessing and caressing me

#include <bits/stdc++.h>
using namespace std;

using LL = long long;

namespace _buff {

const size_t BUFF = 1 << 19;
char ibuf[BUFF], *ib = ibuf, *ie = ibuf;
char getc() {
    if (ib == ie) {
        ib = ibuf;
        ie = ibuf + fread(ibuf, 1, BUFF, stdin);
    }
    return ib == ie ? -1 : *ib++;
}

}

LL read() {
    using namespace _buff;
    LL ret = 0;
    bool pos = true;
    char c = getc();
    for (; (c < '0' || c > '9') && c != '-'; c = getc()) {
        assert(~c);
    }
    if (c == '-') {
        pos = false;
        c = getc();
    }
    for (; c >= '0' && c <= '9'; c = getc()) {
        ret = (ret << 3) + (ret << 1) + (c ^ 48);
    }
    return pos ? ret : -ret;
}

const size_t N = 5e5 + 5;
const int MOD = 998244353;

int qpow(int base, int e) {
    int ret = 1;
    for (; e; e >>= 1) {
        if (e & 1) {
            ret = (LL) ret * base % MOD;
        }
        base = (LL) base * base % MOD;
    }
    return ret;
}

int fac[N], inv[N];

void prep() {
    fac[0] = 1;
    for (int i = 1; i <= N - 1; ++i) {
        fac[i] = (LL) fac[i - 1] * i % MOD;
    }
    inv[N - 1] = qpow(fac[N - 1], MOD - 2);
    for (int i = N - 1; i >= 1; --i) {
        inv[i - 1] = (LL) inv[i] * i % MOD;
    }
}

int comb(int n, int m) {
    return (LL) fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

int main() {
    prep();
    int n = read(), m = read(), ans = 0;
    if (n > m) swap(n, m);
    int mul1 = qpow(n + 1, m - n), mul2 = 1;
    for (int i = n; i >= 0; --i) {
        ans = (ans + (i & 1 ? -1LL : 1LL) * comb(n, i) * comb(m, i) % MOD
                * fac[i] % MOD * mul1 % MOD * mul2) % MOD;
        mul1 = (LL) mul1 * (n + 1) % MOD;
        mul2 = (LL) mul2 * (m + 1) % MOD;
    }
    if (ans < 0) ans += MOD;
    cout << ans;
    return 0;
}
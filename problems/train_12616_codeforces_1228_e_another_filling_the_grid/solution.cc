#include <bits/stdc++.h>
#pragma GCC optimize("-O3", "unroll-loops")
using namespace std;
template <typename T1, typename T2>
inline void chmin(T1& a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
inline void chmax(T1& a, T2 b) {
  if (a < b) a = b;
}
const long long MOD = 1e9 + 7;
const long long MAX = 200010;
const long long mod = 1000000007;
struct mint {
  long long x;
  mint(long long x = 0) : x((x % mod + mod) % mod) {}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod - a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res += a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res -= a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res *= a;
  }
  mint pow(long long t) const {
    if (!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }
  mint inv() const { return pow(mod - 2); }
  mint& operator/=(const mint a) { return (*this) *= a.inv(); }
  mint operator/(const mint a) const {
    mint res(*this);
    return res /= a;
  }
};
long long fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (long long i = 2; i < 300; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}
long long COM(long long n, long long k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
mint dp[303][303];
mint K;
long long N;
bool done[303][303];
mint kpow[303], k1pow[303];
void powinit() {
  for (long long i = 0; i < 303; i++) {
    kpow[i] = K.pow(i);
  }
  for (long long i = 0; i < 303; i++) {
    k1pow[i] = (K - 1).pow(i);
  }
}
mint func(long long r, long long c) {
  if (done[r][c]) return dp[r][c];
  if (c == 0) {
    mint res = kpow[N] - k1pow[N];
    res = res.pow(r);
    dp[r][c] = res;
    done[r][c] = true;
    return dp[r][c];
  }
  if (r == 1) {
    dp[r][c] = kpow[N - c];
    done[r][c] = true;
    return dp[r][c];
  }
  mint res = 0;
  res = k1pow[c] * (kpow[N - c] - k1pow[N - c]) * func(r - 1, c);
  mint res2 = 0;
  for (long long c0 = 1; c0 < c + 1; c0++) {
    res2 += (mint)COM(c, c0) * (k1pow[c - c0]) * func(r - 1, c - c0);
  }
  res2 *= kpow[N - c];
  res += res2;
  done[r][c] = true;
  dp[r][c] = res;
  return dp[r][c];
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N;
  long long k;
  cin >> k;
  COMinit();
  K = (mint)k;
  powinit();
  cout << func(N, N).x << endl;
}

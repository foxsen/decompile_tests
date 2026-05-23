#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1000005;
const long long MOD = 998244353;
const long long inv3 = 332748118;
long long n, ans;
long long Read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x * 10) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
template <typename T>
void Put1(T x) {
  if (x > 9) Put1(x / 10);
  putchar(x % 10 ^ 48);
}
template <typename T>
void Put(T x, char c = -1) {
  if (x < 0) putchar('-'), x = -x;
  Put1(x);
  if (c >= 0) putchar(c);
}
template <typename T>
T Max(T x, T y) {
  return x > y ? x : y;
}
template <typename T>
T Min(T x, T y) {
  return x < y ? x : y;
}
template <typename T>
T Abs(T x) {
  return x < 0 ? -x : x;
}
long long qpow(long long x, long long y) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = 1ll * ret * x % MOD;
    x = 1ll * x * x % MOD;
    y >>= 1;
  }
  return ret;
}
long long fac[MAXN], ifac[MAXN];
void init(long long x) {
  fac[0] = ifac[0] = 1;
  for (long long i = 1; i <= x; ++i) fac[i] = 1ll * fac[i - 1] * i % MOD;
  ifac[x] = qpow(fac[x], MOD - 2);
  for (long long i = x - 1; i >= 1; --i)
    ifac[i] = ifac[i + 1] * (i + 1ll) % MOD;
}
long long C(long long x, long long y) {
  if (x < y || y < 0) return 0;
  return 1ll * fac[x] * ifac[y] % MOD * ifac[x - y] % MOD;
}
signed main() {
  n = Read();
  init(n);
  for (long long i = 1; i <= n; ++i)
    ans = (ans + ((i & 1) ? 1 : -1) * C(n, i) * qpow(3, (n - i) * n + i)) % MOD;
  ans = ans * 2ll % MOD;
  for (long long i = 1; i <= n; ++i)
    ans = (ans - ((i & 1) ? -1 : 1) * 3 * C(n, i) * qpow(3, (n - i) * n) % MOD *
                     (qpow(1 - qpow(inv3, n - i), n) - 1)) %
          MOD;
  Put((ans + MOD) % MOD);
  return 0;
}

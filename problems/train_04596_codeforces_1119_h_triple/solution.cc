#include <bits/stdc++.h>
using namespace std;
inline int gi() {
  int data = 0, fu = 1;
  char ch = 0;
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') fu = -1, ch = getchar();
  while ('0' <= ch && ch <= '9')
    data = (data << 1) + (data << 3) + (ch ^ 48), ch = getchar();
  return data * fu;
}
const long long mod = 998244353;
long long n, K, X, Y, Z, AC, A[524288], B[524288], C[524288], inv2, inv4,
    f[524288], g[524288], h[524288], ans[524288];
inline long long Pow(long long ts, long long js) {
  long long al = 1;
  while (js) {
    if (js & 1) al = 1ll * al * ts % mod;
    ts = 1ll * ts * ts % mod;
    js >>= 1;
  }
  return al;
}
inline void fwt(long long *P, int op) {
  for (long long i = 1; i < K; i <<= 1)
    for (long long j = 0, dt = (i << 1); j < K; j += dt)
      for (long long k = 0; k < i; ++k) {
        long long fx = P[j + k], fy = P[j + k + i];
        P[j + k] = 1ll * (fx + fy) * op % mod;
        P[j + k + i] = 1ll * (fx - fy + mod) * op % mod;
      }
  return;
}
int main() {
  n = gi();
  K = gi();
  K = 1 << K;
  inv4 = Pow(4, mod - 2);
  inv2 = Pow(2, mod - 2);
  X = gi();
  Y = gi();
  Z = gi();
  AC = 0;
  for (long long i = 1; i <= n; ++i) A[i] = gi(), B[i] = gi(), C[i] = gi();
  for (long long i = 1; i <= n; ++i)
    AC ^= C[i], A[i] ^= C[i], B[i] ^= C[i], C[i] = 0;
  for (long long i = 1; i <= n; ++i) f[A[i]]++, g[B[i]]++, h[A[i] ^ B[i]]++;
  fwt(f, 1);
  fwt(g, 1);
  fwt(h, 1);
  long long v0, v1, v2, v3;
  v0 = (Z + X + Y + 2 * mod) % mod;
  v1 = (Z + X - Y + 2 * mod) % mod;
  v2 = (Z - X + Y + 2 * mod) % mod;
  v3 = (Z - X - Y + 2 * mod) % mod;
  for (long long i = 0; i < K; ++i) {
    long long x0, x1, x2, x3;
    x0 = (n + f[i] + g[i] + h[i] + 2 * mod) % mod * inv4 % mod;
    x1 = (1ll * (n + f[i]) * inv2 % mod - x0 + mod) % mod;
    x2 = (1ll * (n + g[i]) * inv2 % mod - x0 + mod) % mod;
    x3 = (1ll * (n + h[i]) * inv2 % mod - x0 + mod) % mod;
    ans[i] = 1ll * Pow(v0, x0) * Pow(v1, x1) % mod * Pow(v2, x2) % mod *
             Pow(v3, x3) % mod;
  }
  fwt(ans, inv2);
  for (long long i = 0; i < K; ++i) printf("%I64d ", ans[i ^ AC]);
  puts("");
  return 0;
}

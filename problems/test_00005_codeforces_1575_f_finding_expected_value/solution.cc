#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 11, mod = 1e9 + 7;
int f[N], g[N], a[N], b[N], c[N], d[N], fac[N], ifac[N], ik[N], ik0[N];
int n, s, ans, cnt, k, m;
int fp(int a, int b) {
  int res = 1;
  for (; b; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) res = 1ll * res * a % mod;
  return res;
}
int C(int n, int m) { return 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod; }
int main() {
  scanf("%d%d", &n, &k);
  fac[0] = 1;
  for (int i = (1); i <= (n); i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  for (int i = (0); i <= (n); i++) ifac[i] = fp(fac[i], mod - 2);
  ik[0] = ik0[0] = 1;
  for (int i = (1); i <= (n); i++) {
    ik[i] = 1ll * ik[i - 1] * fp(k, mod - 2) % mod,
    ik0[i] = 1ll * ik0[i - 1] * (1 - fp(k, mod - 2)) % mod;
  }
  s = n;
  for (int i = (1); i <= (n); i++) {
    scanf("%d", a + i);
    if (a[i] == -1) {
      --i;
      --n;
      ++cnt;
      continue;
    }
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  m = unique(b + 1, b + n + 1) - b - 1;
  int p = 0;
  for (int i = (1); i <= (n); i++) {
    a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
    if (!c[a[i]]) ++p;
    ++c[a[i]];
  }
  n = k;
  g[0] = n;
  for (int i = (1); i <= (s - 1); i++)
    g[i] = 1ll * fp(s - i, mod - 2) *
           (1ll * s * n % mod + 1ll * i * (n - 1) % mod * g[i - 1] % mod) % mod;
  f[s] = 0;
  for (int i = s - 1; ~i; --i) f[i] = (f[i + 1] + g[i]) % mod;
  for (int i = (1); i <= (p); i++) ++d[c[i]];
  d[0] = n - m;
  for (int i = (0); i <= (s); i++) {
    if (d[i] > 0) {
      for (int j = (0); j <= (cnt); j++)
        ans = (ans + 1ll * d[i] * f[i + j] % mod * C(cnt, j) % mod * ik[j] %
                         mod * ik0[cnt - j]) %
              mod;
    }
  }
  ans = 1ll * (ans - 1ll * f[0] * (n - 1)) % mod * fp(n, mod - 2) % mod;
  ans = (ans + mod) % mod;
  printf("%d\n", ans);
  return 0;
}

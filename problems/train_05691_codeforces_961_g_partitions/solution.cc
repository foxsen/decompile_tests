#include <bits/stdc++.h>
using namespace std;
const int maxn = 202020;
const int mod = 1000000007;
int a[maxn], s;
int fac[maxn], ifac[maxn];
int qpow(int a, int n) {
  int ans = 1;
  for (; n; n >>= 1, a = (long long)a * a % mod)
    if (n & 1) ans = (long long)ans * a % mod;
  return ans;
}
int gets(int n, int m) {
  if (m > n) return 0;
  int ans = 0;
  for (int i = 0; i <= m; i++) {
    if (i % 2 == 0)
      ans = (ans + (long long)fac[m] * ifac[i] % mod * ifac[m - i] % mod *
                       qpow(m - i, n) % mod) %
            mod;
    else
      ans = (ans -
             (long long)fac[m] * ifac[i] % mod * ifac[m - i] % mod *
                 qpow(m - i, n) % mod +
             mod) %
            mod;
  }
  return ans * (long long)ifac[m] % mod;
}
int main(void) {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), s = (s + a[i]) % mod;
  fac[0] = 1;
  for (int i = 1; i <= k; i++) fac[i] = fac[i - 1] * (long long)i % mod;
  ifac[k] = qpow(fac[k], mod - 2);
  for (int i = k - 1; i >= 0; i--)
    ifac[i] = ifac[i + 1] * (long long)(i + 1) % mod;
  int ans = (gets(n, k) + (long long)gets(n - 1, k) * (n - 1)) % mod;
  printf("%I64d\n", ans * (long long)s % mod);
  return 0;
}

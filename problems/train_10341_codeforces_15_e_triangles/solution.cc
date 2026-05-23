#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000009;
long long n, f[1000100], g[1000100], times = 1;
long long t(long long x) {
  if (x % 2) return x / 2;
  return 0;
}
signed main() {
  scanf("%lld", &n);
  f[0] = 0;
  f[1] = 2;
  g[1] = 4;
  for (long long i = 2; i <= n; i++) g[i] = (1LL * g[i - 1] * 2 + 4) % MOD;
  for (long long i = 2; i <= n - 2; i++) {
    f[i] =
        1LL * (2 * times % MOD + f[i - 1] + 2LL * g[t(i)] * times % MOD) % MOD;
    if (i % 2) times = 1LL * times * (g[t(i)] + 1) % MOD;
  }
  printf("%lld\n",
         (1LL * 2 * f[n - 2] * f[n - 2] % MOD + 1LL * 8 * f[n - 2] % MOD + 10) %
             MOD);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e9, mod = 998244353;
const long long N = 4e6 + 100, M = 3e5 + 100, T = 101000, maxn = 1e6 + 100;
long long n, m, dp[N], qz[N];
signed main() {
  scanf("%lld%lld", &n, &m);
  dp[1] = 1;
  long long crt = 0;
  for (long long i = 1; i <= n; i++) {
    qz[i] += qz[i - 1];
    qz[i] %= m;
    dp[i] += (crt + qz[i]) % m;
    for (long long j = 2; j * i <= n; j++) {
      qz[i * j] += dp[i];
      qz[i * j] %= m;
      qz[min(i * j + j, n + 1ll)] += (m - dp[i]) % m;
      qz[min(i * j + j, n + 1ll)] %= m;
    }
    crt = (crt + dp[i]) % m;
  }
  printf("%lld\n", dp[n]);
}

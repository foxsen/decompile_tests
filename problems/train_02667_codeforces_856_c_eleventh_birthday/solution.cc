#include <bits/stdc++.h>
using namespace std;
long long n, a[2005], b[2005], n1, n2, f[2][2005][13], g[2][2005][13],
    c[2005][2005], pw[2005], t;
long long calc(long long n, long long m) {
  if (m == 0) return (n == 0);
  return pw[n] * c[n + m - 1][m - 1] % 998244353;
}
signed main() {
  pw[0] = 1;
  c[0][0] = 1;
  for (long long i = 1; i <= 2000; i++)
    pw[i] = pw[i - 1] * i % 998244353, c[i][0] = 1;
  for (long long i = 1; i <= 2000; i++)
    for (long long j = 1; j <= 2000; j++)
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % 998244353;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    n1 = n2 = 0;
    for (long long i = 1; i <= n; i++) {
      long long x, p = 0;
      scanf("%lld", &x);
      for (long long j = x; j; j /= 10) p ^= 1;
      if (p)
        a[++n1] = x % 11;
      else
        b[++n2] = x % 11;
    }
    memset(f, 0, sizeof f), memset(g, 0, sizeof g);
    f[0][0][0] = g[0][0][0] = 1;
    for (long long i = 1; i <= n1; i++) {
      memset(f[i & 1], 0, sizeof f[i & 1]);
      for (long long j = 0; j <= i; j++)
        for (long long k = 0; k < 11; k++) {
          long long p = (k - a[i] + 11) % 11, q = (k + a[i]) % 11;
          f[i & 1][j][k] = (f[i & 1][j][k] + f[(i - 1) & 1][j][p]) % 998244353;
          if (j)
            f[i & 1][j][k] =
                (f[i & 1][j][k] + f[(i - 1) & 1][j - 1][q]) % 998244353;
        }
    }
    for (long long i = 1; i <= n2; i++) {
      memset(g[i & 1], 0, sizeof g[i & 1]);
      for (long long j = 0; j <= i; j++)
        for (long long k = 0; k < 11; k++) {
          long long p = (k - b[i] + 11) % 11, q = (k + b[i]) % 11;
          g[i & 1][j][k] = (g[i & 1][j][k] + g[(i - 1) & 1][j][p]) % 998244353;
          if (j)
            g[i & 1][j][k] =
                (g[i & 1][j][k] + g[(i - 1) & 1][j - 1][q]) % 998244353;
        }
    }
    long long ans = 0;
    for (long long i = 0; i <= n2; i++)
      for (long long j = 0; j < 11; j++) {
        ans = (ans + g[n2 & 1][i][j] * f[n1 & 1][n1 / 2][(11 - j) % 11] %
                         998244353 * pw[n1 / 2] % 998244353 * pw[n1 - n1 / 2] %
                         998244353 * calc(i, n1 - n1 / 2) % 998244353 *
                         calc(n2 - i, n1 / 2 + 1) % 998244353) %
              998244353;
      }
    printf("%lld\n", ans);
  }
  return 0;
}

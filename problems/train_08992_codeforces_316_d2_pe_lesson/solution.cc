#include <bits/stdc++.h>
using namespace std;
long long n, m, x, mod = 1e9 + 7, ans = 1, f[3];
signed main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &x);
    if (x == 1) m++;
  }
  f[0] = f[1] = 1;
  for (long long i = 2; i <= m; i++)
    f[i % 3] = (f[(i - 2) % 3] * (i - 1) + f[(i - 1) % 3]) % mod;
  for (long long i = n; i > m; i--) ans = ans * i % mod;
  printf("%lld", ans * f[(m % 3)] % mod);
  return 0;
}

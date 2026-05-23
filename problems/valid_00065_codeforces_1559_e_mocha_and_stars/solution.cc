#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, mod = 998244353;
long long f[55][N], l[N], r[N], sum[N], prim[N], nump, vis[N], mu[N];
void init() {
  mu[1] = 1;
  for (int i = 2; i < N; i++) {
    if (!vis[i]) {
      prim[++nump] = i;
      mu[i] = -1;
    }
    for (int j = 1; j <= nump && i * prim[j] < N; j++) {
      vis[i * prim[j]] = 1;
      if (i % prim[j] == 0)
        break;
      else
        mu[i * prim[j]] = -mu[i];
    }
  }
}
int main() {
  long long n, m;
  scanf("%lld%lld", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%lld%lld", l + i, r + i);
  long long ans = 0;
  init();
  for (int d = 1; d <= m; d++) {
    f[0][0] = 1;
    long long cnt = 0;
    if (mu[d]) {
      for (int i = 1; i <= n; i++) {
        sum[0] = f[i - 1][0];
        for (int j = 1; j <= m / d; j++)
          sum[j] = (sum[j - 1] + f[i - 1][j]) % mod;
        for (int j = (l[i] + d - 1) / d; j <= m / d; j++) {
          if (j >= r[i] / d)
            f[i][j] = sum[j - (l[i] + d - 1) / d] - sum[j - r[i] / d - 1];
          else
            f[i][j] = sum[j - (l[i] + d - 1) / d];
          f[i][j] = f[i][j] % mod;
        }
      }
      for (int j = 1; j <= m / d; j++) cnt = (cnt + f[n][j]) % mod;
      ans += mu[d] * cnt;
      ans = ans % mod;
      ans += mod;
      ans = ans % mod;
    }
  }
  cout << ans << endl;
  return 0;
}

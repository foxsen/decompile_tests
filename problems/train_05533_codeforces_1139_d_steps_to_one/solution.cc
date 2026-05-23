#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, N = 1e5 + 1;
int dp[N], n, g[N], f[N], e, tim;
int vis[N], sav[N], ep, ans, m;
inline void sai() {
  for (int i = 2; i < N; ++i) {
    if (!g[i]) {
      f[++e] = i;
      g[i] = i;
    }
    for (int j = 1; j <= e; ++j) {
      if (i * f[j] >= N) break;
      g[i * f[j]] = f[j];
      if (i % f[j] == 0) break;
    }
  }
}
inline void dfs(int now, int s, int num) {
  if (now == ep + 1) {
    if (num) {
      if (num & 1) {
        ans -= (m / s);
      } else {
        ans += (m / s);
      }
    }
    return;
  }
  dfs(now + 1, s, num);
  dfs(now + 1, s * sav[now], num + 1);
}
inline int calc(int x, int y) {
  ++tim;
  ep = 0;
  x /= y;
  m = n / y;
  ans = m;
  while (g[x]) {
    if (vis[g[x]] != tim) sav[++ep] = g[x], vis[g[x]] = tim;
    x /= g[x];
  }
  dfs(1, 1, 0);
  return ans;
}
inline int ksm(int x, int y) {
  int ans = 1;
  while (y) {
    if (y & 1) ans = (1LL * ans * x) % mod;
    x = (1LL * x * x) % mod;
    y >>= 1;
  }
  return ans;
}
int main() {
  sai();
  dp[1] = 0;
  scanf("%d", &n);
  for (int i = 2; i <= n; ++i) {
    int tot = n / i, al = 0;
    for (int j = sqrt(i); j; --j) {
      if (i % j == 0) {
        (al += (1LL * dp[j] * calc(i, j)) % mod) %= mod;
        if (i != 1 && i / j != j) {
          (al += (1LL * dp[i / j] * calc(i, i / j)) % mod) %= mod;
        }
      }
    }
    dp[i] = (1LL * (n + al) * ksm(n - tot, mod - 2)) % mod;
  }
  ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = (ans + dp[i]) % mod;
  }
  ans = (1LL * ans * ksm(n, mod - 2) + 1) % mod;
  printf("%d", ans);
  return 0;
}

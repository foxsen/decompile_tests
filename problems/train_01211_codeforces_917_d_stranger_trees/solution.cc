#include <bits/stdc++.h>
long long gi() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) f ^= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f ? x : -x;
}
int pow(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = 1ll * ret * x % 1000000007;
    x = 1ll * x * x % 1000000007;
    y >>= 1;
  }
  return ret;
}
int n, fir[110], dis[210], nxt[210], id;
void link(int a, int b) { nxt[++id] = fir[a], fir[a] = id, dis[id] = b; }
int siz[101], dp[101][101][101], _dp[101][101], C[101][101];
void dfs(int x, int fa = -1) {
  siz[x] = 1;
  dp[x][1][1] = 1;
  for (int i = fir[x]; i; i = nxt[i]) {
    if (dis[i] == fa) continue;
    dfs(dis[i], x);
    for (int j = 1; j <= siz[x]; ++j)
      for (int k = 1; k <= siz[x]; ++k)
        _dp[j][k] = dp[x][j][k], dp[x][j][k] = 0;
    for (int j = 1; j <= siz[dis[i]]; ++j)
      for (int k = 1; k <= siz[dis[i]]; ++k)
        if (dp[dis[i]][j][k])
          for (int J = 1; J <= siz[x]; ++J)
            for (int K = 1; K <= siz[x]; ++K)
              if (_dp[J][K]) {
                dp[x][j + J - 1][k + K] = (dp[x][j + J - 1][k + K] +
                                           1ll * _dp[J][K] * dp[dis[i]][j][k]) %
                                          1000000007;
                dp[x][j + J][K] =
                    (dp[x][j + J][K] +
                     1ll * _dp[J][K] * dp[dis[i]][j][k] % 1000000007 * k) %
                    1000000007;
              }
    siz[x] += siz[dis[i]];
  }
}
int ans[101];
int main() {
  n = gi();
  int a, b;
  for (int i = 1; i < n; ++i) a = gi(), b = gi(), link(a, b), link(b, a);
  dfs(1);
  ans[n - 1] = 1;
  for (int i = n - 2, pn = 1; ~i; --i, pn = 1ll * pn * n % 1000000007) {
    for (int j = 1; j <= n; ++j)
      ans[i] = (ans[i] + 1ll * dp[1][n - i][j] * j) % 1000000007;
    ans[i] = 1ll * ans[i] * pn % 1000000007;
  }
  C[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 1000000007;
  }
  for (int i = n - 1; ~i; --i)
    for (int j = i + 1; j < n; ++j)
      ans[i] = (ans[i] - 1ll * C[j][i] * ans[j] % 1000000007 + 1000000007) %
               1000000007;
  for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
  return 0;
}

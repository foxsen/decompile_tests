#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int maxn = 3010;
int n, m;
char c[maxn][maxn];
int dp[maxn][maxn];
int f[3][3];
int Get_DP(int qx, int qy, int zx, int zy) {
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (c[i][j] == '#') continue;
      if (i == qx && j == qy) {
        dp[i][j] = 1;
        continue;
      }
      dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
    }
  }
  return dp[zx][zy];
}
int det(int n) {
  int ret = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      while (f[j][i]) {
        long long tmp = f[i][i] / f[j][i];
        for (int k = i; k <= n; ++k)
          f[i][k] = (f[i][k] - tmp * f[j][k] % mod + mod) % mod;
        for (int k = i; k <= n; ++k) swap(f[i][k], f[j][k]);
        ret = -ret;
      }
    }
    if (f[i][i] == 0) return 0;
    ret = 1LL * ret * f[i][i] % mod;
  }
  return (ret % mod + mod) % mod;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      c[i][j] = getchar();
      while (c[i][j] < '!') c[i][j] = getchar();
    }
  }
  f[1][1] = Get_DP(2, 1, n, m - 1);
  f[1][2] = Get_DP(2, 1, n - 1, m);
  f[2][1] = Get_DP(1, 2, n, m - 1);
  f[2][2] = Get_DP(1, 2, n - 1, m);
  printf("%d\n", det(2));
  return 0;
}

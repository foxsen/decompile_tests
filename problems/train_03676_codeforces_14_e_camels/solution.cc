#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const int MAXN = 2005;
const int MAXM = 5005;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
const double FINF = 1e18;
long long dp[25][25][25][11][11];
int main() {
  int n, t;
  scanf("%d%d", &n, &t);
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= 4; ++i) {
    for (int j = 1; j <= 4; ++j) {
      if (i == j) continue;
      dp[2][i][j][0][0] = 1;
    }
  }
  for (int i = 3; i <= n; ++i) {
    for (int j = 1; j <= 4; ++j) {
      for (int u = 1; u <= 4; ++u) {
        if (u == j) continue;
        for (int k = 0; k <= t; ++k) {
          for (int p = 0; p <= t; ++p) {
            for (int q = 1; q <= 4; ++q) {
              if (j < u && j < q)
                dp[i][j][u][k][p + 1] += dp[i - 1][q][j][k][p];
              else if (j > u && j > q)
                dp[i][j][u][k + 1][p] += dp[i - 1][q][j][k][p];
              else {
                dp[i][j][u][k][p] += dp[i - 1][q][j][k][p];
              }
            }
          }
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= 4; ++i) {
    for (int j = 1; j <= 4; ++j) {
      ans += dp[n][i][j][t][t - 1];
    }
  }
  cout << ans << endl;
}

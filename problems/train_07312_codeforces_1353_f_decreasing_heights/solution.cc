#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const int N = 1e2 + 10;
long long a[N][N];
int flag[N][N];
long long dp[N][N];
int main() {
  int ncase;
  scanf("%d", &ncase);
  while (ncase--) {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<long long> v;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        scanf("%lld", &a[i][j]);
        a[i][j] -= i + j;
        v.push_back(a[i][j]);
      }
    }
    long long ans = 4 * INF * INF;
    for (auto &x : v) {
      memset((flag), (0), sizeof(flag));
      memset((dp), (0x3f), sizeof(dp));
      long long inf = dp[0][0];
      flag[1][1] = 1;
      dp[1][1] = 0;
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          if (a[i][j] < x) flag[i][j] = 0;
          if (flag[i][j] == 0) continue;
          dp[i][j] += a[i][j] - x;
          dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
          dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
          flag[i + 1][j] |= 1;
          flag[i][j + 1] |= 1;
        }
      }
      if (flag[n][m] != 0) ans = min(ans, dp[n][m]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}

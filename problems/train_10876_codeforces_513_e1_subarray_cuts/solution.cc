#include <bits/stdc++.h>
using namespace std;
int dp[30005][205][4], n, m;
int a[30005], b[30005][2];
int main() {
  cin >> n >> m;
  memset(dp, -0x3f, sizeof(dp));
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++)
    dp[i][1][0] = max(dp[i - 1][1][0], 0) + a[i],
    dp[i][1][1] = max(dp[i - 1][1][1], 0) - a[i];
  for (int i = 1; i <= n; i++) {
    dp[i][1][2] = max(dp[i - 1][1][2], dp[i][1][3]),
    dp[i][1][3] = max(dp[i - 1][1][3], dp[i][1][3]);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 2; j < m; j++) {
      dp[i][j][0] =
          max(dp[i - 1][j][0], max(dp[i - 1][j - 1][1], dp[i - 1][j - 1][3])) +
          2 * a[i];
      dp[i][j][1] =
          max(dp[i - 1][j][1], max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][2])) -
          2 * a[i];
      dp[i][j][2] = max(max(dp[i - 1][j][2], dp[i - 1][j - 1][2]),
                        max(dp[i - 1][j - 1][0], dp[i - 1][j][0]));
      dp[i][j][3] = max(max(dp[i - 1][j][3], dp[i - 1][j - 1][3]),
                        max(dp[i - 1][j - 1][1], dp[i - 1][j][1]));
    }
  }
  int ans = 0;
  for (int i = n; i >= 1; i--)
    b[i][1] = max(b[i + 1][1], 0) - a[i], b[i][0] = max(b[i + 1][0], 0) + a[i];
  for (int i = m - 1; i < n; i++)
    ans = max(ans, max(max(dp[i][m - 1][0], dp[i][m - 1][2]) + b[i + 1][1],
                       max(dp[i][m - 1][1], dp[i][m - 1][3]) + b[i + 1][0]));
  cout << ans;
}

#include <bits/stdc++.h>
using namespace std;
int dp[505][505], a[505], b[505], pp[505][505], n, m;
bool Print(int x) {
  if (!x) return 0;
  if (Print(pp[n][x]))
    cout << " " << b[x];
  else
    cout << b[x];
  return 1;
}
int main() {
  int ans = 1;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cin >> m;
  for (int i = 1; i <= m; i++) cin >> b[i];
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    int t = 0, p = 0;
    for (int j = 1; j <= m; j++) {
      dp[i][j] = dp[i - 1][j];
      pp[i][j] = pp[i - 1][j];
      if (a[i] == b[j] && dp[i][j] < t + 1) {
        dp[i][j] = t + 1;
        pp[i][j] = p;
      }
      if (a[i] > b[j] && dp[i - 1][j] > t) {
        t = dp[i - 1][j];
        p = j;
      }
    }
  }
  for (int i = 1; i <= m; i++)
    if (dp[n][i] > dp[n][ans]) ans = i;
  cout << dp[n][ans] << endl;
  if (dp[n][ans]) Print(ans);
  cout << endl;
  return 0;
}

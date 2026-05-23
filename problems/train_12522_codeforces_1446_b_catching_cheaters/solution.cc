#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  int dp[n + 5][m + 5];
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) - 1;
        if (s[i - 1] == t[j - 1]) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);
        }
        dp[i][j] = max(dp[i][j], 0);
        ans = max(ans, dp[i][j]);
      }
    }
  }
  cout << ans;
}

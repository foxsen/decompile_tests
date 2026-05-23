#include <bits/stdc++.h>
using namespace std;
int sum[1001][2];
int prefix[1001][2];
int dp[1001][2];
int min1 = 1000005;
int min2 = 1e6 + 5;
int main() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  string s[n + 1];
  int A[n + 1][m + 1];
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '#')
        A[i + 1][j + 1] = 0;
      else
        A[i + 1][j + 1] = 1;
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (A[j][i] == 0)
        sum[i][0]++;
      else
        sum[i][1]++;
    }
  }
  for (int i = 1; i <= m; i++) {
    prefix[i][0] = sum[i][0] + prefix[i - 1][0];
    prefix[i][1] = sum[i][1] + prefix[i - 1][1];
  }
  for (int i = 1; i <= m; i++) {
    min1 = 1e6 + 5;
    min2 = 1e6 + 5;
    for (int j = x; j <= y; j++) {
      if (i - j < 0)
        break;
      else {
        dp[i][0] = dp[i - j][1] + (prefix[i][0] - prefix[i - j][0]);
        if (min1 > dp[i][0]) min1 = dp[i][0];
        dp[i][1] = dp[i - j][0] + (prefix[i][1] - prefix[i - j][1]);
        if (min2 > dp[i][1]) min2 = dp[i][1];
      }
    }
    dp[i][0] = min1;
    dp[i][1] = min2;
  }
  cout << min(dp[m][0], dp[m][1]) << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int dp[105][105];
int main() {
  memset(dp, 0, sizeof dp);
  int n;
  string a;
  int ans = 0;
  cin >> a;
  n = a.size();
  for (int i = n - 1; i >= 0; i--)
    for (int j = n - 1; j >= 0; j--)
      if (a[i] == a[j]) dp[i][j] = dp[i + 1][j + 1] + 1;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) ans = max(ans, dp[i][j]);
  cout << ans << endl;
  return 0;
}

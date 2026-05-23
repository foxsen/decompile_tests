#include <bits/stdc++.h>
using namespace std;
int dp[160][160];
int main() {
  int n;
  scanf("%d", &n);
  dp[1][1] = 1;
  dp[0][0] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (j == 0)
        dp[i][j] = dp[i - 2][j];
      else
        dp[i][j] = (dp[i - 2][j] + dp[i - 1][j - 1]) % 2;
    }
  }
  cout << n << endl;
  for (int i = 0; i <= n; i++) cout << dp[n][i] << " ";
  cout << endl;
  cout << n - 1 << endl;
  for (int i = 0; i <= n - 1; i++) cout << dp[n - 1][i] << " ";
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long cost[200][200], dp[100][10][10], n, rem;
int main() {
  ios_base::sync_with_stdio(0);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) cin >> cost[i][j];
  cin >> n;
  for (int k = 1; k <= n; k++)
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        if (i - j) {
          rem = (3 ^ i ^ j);
          dp[k][i][j] = min(dp[k - 1][i][rem] + cost[i][j] + dp[k - 1][rem][j],
                            dp[k - 1][i][j] + cost[i][rem] + dp[k - 1][j][i] +
                                cost[rem][j] + dp[k - 1][i][j]);
        }
  cout << dp[n][0][2] << endl;
  cin.get();
  cin.get();
  return 0;
}

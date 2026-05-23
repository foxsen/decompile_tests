#include <bits/stdc++.h>
using namespace std;
int n, k;
int c[501];
bitset<501> dp[501][501];
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> c[i];
  dp[0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j - c[i] >= 0) {
        dp[i][j] |= dp[i - 1][j - c[i]];
        dp[i][j] |= (dp[i - 1][j - c[i]] << c[i]);
      }
    }
  }
  cout << dp[n][k].count() << endl;
  cout << 0;
  for (int i = 1; i < 501; i++) {
    if (dp[n][k].test(i)) cout << " " << i;
  }
  cout << endl;
  return 0;
}

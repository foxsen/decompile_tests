#include <bits/stdc++.h>
using namespace std;
const int sz = 1e5 + 5;
const int mod = 1e9 + 7;
void solver() {
  int n, d, k;
  cin >> n >> k >> d;
  int dp[105][2] = {0};
  dp[0][0] = 1;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k && i - j >= 0; j++) {
      dp[i][1] = (dp[i][1] + dp[i - j][1]) % mod;
      if (j >= d) {
        dp[i][1] = (dp[i][1] + dp[i - j][0]) % mod;
      } else
        dp[i][0] = (dp[i][0] + dp[i - j][0]) % mod;
    }
  }
  cout << dp[n][1];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solver();
  }
  return 0;
}

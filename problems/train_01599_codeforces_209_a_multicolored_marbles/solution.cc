#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int dp[1000001];
int main() {
  int n;
  cin >> n;
  int ans;
  int pre = 0;
  int pre2 = 0;
  dp[1] = 1;
  pre = 1;
  ans = dp[1];
  for (int i = 2; i <= n; i++) {
    if (i % 2 == 0) {
      dp[i] = pre + 1;
      dp[i] = dp[i] % mod;
      pre2 += dp[i];
      pre2 = pre2 % mod;
    } else {
      dp[i] = pre2 + 1;
      dp[i] = dp[i] % mod;
      pre += dp[i];
      pre = pre % mod;
    }
    ans += dp[i];
    ans = ans % mod;
  }
  cout << ans << endl;
  return 0;
}

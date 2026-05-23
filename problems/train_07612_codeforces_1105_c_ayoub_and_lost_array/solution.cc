#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200001, MOD = 1000000007;
int n, l, r;
long long one = 0, two = 0, zero = 0, dp[MAXN][3];
int main() {
  cin >> n >> l >> r;
  for (; l % 3 != 0 && l <= r; l++)
    if (l % 3 == 1)
      one++;
    else if (l % 3 == 2)
      two++;
  for (; r % 3 != 0 && r >= l; r--)
    if (r % 3 == 1)
      one++;
    else if (r % 3 == 2)
      two++;
  if (l <= r) {
    one += r / 3 - l / 3;
    two += r / 3 - l / 3;
    zero += r / 3 - l / 3 + 1;
  }
  dp[1][0] = zero, dp[1][1] = one, dp[1][2] = two;
  for (int i = 2; i <= n; i++) {
    dp[i][0] = (dp[i - 1][0] * zero % MOD + dp[i - 1][1] * two % MOD +
                dp[i - 1][2] * one % MOD) %
               MOD;
    dp[i][1] = (dp[i - 1][0] * one % MOD + dp[i - 1][1] * zero % MOD +
                dp[i - 1][2] * two % MOD) %
               MOD;
    dp[i][2] = (dp[i - 1][0] * two % MOD + dp[i - 1][1] * one % MOD +
                dp[i - 1][2] * zero % MOD) %
               MOD;
  }
  cout << dp[n][0] << "\n";
  return 0;
}

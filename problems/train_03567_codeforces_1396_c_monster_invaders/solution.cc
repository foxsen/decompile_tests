#include <bits/stdc++.h>
using namespace std;
long long n, r1, r2, r3, d;
const int N = 1e6 + 4;
long long dp[N][2];
long long a[N];
void debug() {
  cout << "-----debug-----" << endl;
  for (int i = 1; i <= n; ++i) {
    printf("dp[%d][%d]=%lld dp[%d][%d]=%lld\n", i, 0, dp[i][0], i, 1, dp[i][1]);
  }
}
int main() {
  cin >> n >> r1 >> r2 >> r3 >> d;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  memset(dp, 0x3f, sizeof(dp));
  dp[1][0] = r1 * a[1] + r3;
  dp[1][1] = min(r1 * a[1] + r1, r2);
  for (int i = 1; i < n; ++i) {
    dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + d + r1 * a[i + 1] + r3);
    dp[i + 1][1] = min(dp[i + 1][1], min(dp[i][0] + d + r1 * (a[i + 1] + 1),
                                         dp[i][0] + d + r2));
    dp[i + 1][0] =
        min(dp[i + 1][0], dp[i][1] + d + r1 * (a[i + 1] + 2) + 2 * d + r1);
    dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + d + r2 + r1 + 2 * d + r1);
    dp[i + 1][0] =
        min(dp[i + 1][0], dp[i][1] + d + r1 * a[i + 1] + r3 + 2 * d + r1);
    dp[i + 1][1] =
        min(dp[i + 1][1], dp[i][1] + d + r1 * a[i + 1] + r1 + d + r1 + d);
    dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + d + r2 + d + r1 + d);
    if (i == n - 1) {
      dp[i + 1][0] =
          min(dp[i + 1][0], dp[i][1] + d + r1 * a[i + 1] + r3 + d + r1);
    }
  }
  cout << dp[n][0] << endl;
  return 0;
}

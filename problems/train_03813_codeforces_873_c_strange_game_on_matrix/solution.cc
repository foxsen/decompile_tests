#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
long double PI = 4 * atan(1);
int k, n, m, a[101][101], dp[101][101], ans[101], rom[101];
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      cin >> a[i][j];
    }
  }
  for (int j = 1; j < m + 1; j++) {
    for (int i = 1; i < n + 1; i++) {
      dp[i][j] = a[i][j];
      dp[i][j] += dp[i - 1][j];
    }
  }
  for (int j = 1; j < m + 1; j++) {
    for (int i = n + 1 - 1; i >= 1; i--) {
      int rm = dp[i - 1][j];
      int tot = dp[min(i + k - 1, n)][j];
      int cur = tot - rm;
      if (cur >= ans[j]) {
        ans[j] = cur;
        rom[j] = rm;
      }
    }
  }
  for (int j = 2; j < m + 1; j++) {
    ans[j] += ans[j - 1];
    rom[j] += rom[j - 1];
  }
  cout << ans[m] << " " << rom[m];
  return 0;
}

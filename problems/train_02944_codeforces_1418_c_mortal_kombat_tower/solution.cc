#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    long long arr[n];
    long long dp[n][2][2];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    dp[0][0][0] = arr[0];
    dp[0][0][1] = 2 * n;
    dp[0][1][0] = 2 * n;
    dp[0][1][1] = 2 * n;
    for (int i = 1; i < n; i++) {
      dp[i][0][0] = min(dp[i - 1][1][0], dp[i - 1][1][1]);
      dp[i][0][1] = arr[i] + dp[i - 1][0][0];
      dp[i][1][0] = min(dp[i - 1][0][0], dp[i - 1][0][1]);
      dp[i][1][1] = dp[i - 1][1][0];
      if (i != 1) {
        dp[i][0][0] += arr[i];
      }
    }
    cout << min(min(dp[n - 1][0][0], dp[n - 1][0][1]),
                min(dp[n - 1][1][0], dp[n - 1][1][1]))
         << endl;
  }
  return 0;
}

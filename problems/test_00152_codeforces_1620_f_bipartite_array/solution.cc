#include <bits/stdc++.h>
using namespace std;
long long a[1000005], dp[1000005][2];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    a[0] = 1e9, dp[0][0] = -1e9;
    for (long long i = 1; i <= n; i++) dp[i][0] = dp[i][1] = 1e9;
    for (long long i = 1; i <= n; i++) {
      long long x = -a[i - 1], y = dp[i - 1][0];
      if (a[i] > x) dp[i][1] = min(dp[i][1], y);
      if (a[i] > y) dp[i][1] = min(dp[i][1], x);
      if (-a[i] > x) dp[i][0] = min(dp[i][0], y);
      if (-a[i] > y) dp[i][0] = min(dp[i][0], x);
      x = a[i - 1], y = dp[i - 1][1];
      if (a[i] > x) dp[i][1] = min(dp[i][1], y);
      if (a[i] > y) dp[i][1] = min(dp[i][1], x);
      if (-a[i] > x) dp[i][0] = min(dp[i][0], y);
      if (-a[i] > y) dp[i][0] = min(dp[i][0], x);
    }
    if (dp[n][1] <= n || dp[n][0] <= n) {
      cout << "YES\n";
      long long now = 0;
      if (dp[n][1] <= n) now = 1;
      for (long long i = n; i >= 1; i--) {
        if (now == 1) {
          long long x = -a[i - 1], y = dp[i - 1][0];
          if (a[i] > x && dp[i][1] == y) now = 0;
          if (a[i] > y && dp[i][1] == x) now = 0;
          x = a[i - 1], y = dp[i - 1][1];
          if (a[i] > x && dp[i][1] == y) now = 1;
          if (a[i] > y && dp[i][1] == x) now = 1;
        } else {
          long long x = -a[i - 1], y = dp[i - 1][0];
          if (-a[i] > x && dp[i][0] == y) now = 0;
          if (-a[i] > y && dp[i][0] == x) now = 0;
          x = a[i - 1], y = dp[i - 1][1];
          if (-a[i] > x && dp[i][0] == y) now = 1;
          if (-a[i] > y && dp[i][0] == x) now = 1;
          a[i] = -a[i];
        }
      }
      for (long long i = 1; i <= n; i++) cout << a[i] << " ";
      cout << "\n";
    } else
      cout << "NO\n";
  }
  return 0;
}

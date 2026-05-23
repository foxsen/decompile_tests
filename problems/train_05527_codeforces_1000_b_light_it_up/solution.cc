#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e18;
const int inf = 1e9;
const int MOD = 1e9 + 7;
const int nax = 1000000 + 10;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int n, m;
  cin >> n >> m;
  long long int i, j = 0, k = 0, a[n], d = 1, t = -1;
  bool f = 1;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long int dp[2][n + 1];
  dp[0][n] = m - a[n - 1];
  dp[1][n] = 0;
  f = 0;
  for (i = n - 2; i >= 0; i--) {
    dp[f][i + 1] = dp[f][i + 2];
    dp[!f][i + 1] = a[i + 1] - a[i] + dp[!f][i + 2];
    f = !f;
  }
  dp[f][i + 1] = dp[f][i + 2];
  dp[!f][i + 1] = a[0] + dp[!f][i + 2];
  j = 0, k = 0;
  f = 1;
  long long int ans = 0;
  for (i = 0; i < n; i++) {
    if (f) {
      k += a[i] - j;
    } else {
      if (1 < (a[i] - j)) {
        t = k;
        t += (a[i] - j);
        t--;
        if (n & 1)
          t += dp[0][i + 1];
        else
          t += dp[1][i + 1];
        ans = max(ans, t);
      }
      d = max(d, a[i] - j);
    }
    j = a[i];
    f = !f;
  }
  if (f)
    k += m - j;
  else {
    if (1 < (m - j)) {
      k += (m - j);
      k--;
    }
    if (m - j > d) d = m - j;
  }
  if (d == 1) {
    cout << k;
    return 0;
  }
  ans = max(ans, k);
  cout << ans;
}

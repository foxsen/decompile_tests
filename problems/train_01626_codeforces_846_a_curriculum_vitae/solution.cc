#include <bits/stdc++.h>
using namespace std;
int a[105];
int dp[105];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1] + (a[i] == 0);
    cnt += a[i];
  }
  int res = cnt;
  int one = 0;
  for (int i = 1; i <= n; i++) {
    one += a[i];
    res = max(res, dp[i] + (cnt - one));
  }
  cout << res << endl;
  return 0;
}

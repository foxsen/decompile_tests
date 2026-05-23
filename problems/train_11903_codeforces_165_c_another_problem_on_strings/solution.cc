#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
string s;
int cnt, dp[N], k;
long long ans, c0;
int main() {
  cin >> k >> s;
  int n = s.length();
  for (int i = 0; i < n; i++) {
    if (s[i] == '1')
      cnt++, dp[cnt] = i, ans += (c0 * (c0 + 1)) / 2, c0 = 0;
    else
      c0++;
  }
  ans += (c0 * (c0 + 1)) / 2;
  if (k == 0) {
    cout << ans;
    return 0;
  }
  ans = 0;
  for (int i = k; i <= cnt; i++) {
    int l, r;
    if (i - k == 0)
      l = dp[1] + 1;
    else
      l = dp[i - k + 1] - dp[i - k];
    if (i == cnt)
      r = n - dp[cnt];
    else
      r = dp[i + 1] - dp[i];
    ans += (1ll * l * 1ll * r);
  }
  cout << ans;
  return 0;
}

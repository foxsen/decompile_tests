#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 50;
long long n, dp[maxn], k, a[maxn], b[maxn], tp[maxn];
void solve() {
  for (long long i = 1; i <= n; i++) b[i] = i - a[i];
  long long pos = 1, ans = 1e18;
  for (long long i = 1; i <= n; i++) {
    dp[i] = (b[i] >= 0);
    for (long long j = 1; j <= i - 1; j++) {
      if (b[i] >= 0 and a[i] > a[j] and b[j] <= b[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    if (dp[i] >= k and b[i] >= 0) {
      ans = min(ans, b[i]);
    }
  }
  if (ans != 1e18)
    cout << ans << '\n';
  else
    cout << -1 << '\n';
}
void input() {
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) cin >> a[i], dp[i] = 0;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  ;
  long long tt;
  cin >> tt;
  while (tt--) {
    input();
    solve();
  }
}

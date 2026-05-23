#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
void fail() {
  std::cout << "NO\n";
  exit(0);
}
using namespace std;
const long long N = 502;
long long n, k, a[N];
bool dp[502][502][502];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  dp[1][a[1]][0] = 1;
  dp[1][0][a[1]] = 1;
  dp[1][0][0] = 1;
  for (long long i = 2; i <= n; i++) {
    dp[i][0][0] = 1;
    for (long long j = 0; j <= k; j++) {
      for (long long s = 0; s <= k; s++) {
        dp[i][j][s] = dp[i - 1][j][s];
        if (j >= a[i]) dp[i][j][s] = max(dp[i][j][s], dp[i - 1][j - a[i]][s]);
        if (s >= a[i]) dp[i][j][s] = max(dp[i][j][s], dp[i - 1][j][s - a[i]]);
      }
    }
  }
  vector<long long> ans;
  for (long long s = 0; s <= k; s++) {
    if (dp[n][s][k - s] || dp[n][k - s][s]) ans.push_back(s);
  }
  cout << ans.size() << '\n';
  for (long long i : ans) cout << i << ' ';
  cout << '\n';
  return 0;
}

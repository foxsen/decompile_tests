#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
#pragma GCC diagnostic ignored "-Wsign-compare"
long long dp[401][201];
void solve() {
  int n;
  cin >> n;
  vector<int> vals(n);
  for (int i = 0; i < n; i++) {
    cin >> vals[i];
  }
  sort(vals.begin(), vals.end());
  for (int i = 0; i < (401); ++i)
    for (int j = 0; j < (201); ++j) dp[i][j] = (int)1e9;
  dp[0][0] = 0;
  for (int i = 1; i <= 400; i++) {
    dp[i][0] = 0;
    for (int j = 1; j <= n; j++) {
      dp[i][j] = min(dp[i - 1][j - 1] + abs(i - vals[j - 1]), dp[i - 1][j]);
    }
  }
  cout << dp[400][n] << '\n';
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

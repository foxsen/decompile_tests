#include <bits/stdc++.h>
using namespace std;
const int maxn = 2100;
int cnt[2][maxn][26];
int dp[maxn][maxn];
string s[2];
int solve() {
  int n = s[0].size();
  for (int i = 0; i < (int)(2); ++i)
    for (int j = 0; j < (int)(n + 1); ++j)
      for (int k = 0; k < (int)(26); ++k) cnt[i][j][k] = 0;
  for (int i = 0; i < (int)(2); ++i)
    for (int j = 0; j < (int)(n); ++j)
      for (int k = 0; k < (int)(26); ++k)
        cnt[i][j + 1][k] = cnt[i][j][k] + (s[i][j] == 'a' + k);
  bool ok = true;
  for (int k = 0; k < (int)(26); ++k) ok &= cnt[0][n][k] == cnt[1][n][k];
  if (!ok) return -1;
  for (int i = 0; i < (int)(n + 1); ++i)
    for (int j = 0; j < (int)(n + 1); ++j) dp[i][j] = 0;
  for (int i = 0; i < (int)(n + 1); ++i)
    for (int j = 0; j < (int)(n + 1); ++j) {
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
      if (s[0][i] == s[1][j]) {
        bool ok = true;
        for (int k = 0; k < (int)(26); ++k) ok &= cnt[0][i][k] <= cnt[1][j][k];
        if (ok) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
      }
    }
  return n - dp[n][n];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n >> s[0] >> s[1];
    cout << solve() << '\n';
  }
  return 0;
}

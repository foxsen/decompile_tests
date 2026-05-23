#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 9;
const int Log2 = 23;
const int inf = 1e9 + 7;
vector<int> g[N];
string s;
int T, n, lcp[N][N], dp[N][N];
void Repack() {
  for (int i = 1; i <= n; i++) lcp[i][n + 1] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) dp[i][j] = 0;
  for (int i = 1; i <= n; i++) dp[1][i] = i;
}
void out() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) cout << dp[i][j] << " ";
    cout << "\n";
  }
  exit(0);
}
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
  if (fopen("tst"
            ".INP",
            "r")) {
    freopen(
        "tst"
        ".INP",
        "r", stdin);
  }
  cin >> T;
  while (T--) {
    cin >> n >> s;
    s = " " + s;
    Repack();
    for (int i = n; i > 0; i--) {
      for (int j = i - 1; j > 0; j--) {
        if (s[j] != s[i])
          lcp[j][i] = 1;
        else
          lcp[j][i] = lcp[j + 1][i + 1] + 1;
      }
    }
    for (int i = 2; i <= n; i++) {
      int mn = n + 1;
      for (int j = 1; j <= n; j++) g[j].clear();
      for (int j = i - 1; j > 0; j--) {
        mn = min(mn, lcp[j][i]);
        g[lcp[j][i]].push_back(j);
      }
      for (int j = i; j <= n; j++) dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
      for (int val = 1; val <= n; val++) {
        for (auto prv : g[val]) {
          dp[i][i + val - 1] = max(dp[i][i + val - 1], dp[i][i + val - 2] + 1);
          if (s[i + val - 1] > s[prv + val - 1])
            dp[i][i + val - 1] = max(dp[i][i + val - 1], dp[prv][n] + 1);
        }
      }
      for (int j = i; j <= n; j++) dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) ans = max(ans, dp[i][j]);
    cout << ans << "\n";
  }
}

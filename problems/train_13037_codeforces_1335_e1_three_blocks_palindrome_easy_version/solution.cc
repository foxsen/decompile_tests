#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e3 + 10;
const int mod = 1e9 + 7;
long long n, ans, cnt;
long long dp[N][27];
int b[N];
vector<int> a[27];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    int g = 1;
    ans = 0;
    for (int i = 1; i <= n; i++) memset(dp[i], 0, sizeof(dp[i]));
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      for (int j = 1; j <= 26; j++) dp[i][j] = dp[i - 1][j];
      dp[i][x]++;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= 26; j++) {
        if (dp[i][j] != 0) {
          int ind = 0;
          for (int k = n; k > i; k--)
            if (dp[i][j] == (dp[n][j] - dp[k - 1][j])) {
              ind = k;
              break;
            }
          if (ind != 0) {
            int ma = 0;
            for (int u = 1; u <= 26; u++)
              ma = ma > (dp[ind - 1][u] - dp[i][u])
                       ? ma
                       : (dp[ind - 1][u] - dp[i][u]);
            ans = (ans > dp[i][j] * 2 + ma) ? ans : dp[i][j] * 2 + ma;
          }
        }
      }
    }
    for (int i = 1; i <= 26; i++) ans = ans > dp[n][i] ? ans : dp[n][i];
    cout << ans << endl;
  }
  return 0;
}

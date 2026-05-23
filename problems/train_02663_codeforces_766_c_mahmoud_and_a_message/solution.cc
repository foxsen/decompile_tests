#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
const int MOD = 1e9 + 7;
int sum[MAXN][30], M[MAXN][MAXN], dp[MAXN], maxx[30], dp2[MAXN];
string a;
int main() {
  ios::sync_with_stdio(false);
  int n;
  int i, j, k;
  int ans = 0;
  cin >> n;
  cin >> a;
  for (i = 1; i <= 26; i++) cin >> maxx[i];
  int flag = 1, len = 0;
  for (i = 1; i <= n; i++) {
    for (j = i; j <= n; j++) {
      flag = 1;
      len = j - i + 1;
      for (k = i; k <= j; k++) {
        if (len > maxx[(a[k - 1] - 'a' + 1)]) {
          flag = 0;
          break;
        }
      }
      M[i][j] = flag;
      if (flag) ans = max(len, ans);
    }
  }
  dp[0] = 1;
  memset(dp2, 0x3f, sizeof dp2);
  dp2[0] = 0;
  for (i = 1; i <= n; i++) {
    for (j = i; j >= 1; j--) {
      if (M[j][i]) {
        dp[i] = (dp[i] + dp[j - 1]) % MOD;
        dp2[i] = min(dp2[i], dp2[j - 1] + 1);
      }
    }
  }
  cout << dp[n] << endl << ans << endl << dp2[n] << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353, INF = 2E18 + 5;
const double PI = 2 * acos(0.0);
const long double EPS = 1.0E-14;
string s, t;
int dp[5005][5005];
int rec(int posS, int posT) {
  if (posS == 0 or posT == 0) return 0;
  if (dp[posS][posT] != -1) return dp[posS][posT];
  int ans = 0;
  if (s[posS - 1] == t[posT - 1]) {
    ans = max(ans, rec(posS - 1, posT - 1) + 2);
  } else {
    ans = max(ans, max(rec(posS - 1, posT) - 1, rec(posS, posT - 1) - 1));
  }
  return dp[posS][posT] = ans;
}
int main() {
  int n, m, ans = 0;
  cin >> n >> m >> s >> t;
  memset(dp, -1, sizeof dp);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      ans = max(ans, rec(i, j));
    }
  }
  cout << ans;
  return 0;
}

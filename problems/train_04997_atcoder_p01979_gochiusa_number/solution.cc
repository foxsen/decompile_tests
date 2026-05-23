#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)
typedef long long ll;

ll dp[20][2][1000][2];
int main() {
  string S;
  cin >> S;
  int N = S.size();
  dp[0][0][0][0] = 1;
  rep(i, 0, N) rep(j, 0, 2) rep(k, 0, 1000) rep(l, 0, 2) {
    int x = j ? 9 : S[i] - '0';
    rep(d, 0, x + 1) {
      dp[i + 1][j || d < x][(k % 100) * 10 + d][l || ((k / 10 == 51) && (d == 3))] += dp[i][j][k][l];
    }
  }
  ll ans = 0;
  rep(j, 0, 2) rep(k, 0, 1000) {
    ans += dp[N][j][k][1];
  }
  cout << ans << endl;
  return 0;
}


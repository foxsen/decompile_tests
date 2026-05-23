
#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i < n; i ++)
#define rep1(i, n) for (int i=1; i <= n; i ++)
#define _min(x, y) x = min(x, y)
#define _max(x, y) x = max(x, y)
using namespace std;


vector<vector<long long> > dp(305, vector<long long>(305, 300000000000));
int main() {
  int N, K; cin >> N >> K;
  vector<int> H;
  H.push_back(0);
  dp[0][0] = 0;
  dp[0][1] = 0;
  rep(i, N) {
    int h; cin >> h;
    H.push_back(h);
    dp[i + 1][1] = h;
    dp[i + 1][0] = 0;
  }
  for (int y = 2; y <= N; y ++) {
    rep1(x, N) {
      for (int i = 1; i < x; i ++) {
        _min(dp[x][y], dp[i][y - 1] + max(0, H[x] - H[i]));
      }
    }
  }
  long long ans = 300000000000;
  //rep(i, N + 1) {
  //  rep(j, N + 1) {
  //    cout << dp[i][j] << " " ;
  //  }
  //  cout << endl;
  //}
  rep1(i, N) {
    _min(ans, dp[i][N - K]);
  }
  cout << ans << endl;
  return 0;
}

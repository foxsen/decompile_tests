#include <bits/stdc++.h>
using namespace std;
long long dp[65][65][2];
int b[65];
int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  long long n, t, cnt;
  cin >> n >> t;
  if (__builtin_popcountll(t) > 1) {
    cout << 0;
    return 0;
  }
  cnt = __builtin_ctzll(t) + 1;
  cerr << cnt << endl;
  n++;
  for (int i = 0; i < 64; i++) b[i] = (n >> (63 - i)) & 1;
  dp[0][0][0] = 1;
  for (int i = 0; i < 64; i++)
    for (int c = 0; c < 64; c++) {
      if (b[i]) {
        dp[i + 1][c][1] += dp[i][c][0];
        dp[i + 1][c + 1][0] += dp[i][c][0];
      } else
        dp[i + 1][c][0] += dp[i][c][0];
      dp[i + 1][c + 1][1] += dp[i][c][1];
      dp[i + 1][c][1] += dp[i][c][1];
    }
  cout << dp[64][cnt][0] + dp[64][cnt][1] - (cnt == 1) << endl;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);
  int N;
  cin >> N;
  vector<bool> color(N);
  vector<int> r(N), b(N);
  for (int i = 0; i < N; i++) {
    string t;
    cin >> t >> r[i] >> b[i];
    color[i] = (t == "B");
  }
  int MSAVE = 0;
  for (int i = 0; i < N; i++) MSAVE += i;
  vector<vector<int> > dp(1 << N, vector<int>(MSAVE + 1, -1));
  dp[0][0] = 0;
  for (int m = 0; m < (1 << N); m++) {
    int red = 0, blue = 0;
    for (int i = 0; i < N; i++) {
      if ((m >> i) & 1) {
        if (color[i])
          blue++;
        else
          red++;
      }
    }
    for (int rs = 0; rs <= MSAVE; rs++) {
      if (dp[m][rs] == -1) continue;
      for (int t = 0; t < N; t++) {
        if ((m >> t) & 1) continue;
        int nrs = rs, nbs = dp[m][rs];
        nbs += min(blue, b[t]);
        nrs += min(red, r[t]);
        int &upd = dp[m ^ (1 << t)][nrs];
        upd = max(upd, nbs);
      }
    }
  }
  int blue_need = 0, red_need = 0;
  for (int c : r) red_need += c;
  for (int c : b) blue_need += c;
  int ans = max(blue_need, red_need);
  int fm = (1 << N) - 1;
  for (int rs = 0; rs <= MSAVE; rs++)
    if (dp[fm][rs] != -1) {
      ans = min(ans, max(blue_need - dp[fm][rs], red_need - rs));
    }
  cout << ans + N << endl;
  return 0;
}

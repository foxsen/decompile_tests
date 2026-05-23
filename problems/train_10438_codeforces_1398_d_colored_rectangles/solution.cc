#include <bits/stdc++.h>
using namespace std;
const int mxsz = 202;
const int inf = 1e9 + 1e2;
const int mod = 1e9 + 7;
int nr, ng, nb, r[mxsz], g[mxsz], b[mxsz], dp[mxsz][mxsz][mxsz], mx;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> nr >> ng >> nb;
  for (int i = 1; i <= nr; i++) {
    cin >> r[i];
  }
  for (int i = 1; i <= ng; i++) {
    cin >> g[i];
  }
  for (int i = 1; i <= nb; i++) {
    cin >> b[i];
  }
  sort(r + 1, r + nr + 1, greater<int>());
  sort(g + 1, g + ng + 1, greater<int>());
  sort(b + 1, b + nb + 1, greater<int>());
  for (int i = 0; i <= nr; i++) {
    for (int j = 0; j <= ng; j++) {
      for (int l = 0; l <= nb; l++) {
        if ((!i && !j) || (!i && !l) || (!j && !l)) continue;
        if (!i) {
          dp[i][j][l] = max({dp[i][j][l], dp[i][j - 1][l - 1] + g[j] * b[l]});
          continue;
        }
        if (!j) {
          dp[i][j][l] = max({dp[i][j][l], dp[i - 1][j][l - 1] + r[i] * b[l]});
          continue;
        }
        if (!l) {
          dp[i][j][l] = max({dp[i][j][l], dp[i - 1][j - 1][l] + g[j] * r[i]});
          continue;
        }
        dp[i][j][l] = max({
            dp[i][j][l],
            dp[i - 1][j][l],
            dp[i][j - 1][l],
            dp[i][j][l - 1],
            dp[i - 1][j - 1][l] + r[i] * g[j],
            dp[i - 1][j][l - 1] + r[i] * b[l],
            dp[i][j - 1][l - 1] + g[j] * b[l],
        });
      }
    }
  }
  cout << dp[nr][ng][nb];
}

#include <bits/stdc++.h>
using namespace std;
double dp[1005][1005][2];
int main() {
  int w, b;
  cin >> w >> b;
  for (int i = w; i >= 0; i--)
    for (int j = b; j >= 0; j--) dp[i][j][0] = dp[i][j][1] = 0;
  dp[w][b][0] = 1;
  double ans = 0;
  for (int i = w; i >= 0; i--) {
    for (int j = b; j >= 0; j--) {
      if (i > 0) ans += dp[i][j][0] * i / (i + j);
      if (j > 0) {
        dp[i][j - 1][1] = dp[i][j][0] * j / (i + j);
        if (i > 0)
          dp[i - 1][j - 1][0] += dp[i][j][1] * i * j / ((i + j) * (i + j - 1));
        if (j > 1)
          dp[i][j - 2][0] +=
              dp[i][j][1] * j * (j - 1) / ((i + j) * (i + j - 1));
      }
    }
  }
  printf("%.10lf\n", ans);
  return 0;
}

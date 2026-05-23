#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
int n, T;
int p[maxn], t[maxn];
double dp[maxn][maxn];
double pp, p1, tmp, ans;
int main() {
  while (scanf("%d%d", &n, &T) != EOF) {
    for (int i = 1; i <= n; i++) scanf("%d%d", &p[i], &t[i]);
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    ans = 0;
    for (int i = 1; i <= n; i++) {
      pp = 0.01 * p[i];
      p1 = 1;
      for (int j = 1; j < t[i]; j++) p1 *= 1 - pp;
      for (int j = 1; j <= T; j++) {
        if (j < t[i])
          dp[i][j] = dp[i][j - 1] * (1 - pp) + dp[i - 1][j - 1] * pp;
        else {
          if (j > t[i])
            tmp = dp[i][j - 1] - p1 * dp[i - 1][j - 1 - t[i]];
          else
            tmp = dp[i][j - 1];
          dp[i][j] = tmp * (1 - pp) + dp[i - 1][j - 1] * pp +
                     dp[i - 1][j - t[i]] * p1 * (1 - pp);
        }
        ans += dp[i][j];
      }
    }
    printf("%.7lf\n", ans);
  }
  return 0;
}

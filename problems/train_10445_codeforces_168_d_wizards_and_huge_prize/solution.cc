#include <bits/stdc++.h>
using namespace std;
template <typename T, typename TT>
ostream& operator<<(ostream& s, pair<T, TT> t) {
  return s << "(" << t.first << "," << t.second << ")";
}
template <typename T>
ostream& operator<<(ostream& s, vector<T> t) {
  for (int i = 0; i < t.size(); i++) s << t[i] << " ";
  return s;
}
int s[201], a[201];
double p[201], dp[2][201][410];
const int M = 200;
int main() {
  int i, j, k, m, l, n;
  while (~scanf("%d%d%d", &n, &l, &k)) {
    for (i = 1; i <= n; i++) scanf("%lf", &p[i]), p[i] /= 100.;
    s[0] = k;
    for (i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      if (a[i] != -1)
        s[i] = s[i - 1] + a[i];
      else
        s[i] = s[i - 1];
    }
    k = min(n, k);
    for (i = 0; i <= n + M; i++) dp[0][0][i] = 0;
    dp[0][0][k + M] = 1;
    int now = 0;
    for (i = 1; i <= n; i++, now ^= 1) {
      for (j = 0; j <= i; j++)
        for (int r = -j; r <= n; r++) dp[1 - now][j][r + M] = 0;
      for (j = 0; j <= i - 1; j++)
        for (int r = -j; r <= n; r++)
          if (dp[now][j][r + M] > 0) {
            if (a[i] == -1)
              dp[1 - now][j + 1][r - 1 + M] += dp[now][j][r + M] * p[i];
            else
              dp[1 - now][j + 1][min(r + a[i], n) + M] +=
                  dp[now][j][r + M] * p[i];
            dp[1 - now][j][r + M] += dp[now][j][r + M] * (1 - p[i]);
          }
    }
    double ans = 0;
    for (i = l; i <= n; i++)
      for (j = 0; j <= n; j++) ans += dp[now][i][j + M];
    printf("%lf\n", ans);
  }
}

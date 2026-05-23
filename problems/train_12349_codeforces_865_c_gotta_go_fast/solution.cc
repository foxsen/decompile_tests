#include <bits/stdc++.h>
using namespace std;
int f[55], s[55];
long double p[55];
long double dp[55][5005];
bool vis[55][5005];
int main() {
  int n, r;
  scanf("%d%d", &n, &r);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%Lf", &f[i], &s[i], &p[i]);
    p[i] /= 100;
  }
  long double lo = 0, hi = 1e18, ans = 0;
  for (int i = 0; i < 200; i++) {
    long double mid = (lo + hi) / 2;
    memset(vis, 0, sizeof(vis));
    memset(dp, 0, sizeof(dp));
    vis[n + 1][0] = 1;
    for (int i = n; i >= 1; i--) {
      for (int j = 0; j <= r; j++) {
        long double res = 0;
        if (j >= s[i]) {
          res += (f[i] + dp[i + 1][j - f[i]]) * p[i];
          res += (s[i] + dp[i + 1][j - s[i]]) * (1 - p[i]);
          res = min(res, mid);
          dp[i][j] = res;
          vis[i][j] = 1;
        } else if (j >= f[i]) {
          res += (f[i] + dp[i + 1][j - f[i]]) * p[i];
          res += (s[i] + mid) * (1 - p[i]);
          res = min(res, mid);
          dp[i][j] = res;
          vis[i][j] = 1;
        } else {
          res += (f[i] + mid) * p[i];
          res += (s[i] + mid) * (1 - p[i]);
          res = min(res, mid);
          dp[i][j] = mid;
          vis[i][j] = mid;
        }
      }
    }
    bool ok = 0;
    if (dp[1][r] < mid) ok = 1;
    if (ok)
      ans = mid, hi = mid;
    else
      lo = mid;
  }
  printf("%.20Lf\n", ans);
}

#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, K, p[N];
double odp[N][N], dp[N][N];
int calc(int x) { return x * (x + 1) / 2; }
int main() {
  scanf("%d%d", &n, &K), K = min(K, 1000);
  const int tot = n * (n + 1) / 2;
  for (int i = (1); i <= (n); ++i) scanf("%d", &p[i]);
  for (int i = (1); i <= (n); ++i)
    for (int j = (i + 1); j <= (n); ++j) dp[i][j] = 1;
  for (int _ = (1); _ <= (K); ++_) {
    memcpy(odp, dp, sizeof(odp));
    for (int i = (1); i <= (n); ++i)
      for (int j = (i + 1); j <= (n); ++j) {
        dp[i][j] =
            odp[i][j] * (calc(i - 1) + calc(j - i - 1) + calc(n - j)) / tot;
        for (int k = (1); k <= (j - 1); ++k) {
          dp[i][j] += odp[k][j] * min(min(k, i), min(j - i, j - k)) / tot;
        }
        for (int k = (i + 1); k <= (n); ++k) {
          dp[i][j] += odp[i][k] *
                      min(min(j - i, k - i), min(n - j + 1, n - k + 1)) / tot;
        }
        const int len = j - i + 1;
        for (int k = (1); k <= (n - len + 1); ++k) {
          dp[i][j] += (1. - odp[k][k + len - 1]) *
                      min(min(i, k), min(n - k - len + 1 + 1, n - j + 1)) / tot;
        }
      }
  }
  double ans = 0;
  for (int i = (1); i <= (n); ++i)
    for (int j = (i + 1); j <= (n); ++j)
      if (p[i] > p[j])
        ans += dp[i][j];
      else
        ans += 1 - dp[i][j];
  printf("%.20f\n", ans);
  return 0;
}

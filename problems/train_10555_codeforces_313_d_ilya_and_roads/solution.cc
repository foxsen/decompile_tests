#include <bits/stdc++.h>
using namespace std;
long long dp[310][310];
long long minv[310][310];
const long long INF = 1000000000000000000LL;
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = (0); i <= (n); i++)
    for (int j = (0); j <= (n); j++) minv[i][j] = INF;
  for (int i = (0); i <= (n); i++)
    for (int j = (0); j <= (n); j++) dp[i][j] = INF;
  for (int i = 0; i < (m); i++) {
    int l, r, c;
    scanf("%d%d%d", &l, &r, &c);
    minv[l][r] = min(minv[l][r], (long long)c);
  }
  for (int l = (n); l >= (1); l--) {
    for (int j = (0); j <= (n - l); j++) {
      minv[j + 1][j + l] = min(minv[j][j + l], minv[j + 1][j + l]);
      minv[j][j + l - 1] = min(minv[j][j + l], minv[j][j + l - 1]);
    }
  }
  dp[0][0] = 0;
  for (int i = (0); i <= (n - 1); i++) {
    for (int j = (0); j <= (n); j++) {
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
      for (int k = (i + 1); k <= (n); k++) {
        dp[k][j + k - i] = min(dp[k][j + k - i], dp[i][j] + minv[i + 1][k]);
      }
    }
  }
  long long ans = INF;
  for (int j = (k); j <= (n); j++) ans = min(ans, dp[n][j]);
  if (ans == INF) ans = -1;
  printf("%I64d\n", ans);
}

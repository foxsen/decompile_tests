#include <bits/stdc++.h>
using namespace std;
int n, m, l[55], arr[55][5005], sum[55], pre[55], suf[55], best[55],
    conc[250005];
long long dp[2][2];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", l + i);
    best[i] = pre[i] = suf[i] = -1e9;
    int s = 0;
    for (int j = 0; j < l[i]; ++j) {
      scanf("%d", arr[i] + j);
      sum[i] += arr[i][j];
      pre[i] = max(pre[i], sum[i]);
      best[i] = max(best[i], arr[i][j]);
      if (s + arr[i][j] > 0)
        best[i] = max(best[i], s += arr[i][j]);
      else
        s = 0;
    }
    s = 0;
    for (int j = l[i] - 1; j >= 0; --j) {
      s += arr[i][j];
      suf[i] = max(suf[i], s);
    }
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", conc + i);
    --conc[i];
  }
  dp[m & 1][0] = dp[m & 1][1] = -1e17;
  for (int i = m - 1; i >= 0; --i) {
    dp[i & 1][0] = best[conc[i]];
    dp[i & 1][1] = pre[conc[i]];
    dp[i & 1][0] = max(dp[i & 1][0], dp[!(i & 1)][0]);
    dp[i & 1][0] = max(dp[i & 1][0], dp[!(i & 1)][1] + suf[conc[i]]);
    dp[i & 1][1] = max(dp[i & 1][1], dp[!(i & 1)][1] + sum[conc[i]]);
  }
  printf("%I64d\n", dp[0][0]);
  return 0;
}

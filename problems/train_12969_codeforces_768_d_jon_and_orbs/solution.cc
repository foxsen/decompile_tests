#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
double dp[10005][maxn];
int ans[maxn];
const double eps = 1e-7;
int main() {
  int q, k;
  scanf("%d %d", &k, &q);
  dp[0][0] = 1;
  for (int i = 1; i < 10005; i++) {
    for (int j = 1; j <= k; j++) {
      dp[i][j] += dp[i - 1][j] * double(j) / k;
      dp[i][j] += dp[i - 1][j - 1] * (double(k - j + 1) / k);
    }
  }
  for (int j = 1; j <= 1000; j++) {
    for (int i = 10000; i >= 1; i--) {
      if (2000 * dp[i][k] >= j - eps) ans[j] = i;
    }
  }
  while (q--) {
    int p;
    scanf("%d", &p);
    printf("%d\n", ans[p]);
  }
  return 0;
}

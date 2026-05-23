#include <bits/stdc++.h>
using namespace std;
const int N = 2004;
const int Inf = 1e9 + 7;
int pos[N], x[N], w[N], lt[N], rt[N], umb[N];
long long dp[N][N];
int a, n, m;
long long int dfs(int i, int j) {
  if (i == a + 1) return 0;
  if (dp[i][j] != -1) return dp[i][j];
  long long int res = Inf;
  if (pos[i] == 1) {
    if (j == 0) return Inf;
    res = min(res, dfs(i + 1, 0));
    res = min(res, dfs(i + 1, j) + w[j]);
    res = min(res, dfs(i + 1, umb[i]) + w[umb[i]]);
  } else {
    if (j == 0) {
      res = min(res, dfs(i + 1, 0));
      res = min(res, dfs(i + 1, umb[i]) + w[umb[i]]);
    } else {
      res = min(res, dfs(i + 1, 0));
      res = min(res, dfs(i + 1, j) + w[j]);
      res = min(res, dfs(i + 1, umb[i]) + w[umb[i]]);
    }
  }
  dp[i][j] = res;
  return res;
}
int main() {
  scanf("%d %d %d", &a, &n, &m);
  int i, j;
  memset(dp, -1, sizeof(dp));
  w[0] = 1e9 + 7;
  for (i = 1; i <= n; i++) {
    scanf("%d %d", &lt[i], &rt[i]);
    for (j = lt[i] + 1; j <= rt[i]; j++) pos[j] = 1;
  }
  for (i = 1; i <= m; i++) {
    scanf("%d %d", &x[i], &w[i]);
    if (w[i] < w[umb[x[i]]]) umb[x[i]] = i;
  }
  long long int ans = dfs(0, 0);
  if (ans >= Inf)
    printf("-1\n");
  else
    printf("%I64d\n", ans);
  return 0;
}

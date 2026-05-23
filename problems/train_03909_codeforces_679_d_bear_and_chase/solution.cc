#include <bits/stdc++.h>
using namespace std;
const int N = 402;
int n, m, dp[N][N];
vector<int> g[N];
double p[N], mxD[N];
bool v[N];
double solve(int second) {
  double ret = 1.0 / n;
  for (int d = 1; d <= n; ++d) {
    memset(p, 0, sizeof p);
    memset(v, 0, sizeof v);
    vector<int> cur;
    for (int i = 1; i <= n; ++i)
      if (dp[second][i] == d) {
        for (int j : g[i]) {
          p[j] += 1.0 / n / ((int)(g[i]).size());
          if (!v[j]) v[j] = true, cur.push_back(j);
        }
      }
    if (!((int)(cur).size())) continue;
    double bst = 1.0 / n;
    for (int i = 1; i <= n; ++i) {
      double ans = 0;
      for (int j : cur) mxD[dp[i][j]] = max(mxD[dp[i][j]], p[j]);
      for (int j : cur) ans += mxD[dp[i][j]], mxD[dp[i][j]] = 0;
      bst = max(bst, ans);
    }
    ret += bst;
  }
  return ret;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (i != j) dp[i][j] = 1000000000;
  for (int i = 1; i <= m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
    dp[x][y] = dp[y][x] = 1;
  }
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
  double ans = 0;
  for (int i = 1; i <= n; ++i) ans = max(ans, solve(i));
  printf("%.9f", ans);
}

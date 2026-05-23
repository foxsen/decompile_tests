#include <bits/stdc++.h>
using namespace std;
const int inf = 0xdddddddd, maxn = 2510;
int dp[maxn][maxn][3], pd[maxn][3], pd1[maxn][3][3], pd2[maxn][3][3], sz[maxn],
    p[maxn], dfn[maxn], low[maxn], cnt, n, m, u, v;
vector<int> cyc, e[maxn];
void upd(int &a, int b) {
  if (a <= b) a = b;
}
void cycle(int u, int v) {
  cyc.clear();
  while (1) {
    cyc.push_back(v);
    if (v == u) break;
    v = p[v];
  }
  reverse(cyc.begin(), cyc.end());
  for (int i = 0; i <= sz[u]; i++) {
    for (int p1 = 0; p1 < 3; p1++)
      for (int p2 = 0; p2 < 3; p2++) pd1[i][p1][p2] = inf;
    for (int p1 = 0; p1 < 3; p1++) pd1[i][p1][p1] = dp[u][i][p1];
  }
  for (int l = 1; l < cyc.size(); l++) {
    v = cyc[l];
    for (int i = 0; i < sz[u] + 1; i++)
      for (int p1 = 0; p1 < 3; p1++)
        for (int p2 = 0; p2 < 3; p2++) pd2[i][p1][p2] = pd1[i][p1][p2];
    for (int i = 0; i < sz[u] + sz[v] + 1; i++)
      for (int p1 = 0; p1 < 3; p1++)
        for (int p2 = 0; p2 < 3; p2++) pd1[i][p1][p2] = inf;
    for (int i = 0; i < sz[u] + 1; i++)
      for (int j = 0; j < sz[v] + 1; j++)
        for (int p1 = 0; p1 < 3; p1++) {
          upd(pd1[i + j][p1][0],
              dp[v][j][0] +
                  max(pd2[i][p1][0], max(pd2[i][p1][1], pd2[i][p1][2])));
          upd(pd1[i + j][p1][1],
              dp[v][j][1] + max(pd2[i][p1][0], pd2[i][p1][1]));
          upd(pd1[i + j][p1][2],
              dp[v][j][2] + max(pd2[i][p1][0], pd2[i][p1][2]));
        }
    sz[u] += sz[v];
  }
  for (int i = 0; i < sz[u] + 1; i++) {
    upd(dp[u][i][0], max(pd1[i][0][0], max(pd1[i][0][1], pd1[i][0][2])));
    upd(dp[u][i][1], max(pd1[i][1][0], pd1[i][1][1]));
    upd(dp[u][i][2], max(pd1[i][2][0], pd1[i][2][2]));
  }
}
void dfs(int u, int f) {
  p[u] = f;
  dfn[u] = low[u] = ++cnt;
  sz[u] = 1;
  dp[u][0][0] = 0;
  dp[u][1][1] = 0;
  dp[u][0][2] = 1;
  for (int i = 0; i < e[u].size(); i++) {
    int v = e[u][i];
    if (v == f) continue;
    if (!dfn[v]) {
      dfs(v, u);
      if (low[v] > dfn[u]) {
        for (int p1 = 0; p1 < sz[u] + sz[v] + 1; p1++)
          for (int p2 = 0; p2 < 3; p2++) pd[p1][p2] = inf;
        for (int p1 = 0; p1 < sz[u] + 1; p1++)
          for (int p2 = 0; p2 < sz[v] + 1; p2++) {
            upd(pd[p1 + p2][0],
                dp[u][p1][0] +
                    max(dp[v][p2][0], max(dp[v][p2][1], dp[v][p2][2])));
            upd(pd[p1 + p2][1], dp[u][p1][1] + max(dp[v][p2][0], dp[v][p2][1]));
            upd(pd[p1 + p2][2], dp[u][p1][2] + max(dp[v][p2][0], dp[v][p2][2]));
          }
        sz[u] += sz[v];
        for (int p1 = 0; p1 < sz[u] + 1; p1++)
          for (int p2 = 0; p2 < 3; p2++) dp[u][p1][p2] = pd[p1][p2];
      }
    }
    low[u] = min(low[u], low[v]);
  }
  for (int i = 0; i < e[u].size(); i++) {
    int v = e[u][i];
    if (p[v] != u && dfn[v] > dfn[u]) cycle(u, v);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  memset(dp, 0xdd, sizeof(dp));
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1, 0);
  for (int i = 0; i <= n; i++)
    printf("%d ", max(dp[1][i][0], max(dp[1][i][1], dp[1][i][2])));
  return 0;
}

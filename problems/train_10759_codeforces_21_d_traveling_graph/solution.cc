#include <bits/stdc++.h>
using namespace std;
int n, m, ans, cnt, tot, flag, s;
int dist[20][20], deg[20], mp[20], dp[1 << 16], vis[20];
void solve() {
  int i, j, k, t;
  for (i = 1; i <= n; i++) dist[i][i] = 0;
  for (k = 1; k <= n; k++) {
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  for (i = 1; i <= n; i++) {
    if (vis[i] && dist[1][i] == 0x3f3f3f3f) {
      printf("-1\n");
      return;
    }
  }
  cnt = 0;
  for (i = 1; i <= n; i++) {
    if (deg[i] & 1) {
      mp[cnt] = i;
      cnt++;
    }
  }
  if (cnt == 0) {
    printf("%d\n", tot);
    return;
  }
  s = (1 << cnt) - 1;
  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;
  int x, y;
  for (i = 0; i <= s; i++) {
    for (j = 0; j < cnt; j++) {
      if (i & (1 << j)) continue;
      x = j;
      break;
    }
    for (j = x + 1; j < cnt; j++) {
      if (i & (1 << j)) continue;
      int ss = i;
      ss |= (1 << x);
      ss |= (1 << j);
      dp[ss] = min(dp[ss], dp[i] + dist[mp[x]][mp[j]]);
    }
  }
  if (dp[s] >= 0x3f3f3f3f)
    printf("-1\n");
  else
    printf("%d\n", dp[s] + tot);
}
int main() {
  int i, j, t;
  while (~scanf("%d%d", &n, &m)) {
    memset(dist, 0x3f, sizeof(dist));
    int u, v, w;
    tot = 0;
    memset(deg, 0, sizeof(deg));
    memset(vis, 0, sizeof(vis));
    for (i = 1; i <= m; i++) {
      scanf("%d%d%d", &u, &v, &w);
      tot += w;
      vis[u] = vis[v] = 1;
      if (u == v) continue;
      dist[u][v] = dist[v][u] = min(dist[u][v], w);
      deg[u]++;
      deg[v]++;
    }
    solve();
  }
  return 0;
}

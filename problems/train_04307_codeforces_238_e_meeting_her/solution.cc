#include <bits/stdc++.h>
using namespace std;
inline long long rd() {
  long long _x = 0;
  int _ch = getchar(), _f = 1;
  for (; !isdigit(_ch) && (_ch != '-') && (_ch != EOF); _ch = getchar())
    ;
  if (_ch == '-') {
    _f = 0;
    _ch = getchar();
  }
  for (; isdigit(_ch); _ch = getchar()) _x = _x * 10 + _ch - '0';
  return _f ? _x : -_x;
}
void write(long long _x) {
  if (_x >= 10)
    write(_x / 10), putchar(_x % 10 + '0');
  else
    putchar(_x + '0');
}
inline void wrt(long long _x, char _p) {
  if (_x < 0) putchar('-'), _x = -_x;
  write(_x);
  if (_p) putchar(_p);
}
bool must[105][105];
int G[105][105], f[105][105];
int dp[105], Dp[105];
int n, m, a, b, K;
int dijstra(int s, int t, int x) {
  int dis[105];
  bool vis[105];
  memset(vis, 0, sizeof vis);
  memset(dis, 0x3f, sizeof dis);
  dis[s] = 0;
  vis[x] = 1;
  for (int i = int(1); i <= (int)(n); i++) {
    int p = 0;
    for (int j = int(1); j <= (int)(n); j++)
      if (!vis[j] && dis[j] < dis[p]) p = j;
    if (p == 0) return dis[t];
    vis[p] = 1;
    for (int j = int(1); j <= (int)(n); j++)
      if (G[p][j] && dis[p] + 1 < dis[j]) dis[j] = dis[p] + 1;
  }
  return dis[t];
}
pair<int, int> ride[105];
bool vis[105];
int dfs(int u, int k) {
  if (vis[u]) return Dp[u];
  vis[u] = 0;
  int tmp = -1;
  for (int i = int(1); i <= (int)(n); i++)
    if (f[u][i] == 1 && f[u][ride[k].second] == f[i][ride[k].second] + 1) {
      tmp = max(tmp, dfs(i, k));
    }
  if (tmp == -1) tmp = 1e9;
  tmp = min(tmp, dp[u]);
  return Dp[u] = tmp;
}
int main() {
  n = rd(), m = rd(), a = rd(), b = rd();
  memset(G, 0, sizeof G);
  memset(f, 0x3f, sizeof f);
  for (int i = int(1); i <= (int)(m); i++) {
    int x = rd(), y = rd();
    G[x][y] = f[x][y] = 1;
  }
  for (int k = int(1); k <= (int)(n); k++)
    for (int i = int(1); i <= (int)(n); i++)
      for (int j = int(1); j <= (int)(n); j++)
        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
  for (int i = int(1); i <= (int)(n); i++) f[i][i] = 0;
  K = rd();
  for (int i = int(1); i <= (int)(K); i++) {
    int x = rd(), y = rd();
    ride[i] = make_pair(x, y);
    if (f[x][y] == 1061109567) continue;
    for (int j = int(1); j <= (int)(n); j++)
      if (j != x && j != y) must[i][j] = (dijstra(x, y, j) != f[x][y]);
    must[i][x] = 1;
    must[i][y] = 1;
  }
  memset(dp, 0x3f, sizeof dp);
  memset(Dp, 0x3f, sizeof Dp);
  dp[b] = 0;
  Dp[b] = 0;
  while (1) {
    bool flag = 0;
    for (int i = int(1); i <= (int)(K); i++) {
      for (int j = int(1); j <= (int)(n); j++)
        if (must[i][j]) {
          memset(vis, 0, sizeof vis);
          int tmp = dfs(j, i) + 1;
          if (tmp < dp[j]) dp[j] = tmp, flag = 1;
        }
    }
    if (!flag) break;
  }
  wrt(dp[a] >= 1000000000 ? -1 : dp[a], '\n');
}

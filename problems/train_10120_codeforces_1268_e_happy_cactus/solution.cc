#include <bits/stdc++.h>
using namespace std;
void read(int &x) {
  char ch = getchar();
  x = 0;
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
}
const int N = 5e5 + 5, M = N << 1;
int n, m, num, dfn[N], fa[N], up[N], dp[N], f[N];
int cnt, c, mx[N], mn[N], q[M], in[N], k[N];
struct edge {
  int x, y;
} e[N];
vector<edge> g[N];
void yxlove() {
  int x = 0, y = 0;
  mx[++cnt] = 0, mn[cnt] = 1e9;
  for (int i = 1, o; i <= c; ++i) {
    in[o = q[i]] = cnt;
    if (o > mx[cnt]) mx[cnt] = o, y = i;
    if (o < mn[cnt]) mn[cnt] = o, x = i;
  }
  for (int i = 1; i <= c; ++i) q[c + i] = q[i];
  int tx = x, ty = y;
  if (tx > ty) ty += c;
  k[cnt] = 1;
  for (int i = tx; i < ty; ++i)
    if (q[i] > q[i + 1]) k[cnt] = 0;
  tx = x, ty = y;
  if (tx < ty) tx += c;
  for (int i = tx; i > ty; --i)
    if (q[i] > q[i - 1]) k[cnt] = 0;
}
void dfs(int u) {
  dfn[u] = ++num;
  dp[u] = 1;
  for (edge i : g[u])
    if (i.x != fa[u]) {
      int v = i.x, w = i.y;
      if (!dfn[v])
        fa[v] = u, up[v] = w, dfs(v);
      else if (dfn[v] < 0) {
        c = 0;
        for (int t = v; t != u; t = fa[t]) q[++c] = up[t];
        q[++c] = w;
        yxlove();
      }
    }
  dfn[u] = -1;
}
signed main() {
  read(n), read(m);
  for (int i = 1, u, v; i <= m; ++i) {
    read(u), read(v);
    e[i] = {u, v};
    g[u].push_back({v, i}), g[v].push_back({u, i});
  }
  dfs(1);
  for (int i = m, x, y; i >= 1; --i) {
    f[i] = dp[x = e[i].x] + dp[y = e[i].y];
    if (k[in[i]] && i == mn[in[i]]) f[i] -= f[mx[in[i]]];
    dp[x] = dp[y] = f[i];
  }
  for (int i = 1; i <= n; ++i) printf("%d ", dp[i] - 1);
  return 0;
}

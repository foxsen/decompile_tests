#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = 4e5 + 5;
int n, m, a[N], fa[N], siz[N], f[N][22], w[N][22], dep[N], lca[N], mx[N],
    val[N];
struct edge {
  int x, y, c, z;
} e[N];
struct query {
  int x, z, id;
} q[N];
vector<pair<int, int> > G[N];
pair<int, int> ans[N];
int getf(int x) { return fa[x] == x ? x : fa[x] = getf(fa[x]); }
void dfs(int u, int prt) {
  dep[u] = dep[prt] + 1;
  for (int i = 1; i <= 18; i++) f[u][i] = f[f[u][i - 1]][i - 1];
  for (int i = 1; i <= 18; i++)
    w[u][i] = max(w[u][i - 1], w[f[u][i - 1]][i - 1]);
  for (auto p : G[u])
    if (p.first != prt && getf(p.first) == getf(u))
      f[p.first][0] = u, w[p.first][0] = p.second, dfs(p.first, u);
}
pair<int, int> LCA(int x, int y) {
  if (x == 0) return {y, 0};
  if (y == 0) return {x, 0};
  if (dep[x] < dep[y]) swap(x, y);
  int res = 0;
  for (int i = 18; i >= 0; i--)
    if (f[x][i] && dep[f[x][i]] >= dep[y]) res = max(res, w[x][i]), x = f[x][i];
  if (x == y) return {x, res};
  for (int i = 18; i >= 0; i--)
    if (f[x][i] != f[y][i])
      res = max({res, w[x][i], w[y][i]}), x = f[x][i], y = f[y][i];
  return {f[x][0], max({res, w[x][0], w[y][0]})};
}
void merge(int x, int y, int z) {
  int fx = getf(x), fy = getf(y);
  if (fx == fy) return;
  if (siz[fx] > siz[fy]) swap(x, y), swap(fx, fy);
  siz[fy] += siz[fx], fa[fx] = fy;
  f[x][0] = y, w[x][0] = z, dfs(x, y);
  auto p = LCA(lca[fx], lca[fy]);
  if (mx[fy] < mx[fx])
    lca[fy] = lca[fx], val[fy] = val[fx], mx[fy] = mx[fx];
  else if (mx[fy] > mx[fx])
    ;
  else
    val[fy] = max({val[fy], val[fx], LCA(p.first, lca[fx]).second,
                   LCA(p.first, lca[fy]).second}),
    lca[fy] = p.first;
}
pair<int, int> ask(int x) {
  pair<int, int> res;
  res.first = mx[getf(x)];
  res.second = max(val[getf(x)], LCA(lca[getf(x)], x).second);
  auto qwer = LCA(lca[getf(x)], x);
  return res;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i < n; i++)
    scanf("%d%d%d%d", &e[i].x, &e[i].y, &e[i].c, &e[i].z);
  for (int i = 1; i < n; i++) {
    G[e[i].x].push_back({e[i].y, e[i].z});
    G[e[i].y].push_back({e[i].x, e[i].z});
  }
  for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1, lca[i] = i, mx[i] = a[i];
  sort(e + 1, e + n, [&](edge a, edge b) { return a.c > b.c; });
  for (int i = 1; i <= m; i++) scanf("%d%d", &q[i].z, &q[i].x), q[i].id = i;
  sort(q + 1, q + 1 + m, [&](query a, query b) { return a.z > b.z; });
  int j = 0;
  for (int i = 1, lst = 0; i < n; i++) {
    if (e[i].c != lst) {
      while (j + 1 <= m && q[j + 1].z > e[i].c)
        ans[q[j + 1].id] = ask(q[j + 1].x), j++;
      lst = e[i].c;
    }
    merge(e[i].x, e[i].y, e[i].z);
  }
  while (j + 1 <= m) ans[q[j + 1].id] = ask(q[j + 1].x), j++;
  for (int i = 1; i <= m; i++) printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, m, q, t, tt, a[N], dfn[N], r[N], dep[N], fa[N][25], f[N][25], qq[N][2],
    rt[N], s[N * 20], ls[N * 20], rs[N * 20], ans[N], ff[N];
pair<int, int> e[N];
vector<int> g[N];
void dfs1(int x, int p) {
  dfn[x] = ++t;
  fa[x][0] = p;
  dep[x] = dep[p] + 1;
  for (int i = 0; i < g[x].size(); i++) dfs1(g[x][i], x);
  r[x] = t;
}
void dfs2(int x) {
  for (int i = 0; i < g[x].size(); i++) {
    dfs2(g[x][i]);
    f[x][0] = (dep[f[g[x][i]][0]] > dep[f[x][0]] ? f[x][0] : f[g[x][i]][0]);
  }
}
int lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  int sub = dep[x] - dep[y];
  for (int i = 0; i <= 20; i++)
    if (sub & (1 << i)) x = fa[x][i];
  if (x == y) return x;
  for (int i = 20; i >= 0; i--)
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  return fa[x][0];
}
int gtdis(int x, int y, int id, int kd) {
  int s = 0;
  for (int i = 20; i >= 0; i--)
    if (dep[f[x][i]] > dep[y]) s |= (1 << i), x = f[x][i];
  qq[id][kd] = x;
  return s;
}
bool cmp(pair<int, int> a, pair<int, int> b) {
  return dfn[a.first] < dfn[b.first];
}
void ins(int &x, int y, int l, int r, int p) {
  x = ++tt;
  s[x] = s[y] + 1;
  if (l == r) return;
  int md = l + r >> 1;
  if (p <= md)
    rs[x] = rs[y], ins(ls[x], ls[y], l, md, p);
  else
    ls[x] = ls[y], ins(rs[x], rs[y], md + 1, r, p);
}
int qry(int x, int y, int l, int r, int tl, int tr) {
  if (tl <= l && r <= tr) return s[y] - s[x];
  int md = l + r >> 1, res = 0;
  if (tl <= md) res += qry(ls[x], ls[y], l, md, tl, tr);
  if (tr > md) res += qry(rs[x], rs[y], md + 1, r, tl, tr);
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 2, p; i <= n; i++) {
    scanf("%d", &p);
    g[p].push_back(i);
  }
  dfs1(1, 0);
  for (int i = 1; i <= 20; i++)
    for (int j = 1; j <= n; j++) fa[j][i] = fa[fa[j][i - 1]][i - 1];
  for (int i = 1; i <= n; i++) f[i][0] = i;
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    int t = lca(u, v);
    e[i] = make_pair(u, v);
    if (dep[f[u][0]] > dep[t]) f[u][0] = t;
    if (dep[f[v][0]] > dep[t]) f[v][0] = t;
  }
  dfs2(1);
  for (int i = 1; i <= 20; i++)
    for (int j = 1; j <= n; j++) f[j][i] = f[f[j][i - 1]][i - 1];
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    int t = lca(u, v);
    if (dep[f[u][20]] > dep[t] || dep[f[v][20]] > dep[t])
      ans[i] = -1;
    else {
      if (u == t)
        ff[i] = 1, ans[i] = gtdis(v, t, i, 0) + 1;
      else if (v == t)
        ff[i] = 1, ans[i] = gtdis(u, t, i, 0) + 1;
      else
        ans[i] = gtdis(u, t, i, 0) + gtdis(v, t, i, 1) + 1;
    }
  }
  sort(e + 1, e + m + 1, cmp);
  for (int i = 1; i <= m; i++) a[i] = dfn[e[i].first];
  for (int i = 1; i <= m; i++) ins(rt[i], rt[i - 1], 1, n, dfn[e[i].second]);
  for (int i = 1; i <= q; i++) {
    if (ans[i] == -1 || ff[i] == 1) continue;
    int pl = lower_bound(a + 1, a + m + 1, dfn[qq[i][0]]) - a - 1;
    int pr = lower_bound(a + 1, a + m + 1, r[qq[i][0]] + 1) - a - 1;
    int res1 = qry(rt[pl], rt[pr], 1, n, dfn[qq[i][1]], r[qq[i][1]]);
    pl = lower_bound(a + 1, a + m + 1, dfn[qq[i][1]]) - a - 1;
    pr = lower_bound(a + 1, a + m + 1, r[qq[i][1]] + 1) - a - 1;
    int res2 = qry(rt[pl], rt[pr], 1, n, dfn[qq[i][0]], r[qq[i][0]]);
    if (res1 == 0 && res2 == 0) ans[i]++;
  }
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, M = 110;
struct node {
  int u, v, id;
  string s;
};
int n, Q, tot, cnt, m, hd[N], fa[N][20], dep[N], ans[N], v[N << 1], nxt[N << 1],
    rt[N], sum[N * 50], lc[N * 50], rc[N * 50];
unsigned long long val[N][M], nv[N], dv[M], rv[M];
char c[N << 1];
string str;
vector<node> q[M];
vector<unsigned long long> h;
void add(int x, int y, char z) {
  v[++tot] = y, nxt[tot] = hd[x], c[tot] = z, hd[x] = tot;
}
void dfs(int u, int f) {
  dep[u] = dep[f] + 1, fa[u][0] = f;
  for (int i = 2, j = f; i <= 100; ++i, j = fa[j][0])
    val[u][i] = val[u][i - 1] * 233 + val[j][1];
  for (int i = 1; i < 20 && fa[u][i - 1]; ++i)
    fa[u][i] = fa[fa[u][i - 1]][i - 1];
  for (int i = hd[u]; i; i = nxt[i])
    if (v[i] != f) val[v[i]][1] = c[i] - 'a', dfs(v[i], u);
}
int lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = 19; ~i; --i)
    if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
  if (x == y) return x;
  for (int i = 19; ~i; --i)
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  return fa[x][0];
}
int up(int x, int k) {
  for (int i = 19; ~i; --i)
    if ((k >> i) & 1) x = fa[x][i];
  return x;
}
void update(int& x, int y, int k, int l, int r) {
  x = ++cnt, lc[x] = lc[y], rc[x] = rc[y], sum[x] = sum[y] + 1;
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (k <= mid)
    update(lc[x], lc[y], k, l, mid);
  else
    update(rc[x], rc[y], k, mid + 1, r);
}
int query(int k, int x, int y, int l, int r) {
  if (l == r) return sum[x] - sum[y];
  int mid = (l + r) >> 1;
  if (k <= mid) return query(k, lc[x], lc[y], l, mid);
  return query(k, rc[x], rc[y], mid + 1, r);
}
int solve(node pos) {
  int ret = 0, z = lca(pos.u, pos.v), l = pos.s.size();
  dv[0] = 0;
  for (int i = 0; i < l; ++i) dv[i + 1] = dv[i] * 233 + pos.s[i] - 'a';
  rv[0] = 0;
  for (int i = 0; i < l; ++i) rv[i + 1] = rv[i] * 233 + pos.s[l - i - 1] - 'a';
  if (dep[pos.u] - dep[z] >= l) {
    int v = lower_bound(h.begin(), h.end(), dv[l]) - h.begin() + 1;
    if (v <= m && dv[l] == h[v - 1])
      ret +=
          query(v, rt[pos.u], rt[up(pos.u, dep[pos.u] - dep[z] - l + 1)], 1, m);
  }
  if (dep[pos.v] - dep[z] >= l) {
    int v = lower_bound(h.begin(), h.end(), rv[l]) - h.begin() + 1;
    if (v <= m && rv[l] == h[v - 1])
      ret +=
          query(v, rt[pos.v], rt[up(pos.v, dep[pos.v] - dep[z] - l + 1)], 1, m);
  }
  for (int i = up(pos.u, max(0, dep[pos.u] - dep[z] - l + 1)); i != z;
       i = fa[i][0])
    if (dep[pos.v] - dep[z] - l + dep[i] - dep[z] >= 0) {
      int j = up(pos.v, dep[pos.v] - dep[z] - l + dep[i] - dep[z]);
      if (val[i][dep[i] - dep[z]] == dv[dep[i] - dep[z]] &&
          val[j][dep[j] - dep[z]] == rv[dep[j] - dep[z]])
        ++ret;
    }
  return ret;
}
void modify(int u) {
  update(rt[u], rt[fa[u][0]], nv[u], 1, m);
  for (int i = hd[u]; i; i = nxt[i])
    if (v[i] != fa[u][0]) modify(v[i]);
}
int main() {
  scanf("%d", &n);
  char z;
  for (int i = 1, x, y; i < n; ++i)
    scanf("%d%d %c", &x, &y, &z), add(x, y, z), add(y, x, z);
  dfs(1, 0);
  scanf("%d", &Q);
  for (int i = 1, x, y; i <= Q; ++i)
    cin >> x >> y >> str, q[str.size()].push_back((node){x, y, i, str});
  for (int i = 1; i <= 100; ++i)
    if (q[i].size()) {
      h.clear(), cnt = 1;
      for (int j = 1; j <= n; ++j) h.push_back(val[j][i]);
      sort(h.begin(), h.end());
      h.erase(unique(h.begin(), h.end()), h.end());
      for (int j = 1; j <= n; ++j)
        nv[j] = lower_bound(h.begin(), h.end(), val[j][i]) - h.begin() + 1;
      m = h.size();
      modify(1);
      for (int j = 0; j < q[i].size(); ++j) ans[q[i][j].id] = solve(q[i][j]);
    }
  for (int i = 1; i <= Q; ++i) printf("%d\n", ans[i]);
}

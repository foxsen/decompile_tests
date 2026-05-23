#include <bits/stdc++.h>
const int N = 100050;
long long addv[N * 4], sumv[N * 4];
inline void upd(int o, int l, int r) {
  if (l != r)
    sumv[o] = sumv[o << 1] + sumv[o << 1 | 1] + addv[o] * (r - l + 1);
  else
    sumv[o] = addv[o];
}
void add(int o, int l, int r, int L, int R, int x) {
  if (r < L || R < l) return;
  if (L <= l && r <= R) {
    addv[o] += x;
  } else {
    int mid = (l + r) >> 1;
    add(o << 1, l, mid, L, R, x);
    add(o << 1 | 1, mid + 1, r, L, R, x);
  }
  upd(o, l, r);
}
long long query(int o, int l, int r, int L, int R) {
  if (r < L || R < l) return 0;
  if (L <= l && r <= R) return sumv[o];
  int mid = (l + r) >> 1;
  return addv[o] * (std::min(r, R) - std::max(l, L) + 1) +
         query(o << 1, l, mid, L, R) + query(o << 1 | 1, mid + 1, r, L, R);
}
int n, q;
int pre[N], to[N * 2], nxt[N * 2], cnt;
inline void addEdge(int x, int y) {
  nxt[cnt] = pre[x];
  to[pre[x] = cnt++] = y;
}
int left[N], right[N], cnt2;
int a[N], root;
int fa[N][20], dep[N];
void dfs(int x, int f) {
  dep[x] = dep[f] + 1;
  fa[x][0] = f;
  for (int i = 0; fa[x][i]; ++i) fa[x][i + 1] = fa[fa[x][i]][i];
  left[x] = ++cnt2;
  add(1, 1, n, left[x], left[x], a[x]);
  for (int i = pre[x]; ~i; i = nxt[i])
    if (to[i] != f) dfs(to[i], x);
  right[x] = cnt2;
}
int LCA(int x, int y) {
  if (dep[x] < dep[y]) std::swap(x, y);
  for (int i = 19; ~i; --i)
    if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
  for (int i = 19; ~i; --i)
    if (fa[x][i] != fa[y][i]) {
      x = fa[x][i];
      y = fa[y][i];
    }
  return x == y ? x : fa[x][0];
}
void addS(int u, int v, int x) {
  int l1 = LCA(u, v), l2 = LCA(u, root), l3 = LCA(v, root);
  if (dep[l1] > std::max(dep[l3], dep[l2]))
    add(1, 1, n, left[l1], right[l1], x);
  else {
    add(1, 1, n, 1, n, x);
    if (l2 != root && l3 != root) {
      int t = root;
      for (int i = 19; ~i; --i)
        if (dep[fa[t][i]] > std::max(dep[l2], dep[l3])) t = fa[t][i];
      add(1, 1, n, left[t], right[t], -x);
    }
  }
}
long long queryS(int u) {
  if (u == root) return query(1, 1, n, 1, n);
  if (LCA(u, root) == u) {
    int t = root;
    for (int i = 19; ~i; --i)
      if (dep[fa[t][i]] > dep[u]) t = fa[t][i];
    return query(1, 1, n, 1, n) - query(1, 1, n, left[t], right[t]);
  }
  return query(1, 1, n, left[u], right[u]);
}
int main() {
  scanf("%d%d", &n, &q);
  memset(pre, -1, sizeof pre);
  int x, y;
  cnt = cnt2 = 0;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i < n; ++i) {
    scanf("%d%d", &x, &y);
    addEdge(x, y);
    addEdge(y, x);
  }
  dfs(root = 1, 0);
  int op, u, v;
  while (q--) {
    scanf("%d%d", &op, &u);
    if (op == 1)
      root = u;
    else if (op == 2) {
      scanf("%d%d", &v, &x);
      addS(u, v, x);
    } else
      printf("%I64d\n", queryS(u));
  }
  return 0;
}

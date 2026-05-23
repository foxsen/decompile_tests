#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int D = 25;
struct Edge {
  int u, v, w, nex;
} edges[N];
int head[N], etot;
void addEdge(int u, int v, int w) {
  edges[++etot] = Edge{u, v, w, head[u]};
  head[u] = etot;
}
int dep[N], L[N], R[N], id[N];
long long dis[N];
int rt[N][D];
int dfs_clock;
int a[N], nd[N << 1];
int n, q;
void DFS(int u, int fa) {
  L[u] = ++dfs_clock;
  id[dfs_clock] = u;
  rt[u][0] = fa;
  for (int i = head[u]; i; i = edges[i].nex) {
    Edge &e = edges[i];
    if (e.v == fa) continue;
    dep[e.v] = dep[u] + 1;
    dis[e.v] = dis[u] + e.w;
    DFS(e.v, u);
  }
  R[u] = dfs_clock;
}
void initLCA() {
  for (int j = 1; j < D; ++j) {
    for (int i = 1; i <= n; ++i) {
      rt[i][j] = !rt[i][j - 1] ? 0 : rt[rt[i][j - 1]][j - 1];
    }
  }
}
int LCA(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = 0; i < D; ++i) {
    if ((dep[u] - dep[v]) >> i & 1) u = rt[u][i];
  }
  if (u == v) return u;
  for (int i = D - 1; i >= 0; --i) {
    if (rt[u][i] != rt[v][i]) {
      u = rt[u][i];
      v = rt[v][i];
    }
  }
  return rt[u][0];
}
long long v[N << 2], tag[N << 2];
void up(int o) { v[o] = min(v[o << 1], v[o << 1 | 1]); }
void build(int o, int l, int r) {
  if (l == r) {
    v[o] = dis[id[l]] + a[id[l]];
    return;
  }
  int mid = l + r >> 1;
  build(o << 1, l, mid);
  build(o << 1 | 1, mid + 1, r);
  up(o);
}
void down(int o) {
  if (tag[o]) {
    tag[o << 1] += tag[o];
    v[o << 1] += tag[o];
    tag[o << 1 | 1] += tag[o];
    v[o << 1 | 1] += tag[o];
    tag[o] = 0;
  }
}
int ql, qr;
void modify(int o, int l, int r, long long x) {
  if (ql > r || qr < l) return;
  if (ql <= l && r <= qr) {
    tag[o] += x;
    v[o] += x;
    return;
  }
  down(o);
  int mid = l + r >> 1;
  modify(o << 1, l, mid, x);
  modify(o << 1 | 1, mid + 1, r, x);
  up(o);
}
long long query(int o, int l, int r) {
  if (ql <= l && r <= qr) return v[o];
  down(o);
  int mid = l + r >> 1;
  long long ret = (long long)1e18;
  if (ql <= mid) ret = min(ret, query(o << 1, l, mid));
  if (qr > mid) ret = min(ret, query(o << 1 | 1, mid + 1, r));
  return ret;
}
void update(int i, int w) {
  Edge &e = edges[i];
  ql = qr = L[e.u];
  long long du = query(1, 1, n) - a[e.u];
  ql = qr = L[e.v];
  long long dv = query(1, 1, n) - a[e.v];
  qr = R[e.v];
  modify(1, 1, n, w - (dv - du));
}
long long ask(int u, int v) {
  if (u == v) return 0;
  int lca = LCA(u, v);
  ql = qr = L[v];
  long long dv = query(1, 1, n) - a[v];
  ql = qr = L[u];
  long long du = query(1, 1, n) - a[u];
  if (u == lca) {
    return dv - du;
  } else {
    ql = L[u];
    qr = R[u];
    long long t = query(1, 1, n);
    return t - du + dv;
  }
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i < n; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    addEdge(u, v, w);
  }
  for (int i = n; i < 2 * n - 1; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    a[u] = w;
    nd[i] = u;
  }
  DFS(1, 0);
  initLCA();
  build(1, 1, n);
  for (int i = 1; i <= q; ++i) {
    int op, x, y;
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1) {
      if (x >= n) {
        ql = qr = L[nd[x]];
        modify(1, 1, n, y - a[nd[x]]);
        a[nd[x]] = y;
      } else
        update(x, y);
    } else {
      printf("%I64d\n", ask(x, y));
    }
  }
  return 0;
}

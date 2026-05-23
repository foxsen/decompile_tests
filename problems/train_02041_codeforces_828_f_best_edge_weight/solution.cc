#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 10;
struct Edge {
  int u, v, cost, idx;
  bool operator<(const Edge& rhs) const { return cost < rhs.cost; }
} ed[MAX_N];
inline bool cmp_idx(const Edge& lhs, const Edge& rhs) {
  return lhs.idx < rhs.idx;
}
map<pair<int, int>, int> ID;
int ver[MAX_N][19], maxCost[MAX_N][19], dep[MAX_N];
int par[MAX_N], _rank[MAX_N];
int n, m, ans[MAX_N];
bool inMST[MAX_N];
vector<pair<int, int> > g[MAX_N];
inline void init(int n) {
  for (int i = 1; i <= n; i++) {
    par[i] = i;
    _rank[i] = 0;
  }
}
int find(int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}
inline void unite(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  if (_rank[x] < _rank[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if (_rank[x] == _rank[y]) _rank[x]++;
  }
}
inline bool same(int x, int y) { return find(x) == find(y); }
void dfs(int u, int fa, int d) {
  dep[u] = d;
  for (pair<int, int>& e : g[u]) {
    int v = e.first, cost = e.second;
    if (v != fa) {
      ver[v][0] = u;
      maxCost[v][0] = cost;
      dfs(v, u, d + 1);
    }
  }
}
void initLca() {
  memset(ver, -1, sizeof ver);
  memset(maxCost, 0x8f, sizeof maxCost);
  dfs(1, -1, 1);
  for (int k = 1; k < 19; k++) {
    for (int v = 1; v <= n; v++) {
      if (ver[v][k - 1] != -1 && ver[ver[v][k - 1]][k - 1] != -1) {
        maxCost[v][k] = max(maxCost[v][k - 1], maxCost[ver[v][k - 1]][k - 1]);
        ver[v][k] = ver[ver[v][k - 1]][k - 1];
      }
    }
  }
}
pair<int, int> find_lca(int u, int v) {
  if (dep[u] > dep[v]) swap(u, v);
  int res = -0x7fffffff;
  for (int k = 18; k >= 0; k--) {
    if (ver[v][k] != -1 && dep[ver[v][k]] >= dep[u]) {
      res = max(res, maxCost[v][k]);
      v = ver[v][k];
    }
  }
  if (u == v) return pair<int, int>(res, v);
  for (int k = 18; k >= 0; k--) {
    if (ver[v][k] != ver[u][k]) {
      res = max(res, max(maxCost[v][k], maxCost[u][k]));
      v = ver[v][k];
      u = ver[u][k];
    }
  }
  res = max(res, max(maxCost[v][0], maxCost[u][0]));
  return pair<int, int>(res, ver[v][0]);
}
void modify(int u, int v, int w) {
  v = find(v);
  while (dep[u] < dep[v]) {
    int fa = ver[v][0], id = ID[pair<int, int>(fa, v)];
    ans[id] = min(ans[id], w);
    par[v] = find(fa);
    v = find(v);
  }
}
int main() {
  int u, v, c;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &u, &v, &c);
    ed[i] = (Edge){u, v, c, i};
    ID[pair<int, int>(u, v)] = i;
    ID[pair<int, int>(v, u)] = i;
    ans[i] = 0x7fffffff;
  }
  sort(ed, ed + m);
  init(n);
  for (int i = 0; i < m; i++) {
    Edge& e = ed[i];
    if (!same(e.u, e.v)) {
      unite(e.u, e.v);
      g[e.u].push_back(pair<int, int>(e.v, e.cost));
      g[e.v].push_back(pair<int, int>(e.u, e.cost));
      inMST[i] = true;
    }
  }
  initLca();
  init(n);
  for (int i = 0; i < m; i++) {
    if (inMST[i]) continue;
    Edge& e = ed[i];
    pair<int, int> lca = find_lca(e.u, e.v);
    ans[e.idx] = min(ans[e.idx], lca.first - 1);
    modify(lca.second, e.u, e.cost - 1);
    modify(lca.second, e.v, e.cost - 1);
  }
  for (int i = 0; i < m; i++) {
    if (ans[i] == 0x7fffffff) ans[i] = -1;
    printf("%d ", ans[i]);
  }
  puts("");
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2e5 + 5;
const int INF = 1e9 + 5;
class edge {
 public:
  int u, v, c, id;
  void read(int i) {
    scanf("%d%d%d", &u, &v, &c);
    id = i;
  }
  bool operator<(const edge& o) const { return c < o.c; }
};
int n, m;
edge e[Maxn];
int ans[Maxn];
int pa[Maxn];
int dep[Maxn];
int maxw[Maxn][19];
int ancs[Maxn][19];
bool marked[Maxn];
int up[Maxn];
int minw[Maxn];
vector<pair<int, int> > adj[Maxn];
bool used[Maxn];
int find(int x) { return (x == pa[x]) ? x : pa[x] = find(pa[x]); }
bool uni(edge edg) {
  int a = find(edg.u), b = find(edg.v);
  if (a == b) return false;
  pa[b] = a;
  return true;
}
void mst() {
  sort(e + 1, e + m + 1);
  for (int i = 1; i <= m; i++) {
    if (uni(e[i])) {
      adj[e[i].u].push_back(pair<int, int>(e[i].v, e[i].c));
      adj[e[i].v].push_back(pair<int, int>(e[i].u, e[i].c));
      used[i] = true;
    }
  }
}
void dfs(int now, int pre = -1) {
  for (auto v : adj[now]) {
    if (v.first != pre) {
      dep[v.first] = dep[now] + 1;
      ancs[v.first][0] = now;
      maxw[v.first][0] = v.second;
      for (int i = 1; i <= 18; i++) {
        ancs[v.first][i] = ancs[ancs[v.first][i - 1]][i - 1];
        maxw[v.first][i] =
            max(maxw[v.first][i - 1], maxw[ancs[v.first][i - 1]][i - 1]);
      }
      up[v.first] = now;
      dfs(v.first, now);
    }
  }
}
void build() {
  dep[1] = 0;
  for (int i = 0; i <= 18; i++) {
    ancs[1][i] = 1;
    maxw[1][i] = 0;
  }
  dfs(1);
  memset(minw, 0, sizeof minw);
  memset(marked, 0, sizeof marked);
}
int mark(int src, int dst, int wgt) {
  if (dep[src] <= dep[dst]) return src;
  if (!marked[src]) {
    marked[src] = true;
    minw[src] = wgt;
  }
  return up[src] = mark(up[src], dst, wgt);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) pa[i] = i;
  for (int i = 1; i <= m; i++) {
    e[i].read(i);
  }
  mst();
  build();
  for (int i = 1; i <= m; i++) {
    if (!used[i]) {
      int u = e[i].u, v = e[i].v;
      if (dep[u] < dep[v]) swap(u, v);
      int w = 0;
      for (int i = 18; i >= 0; i--) {
        if ((1 << i) <= dep[u] - dep[v]) {
          w = max(w, maxw[u][i]);
          u = ancs[u][i];
        }
      }
      for (int i = 18; i >= 0; i--) {
        if (ancs[u][i] != ancs[v][i]) {
          w = max(w, maxw[u][i]);
          w = max(w, maxw[v][i]);
          u = ancs[u][i];
          v = ancs[v][i];
        }
      }
      int lca = u;
      if (u != v) {
        w = max(w, maxw[u][0]);
        w = max(w, maxw[v][0]);
        lca = ancs[u][0];
      }
      ans[e[i].id] = w - 1;
      u = e[i].u;
      v = e[i].v;
      mark(u, lca, e[i].c);
      mark(v, lca, e[i].c);
    }
  }
  for (int i = 1; i <= m; i++) {
    if (used[i]) {
      int u = e[i].u, v = e[i].v;
      if (dep[u] < dep[v]) swap(u, v);
      ans[e[i].id] = minw[u] - 1;
    }
  }
  for (int i = 1; i <= m; i++) printf("%d ", ans[i]);
  return 0;
}

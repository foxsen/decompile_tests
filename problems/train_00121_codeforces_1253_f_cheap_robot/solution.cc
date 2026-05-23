#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int x, y;
  long long val;
} e[3 * 100055];
bool cmp(Edge x1, Edge x2) { return x1.val < x2.val; }
int head[100055], to[6 * 100055], nex[6 * 100055];
long long w[6 * 100055];
int edge;
inline void addEdge(int x, int y, long long z) {
  to[++edge] = y, w[edge] = z, nex[edge] = head[x], head[x] = edge;
  to[++edge] = x, w[edge] = z, nex[edge] = head[y], head[y] = edge;
}
int n, m, k, q;
void init() {
  for (int i = 1; i <= n; i++) head[i] = 0;
  edge = 0;
}
bool vis[100055];
long long d[100055];
struct node {
  int x;
  long long val;
  node(int x, long long val) : x(x), val(val) {}
  friend bool operator<(node x1, node x2) { return x1.val > x2.val; }
};
priority_queue<node> que;
int pre[100055];
int findd(int x) {
  if (pre[x] == x) return x;
  return pre[x] = findd(pre[x]);
}
long long f[100055][18];
int g[100055][18];
int dep[100055];
int N;
void dfs(int u, int fa) {
  for (int i = 1; i <= N; i++) {
    g[u][i] = g[g[u][i - 1]][i - 1];
    f[u][i] = max(f[u][i - 1], f[g[u][i - 1]][i - 1]);
  }
  for (int i = head[u]; i; i = nex[i]) {
    int v = to[i];
    if (v == fa) continue;
    dep[v] = dep[u] + 1;
    g[v][0] = u;
    f[v][0] = w[i];
    dfs(v, u);
  }
}
inline long long lca(int x, int y) {
  if (dep[x] > dep[y]) swap(x, y);
  long long ans = 0;
  for (int i = N; i >= 0; i--) {
    if (dep[g[y][i]] >= dep[x]) {
      ans = max(ans, f[y][i]);
      y = g[y][i];
    }
  }
  if (x == y) return ans;
  for (int i = N; i >= 0; i--) {
    if (g[x][i] != g[y][i]) {
      ans = max(f[x][i], ans);
      ans = max(f[y][i], ans);
      x = g[x][i];
      y = g[y][i];
    }
  }
  if (x != y) ans = max(ans, f[x][0]), ans = max(ans, f[y][0]);
  return ans;
}
int main() {
  cin >> n >> m >> k >> q;
  int x, y, z;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &x, &y, &z);
    addEdge(x, y, z);
    e[i].x = x, e[i].y = y, e[i].val = z;
  }
  for (int i = k + 1; i <= n; i++) d[i] = 0x7f7f7f7f7f7f7f7f;
  for (int i = 1; i <= k; i++) que.push(node(i, 0));
  while (que.size()) {
    int u = que.top().x;
    que.pop();
    if (vis[u]) continue;
    vis[u] = true;
    for (int i = head[u]; i; i = nex[i]) {
      int v = to[i];
      if (d[v] > d[u] + w[i]) {
        d[v] = d[u] + w[i];
        que.push(node(v, d[v]));
      }
    }
  }
  for (int i = 1; i <= m; i++) e[i].val += (d[e[i].x] + d[e[i].y]);
  sort(e + 1, e + 1 + m, cmp);
  init();
  for (int i = 1; i <= n; i++) pre[i] = i;
  for (int i = 1; i <= m; i++) {
    x = e[i].x;
    int xx = findd(x);
    y = e[i].y;
    int yy = findd(y);
    if (xx != yy) {
      pre[xx] = yy;
      addEdge(x, y, e[i].val);
    }
  }
  N = ceil(log2(n));
  dep[1] = 1;
  dfs(1, 0);
  while (q--) {
    scanf("%d%d", &x, &y);
    printf("%lld\n", lca(x, y));
  }
  return 0;
}

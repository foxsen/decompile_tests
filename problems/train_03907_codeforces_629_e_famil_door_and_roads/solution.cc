#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m;
int fa[N][20], size[N], dep[N];
long long sum[N], s[N];
struct Edge {
  int t, nxt;
} e[N << 1];
int head[N], cnt;
void add(int u, int v) {
  e[++cnt].t = v;
  e[cnt].nxt = head[u];
  head[u] = cnt;
}
void get_tree(int x) {
  dep[x] = dep[fa[x][0]] + 1;
  size[x] = 1;
  for (int i = 1; i <= 19; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
  for (int i = head[x]; i; i = e[i].nxt) {
    int t = e[i].t;
    if (t == fa[x][0]) continue;
    fa[t][0] = x;
    get_tree(t);
    size[x] += size[t];
    sum[x] += sum[t] + size[t];
  }
}
void dfs(int x) {
  for (int i = head[x]; i; i = e[i].nxt) {
    int t = e[i].t;
    if (t == fa[x][0]) continue;
    s[t] = s[x] + sum[x] - sum[t] - size[t] + n - size[t];
    dfs(t);
  }
}
int LCA(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = 19; i >= 0; i--)
    if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
  if (x == y) return x;
  for (int i = 19; i >= 0; i--)
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  return fa[x][0];
}
int find(int x, int y) {
  for (int i = 19; i >= 0; i--)
    if (dep[fa[fa[x][i]][0]] >= dep[y]) x = fa[x][i];
  return x;
}
inline int Dis(int x, int y) { return dep[x] + dep[y] - (dep[LCA(x, y)] << 1); }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    add(u, v);
    add(v, u);
  }
  get_tree(1);
  dfs(1);
  while (m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    int lca = LCA(x, y);
    double ans = 0;
    if (dep[x] < dep[y]) swap(x, y);
    if (lca == y) {
      int w = find(x, y);
      ans = dep[x] - dep[w] + 1.0 + 1.0 * sum[x] / size[x] +
            1.0 * s[w] / (n - size[w]);
    } else {
      ans = 1.0 * sum[x] / size[x] + 1.0 * sum[y] / size[y] + Dis(x, y) + 1;
    }
    printf("%.8f\n", ans);
  }
  return 0;
}

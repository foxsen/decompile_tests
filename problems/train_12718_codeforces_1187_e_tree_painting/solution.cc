#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;
vector<int> g[N];
int n, sz[N];
long long up[N], down[N];
int rt1 = 1, rt2 = 0;
void pre(int u, int p) {
  sz[u] = 1;
  for (auto v : g[u]) {
    if (v == p) continue;
    pre(v, u);
    sz[u] += sz[v];
    down[u] += down[v] + sz[v];
  }
}
void dfs(int u, int p, int rt) {
  if (p != u) {
    up[u] = up[p] + (sz[rt] - sz[p]) + (down[p] - (down[u] + sz[u])) +
            (sz[p] - sz[u]);
  }
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u, rt);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    up[i] = down[i] = sz[i] = 0;
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  pre(1, 1);
  dfs(1, 1, rt1);
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans = max(ans, up[i] + down[i]);
  cout << ans + n << endl;
}

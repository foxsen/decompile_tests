#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > G, F;
vector<int> visited, explored, V, dp1, dp2, cat, childs, dsu, par, nodes,
    leaves;
int dfs_contract(int v, int p) {
  par[v] = p;
  nodes.push_back(v);
  ++visited[v];
  int ans = 0;
  for (int u : G[v]) {
    if (u == p) continue;
    if (visited[u]) {
      if (explored[u]) continue;
      --V[v];
      ++V[u];
      continue;
    }
    ans += dfs_contract(u, v);
    V[v] += V[u];
    dp1[v] += dp1[u];
  }
  ++explored[v];
  if (V[v] < 0) {
    ++dp1[v];
    dsu[v] = p;
    return 0;
  }
  ans += dp1[v];
  dp1[v] = 0;
  return ans;
}
int Find(int v) {
  if (dsu[v] == v)
    return v;
  else
    return dsu[v] = Find(dsu[v]);
}
void dfs_init(int v, int p) {
  ++childs[v];
  leaves[v] = (F[v].size() < 2);
  for (int u : F[v]) {
    if (u == p) continue;
    dfs_init(u, v);
    childs[v] += childs[u];
    leaves[v] += leaves[u];
  }
}
int far(int v, int& d) {
  queue<vector<int> > Q;
  Q.push({0, v, v});
  int u = v, p;
  while (not Q.empty()) {
    vector<int> aux = Q.front();
    Q.pop();
    d = aux[0], u = aux[1], p = aux[2];
    for (int w : F[u]) {
      if (w != p) Q.push({d + 1, w, u});
    }
  }
  return u;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  G = F = vector<vector<int> >(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  visited = explored = V = dp1 = dp2 = childs = dsu = par = leaves =
      vector<int>(n, 0);
  for (int i = 0; i < n; ++i) dsu[i] = i;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (not visited[i]) {
      if (i) ++ans;
      nodes.clear();
      ans += dfs_contract(i, i);
      for (int v : nodes) {
        if (v == i) continue;
        int u = Find(v);
        int w = Find(par[v]);
        if (u == w) continue;
        F[u].push_back(w);
        F[w].push_back(u);
      }
      dfs_init(i, i);
      int d = 0;
      int v = far(i, d);
      d = 0;
      int u = far(v, d);
      d = max(0, d - 1) + leaves[i];
      ans += childs[i] - d;
    }
  }
  cout << ans << endl;
}

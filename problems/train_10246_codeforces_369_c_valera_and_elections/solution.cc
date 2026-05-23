#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> g;
vector<int> w;
vector<int> dp;
void dfs(int node, int p) {
  dp[node] = w[node];
  for (int u : g[node]) {
    if (u != p) {
      dfs(u, node);
      dp[node] += dp[u];
    }
  }
}
int main() {
  cin >> n;
  int u, v, t;
  g.assign(n + 1, vector<int>());
  w.assign(n + 1, 0);
  dp.assign(n + 1, 0);
  vector<int> ans;
  for (int i = 1; i < n; i++) {
    cin >> u >> v >> t;
    g[u].push_back(v);
    g[v].push_back(u);
    if (t == 2) {
      w[u] = 1;
      w[v] = 1;
    }
  }
  dfs(1, 0);
  for (int i = 1; i <= n; i++) {
    if (dp[i] == 1 && w[i] == 1) ans.push_back(i);
  }
  cout << ans.size() << endl;
  for (auto u : ans) cout << u << " ";
  return 0;
}

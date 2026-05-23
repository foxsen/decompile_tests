#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> w(n + 1);
  for (int i = 1; i <= n; i++) cin >> w[i];
  vector<vector<int>> edge(n + 1);
  vector<pair<int, int>> fav(1);
  vector<int> deg(n + 1);
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    edge[u].emplace_back(i);
    edge[v].emplace_back(i);
    ++deg[u];
    ++deg[v];
    fav.emplace_back(u, v);
  }
  vector<int> ans(m + 1);
  vector<int> Q;
  for (int i = 1; i <= n; i++) {
    if (deg[i] <= w[i]) {
      for (auto& x : edge[i]) {
        if (!ans[x]) {
          ans[x] = i;
          Q.emplace_back(x);
        }
      }
    }
  }
  for (int i = 0; i < (int)Q.size(); i++) {
    int now = Q[i];
    int v = fav[now].first + fav[now].second - ans[now];
    --deg[v];
    if (deg[v] <= w[v]) {
      for (auto& u : edge[v]) {
        if (!ans[u]) {
          ans[u] = v;
          Q.emplace_back(u);
        }
      }
    }
  }
  if ((int)Q.size() != m)
    cout << "DEAD\n";
  else {
    cout << "ALIVE\n";
    reverse(Q.begin(), Q.end());
    for (auto& x : Q) cout << x << " ";
  }
}

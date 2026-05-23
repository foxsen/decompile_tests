#include <bits/stdc++.h>
using namespace std;
const int Maxn = 200005;
vector<int> eul, G[Maxn];
int vis[Maxn];
void dfs(int u) {
  vis[u] = 1;
  eul.push_back(u);
  for (int v : G[u]) {
    if (vis[v] == 0) {
      dfs(v);
      eul.push_back(u);
    }
  }
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1);
  int cost = (2 * n + k - 1) / k;
  int f = 0;
  vector<vector<int>> ans;
  for (int i = 0; i < eul.size(); i += cost) {
    vector<int> cur;
    for (int j = i; j < min(int(eul.size()), i + cost); ++j)
      cur.push_back(eul[j]);
    if (cur.size() == 0) {
      cur.push_back(1);
    }
    ans.push_back(cur);
  }
  while (ans.size() < k) {
    vector<int> t;
    t.push_back(1);
    ans.push_back(t);
  }
  for (auto i : ans) {
    cout << i.size() << ' ';
    for (auto j : i) cout << j << ' ';
    cout << '\n';
  }
  return 0;
}

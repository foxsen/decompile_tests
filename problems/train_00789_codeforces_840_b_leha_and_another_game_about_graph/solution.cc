#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 100;
vector<int> adj[N];
int n, m, d[N];
vector<pair<int, int> > edge;
bool in[N];
int wildcard, sz[N];
bool vis[N];
void dfs(int u) {
  vis[u] = true;
  if (d[u] == -1) wildcard = u;
  sz[u] = (d[u] == 1);
  for (int id : adj[u]) {
    auto e = edge[id];
    int v = e.first + e.second - u;
    if (vis[v]) continue;
    dfs(v);
    sz[u] += sz[v];
    in[id] = sz[v] & 1;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < (int)(n); i++) cin >> d[i];
  for (int _ = 0; _ < (int)(m); _++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    edge.emplace_back(u, v);
    adj[u].push_back(((int)(edge).size()) - 1);
    adj[v].push_back(((int)(edge).size()) - 1);
  }
  bool ok = 1;
  for (int u = 0; u < (int)(n); u++)
    if (!vis[u]) {
      wildcard = -1;
      dfs(u);
      if ((sz[u] & 1)) {
        if (wildcard == -1) {
          ok = 0;
          break;
        } else
          d[wildcard] = 1;
      }
    }
  if (ok) {
    fill_n(vis, n, false);
    for (int u = 0; u < (int)(n); u++)
      if (!vis[u]) dfs(u);
    vector<int> ans;
    for (int id = 0; id < (int)(m); id++)
      if (in[id]) ans.push_back(id);
    cout << ((int)(ans).size()) << endl;
    for (auto x : ans) cout << x + 1 << '\n';
  } else
    cout << -1 << endl;
  return 0;
}

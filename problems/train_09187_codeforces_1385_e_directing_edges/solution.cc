#include <bits/stdc++.h>
using namespace std;
const int tam = 2e5;
vector<int> adj[tam];
vector<int> pos(tam);
vector<int> color(tam);
int topo_pos;
bool acyc;
void dfs(int v) {
  color[v] = 1;
  for (int u : adj[v]) {
    if (!color[u])
      dfs(u);
    else if (color[u] == 1)
      acyc = false;
  }
  pos[v] = topo_pos--;
  color[v] = 2;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 0; i < m; i++) {
      int t, x, y;
      cin >> t >> x >> y;
      --x, --y;
      if (t) adj[x].push_back(y);
      edges.push_back({x, y});
    }
    topo_pos = 25;
    acyc = true;
    for (int i = 0; i < n; i++) color[i] = 0;
    for (int i = 0; i < n; i++)
      if (!color[i]) dfs(i);
    if (!acyc) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    for (pair<int, int> pii : edges) {
      if (pos[pii.first] < pos[pii.second])
        cout << pii.first + 1 << " " << pii.second + 1 << endl;
      else
        cout << pii.second + 1 << " " << pii.first + 1 << endl;
    }
  }
  return 0;
}

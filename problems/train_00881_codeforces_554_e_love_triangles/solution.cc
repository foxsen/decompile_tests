#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
int n, m, v, u, t, cnt, dis[100100];
long long ans = 1;
bool mark[100100];
vector<pair<int, int> > g[100100];
void dfs(int a) {
  mark[a] = true;
  for (int i = 0; i < g[a].size(); i++)
    if (!mark[g[a][i].first]) {
      dis[g[a][i].first] = dis[a] + g[a][i].second;
      dfs(g[a][i].first);
    } else {
      if ((dis[g[a][i].first] & 1) == (dis[a] & 1) && g[a][i].second) ans = 0;
      if ((dis[g[a][i].first] & 1) != (dis[a] & 1) && !g[a][i].second) ans = 0;
    }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> v >> u >> t;
    t = !t;
    g[v].push_back(make_pair(u, t));
    g[u].push_back(make_pair(v, t));
  }
  for (int i = 1; i <= n; i++)
    if (!mark[i]) {
      dfs(i);
      cnt++;
    }
  for (int i = 1; i < cnt; i++) ans = (ans * 2ll) % M;
  cout << ans << endl;
  return 0;
}

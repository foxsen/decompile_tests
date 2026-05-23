#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
vector<int> p;
vector<vector<pair<int, int> > > gr;
vector<int> x;
int dsu_get(int v) { return (v == p[v]) ? v : (p[v] = dsu_get(p[v])); }
void dsu_unite(int a, int b) {
  a = dsu_get(a);
  b = dsu_get(b);
  if (rand() & 1) swap(a, b);
  if (a != b) p[a] = b;
}
vector<int> marked;
vector<char> used;
void dfs(int v) {
  marked[v] = 1;
  for (int i = 0; i < gr[v].size(); i++)
    if (!marked[gr[v][i].first]) {
      dfs(gr[v][i].first);
      if (marked[gr[v][i].first] == 2) {
        used[gr[v][i].second] = true;
        marked[v] = 2;
      }
    }
  if (x[v]) {
    marked[v] = 2;
  }
}
int main() {
  srand(time(NULL));
  int n, m, k;
  cin >> n >> m >> k;
  gr.resize(n);
  x.resize(n, 0);
  int xf = 0;
  for (int i = 0; i < k; i++) {
    int ff;
    cin >> ff;
    ff--;
    x[ff] = 1;
    xf = ff;
  }
  vector<pair<int, pair<int, int> > > g;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    g.push_back(make_pair(w, make_pair(v, u)));
  }
  int cost = 0;
  vector<pair<int, pair<int, int> > > res;
  sort(g.begin(), g.end());
  p.resize(n, 0);
  for (int i = 0; i < n; ++i) p[i] = i;
  for (int i = 0; i < m; ++i) {
    int a = g[i].second.first, b = g[i].second.second, l = g[i].first;
    if (dsu_get(a) != dsu_get(b)) {
      cost += l;
      res.push_back(make_pair(g[i].first, g[i].second));
      dsu_unite(a, b);
    }
  }
  sort(res.begin(), res.end());
  marked.resize(n, false);
  used.resize(res.size(), false);
  for (int i = 0; i < res.size(); i++) {
    gr[res[i].second.first].push_back(make_pair(res[i].second.second, i));
    gr[res[i].second.second].push_back(make_pair(res[i].second.first, i));
  }
  dfs(xf);
  int ans = 0;
  for (int i = res.size() - 1; i >= 0; i--)
    if (used[i]) {
      ans = res[i].first;
      break;
    }
  for (int i = 0; i < k; i++) cout << ans << " ";
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1000 * 100;
int col[N + 3], sz[N + 3];
long long ans[N + 3];
map<int, long long>* cnt[N + 2];
map<int, long long>* val[N + 3];
vector<int> g[N + 3];
void dfs(int u, int p) {
  int mx = -1, bigChild = -1;
  sz[u] = 1;
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
    sz[u] += sz[v];
    if (sz[v] > mx) mx = sz[v], bigChild = v;
  }
  if (bigChild != -1) {
    cnt[u] = cnt[bigChild], val[u] = val[bigChild];
  } else {
    cnt[u] = new map<int, long long>(), val[u] = new map<int, long long>();
  }
  if ((*cnt[u])[col[u]] > 0) (*val[u])[(*cnt[u])[col[u]]] -= col[u];
  (*cnt[u])[col[u]] += 1;
  (*val[u])[(*cnt[u])[col[u]]] += col[u];
  for (auto v : g[u]) {
    if (v == p || v == bigChild) continue;
    for (auto it : (*cnt[v])) {
      int colr = it.first;
      long long freq = it.second;
      if ((*cnt[u])[colr] > 0) (*val[u])[(*cnt[u])[colr]] -= colr;
      (*cnt[u])[colr] += freq;
      (*val[u])[(*cnt[u])[colr]] += colr;
    }
  }
  ans[u] = ((*val[u]).rbegin())->second;
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  memset(sz, 0, sizeof sz);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> col[i];
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
  cout << "\n";
  return 0;
}

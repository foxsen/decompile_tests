#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long MOD = 998244353;
const long long N = 1e5 + 9;
const long long M = 1e6 + 9;
long long n, l, m, cnt, root;
vector<long long> G[N];
bool ll[N];
void dfs(long long u, long long f, long long dep) {
  bool ok = 0;
  for (auto v : G[u]) {
    if (ll[v]) ok = 1;
    if (v == f) continue;
    dfs(v, u, dep + 1);
  }
  if (ok && !ll[u]) m++;
  if (u == root || !ll[u]) return;
  if (~dep & 1) cnt++;
}
void solve() {
  cin >> n;
  for (long long i = 1, u, v; i <= n - 1; i++) {
    cin >> u >> v;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  for (long long u = 1; u <= n; u++) {
    if (G[u].size() == 1) {
      root = u;
      ll[u] = 1;
      l++;
    }
  }
  dfs(root, root, 1);
  if (cnt)
    cout << 3 << " ";
  else
    cout << 1 << " ";
  cout << n - 1 - l + m << endl;
  return;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  solve();
  return 0;
}

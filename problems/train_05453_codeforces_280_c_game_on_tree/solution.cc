#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int N = 1e5 + 5;
int n;
vector<int> g[N];
long double dfs(int node, int par, int lvl) {
  long double ans = 1.0 / lvl;
  for (auto &i : g[node])
    if (i != par) ans += dfs(i, node, lvl + 1);
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  cout << fixed << setprecision(9) << dfs(1, 1, 1);
  return 0;
}

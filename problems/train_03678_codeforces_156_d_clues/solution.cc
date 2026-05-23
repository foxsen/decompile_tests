#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7, inf = 0x3f3f3f3f;
vector<int> g[maxn];
int vis[maxn], n, m, mod, cnt;
void dfs(int u, int fa) {
  cnt++;
  vis[u] = 1;
  for (auto &v : g[u]) {
    if (v == fa || vis[v]) continue;
    dfs(v, u);
  }
}
long long quick(long long x, long long n) {
  long long res = 1;
  x %= mod;
  if (x == 0) return 0;
  while (n) {
    if (n & 1) res = (res * x) % mod;
    x = (x * x) % mod;
    n >>= 1;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> mod;
  for (int i = 0, u, v; i < m; ++i) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> s;
  for (int i = 1; i <= n; ++i) {
    cnt = 0;
    if (vis[i]) continue;
    dfs(i, 0);
    s.push_back(cnt);
  }
  int k = s.size();
  if (k == 1) {
    cout << 1 % mod << '\n';
    return 0;
  }
  long long ans = quick(n, k - 2);
  for (auto &v : s) ans = ans * v % mod;
  cout << ans % mod << '\n';
  return 0;
}

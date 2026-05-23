#include <bits/stdc++.h>
using namespace std;
const double error = 1e-15;
const double pi = 2 * acos(0);
const int maxn = (int)1e5 + 10;
const int mod = (int)1e9 + 7;
int dx[] = {0, -1, 0, +1, -1, -1, +1, +1};
int dy[] = {-1, 0, +1, 0, -1, +1, +1, -1};
long dp[200005], pv[200005];
vector<long> L[200005], R[200005], g[200005];
int p[200005];
long dfs(int v) {
  long j, u, x;
  dp[v] = 1;
  for (j = 0; j < g[v].size(); j++) {
    u = g[v][j];
    x = dfs(u);
    dp[v] = (1LL * dp[v] * (x + 1)) % mod;
    L[v].push_back(dp[v]);
  }
  R[v].resize(g[v].size());
  for (j = g[v].size() - 1; j >= 0; j--) {
    u = g[v][j];
    x = j == g[v].size() - 1 ? (dp[u] + 1) : (1LL * (dp[u] + 1) * x) % mod;
    R[v][j] = x;
  }
  return dp[v];
}
int main() {
  ios_base::sync_with_stdio(0);
  long n, i, x, pp, j, y;
  cin >> n;
  for (i = 2; i <= n; i++) {
    cin >> p[i];
    g[p[i]].push_back(i);
  }
  x = dfs(1);
  cout << x << " ";
  pv[1] = 1;
  for (i = 2; i <= n; i++) {
    pp = p[i];
    x = pv[pp];
    y = lower_bound(g[pp].begin(), g[pp].end(), i) - g[pp].begin();
    if (y > 0) {
      x = (1LL * x * L[pp][y - 1]) % mod;
    }
    if (y < g[pp].size() - 1) {
      x = (1LL * x * R[pp][y + 1]) % mod;
    }
    pv[i] = x + 1;
    x = (1LL * (x + 1) * dp[i]) % mod;
    cout << x << " ";
  }
  return 0;
}

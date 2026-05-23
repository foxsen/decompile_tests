#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long double eps = 1e-7;
const int inf = 1000000010;
const long long INF = 10000000000000010LL;
const int mod = 998244353;
const int MAXN = 300010, LOG = 18;
struct DSU {
  int par[MAXN];
  DSU() {
    for (int i = 1; i < MAXN; i++) par[i] = i;
  }
  int get(int x) {
    if (par[x] == x) return x;
    return par[x] = get(par[x]);
  }
  void join(int x, int y) { par[get(x)] = get(y); }
} dsu;
int n, m, k, u, v, x, y, t, a, b;
int A[MAXN], B[MAXN];
int h[MAXN];
int par[MAXN][LOG];
long long dp[MAXN][2];
vector<int> G[MAXN], vec[MAXN];
void dfs1(int node, int p) {
  h[node] = h[p] + 1;
  par[node][0] = p;
  for (int i = 1; i < LOG; i++) par[node][i] = par[par[node][i - 1]][i - 1];
  for (int v : G[node])
    if (v != p) dfs1(v, node);
}
int Lca(int x, int y) {
  if (h[x] > h[y]) swap(x, y);
  for (int i = 0; i < LOG; i++)
    if ((h[y] - h[x]) & (1 << i)) y = par[y][i];
  if (x == y) return x;
  for (int i = LOG - 1; i >= 0; i--)
    if (par[x][i] != par[y][i]) {
      x = par[x][i];
      y = par[y][i];
    }
  return par[x][0];
}
int dfs2(int node, int p) {
  for (int v : G[node])
    if (v != p) B[node] += dfs2(v, node);
  return B[node];
}
long long powmod(long long a, long long b) {
  if (!b) return 1;
  if (b & 1) return a * powmod(a * a % mod, b >> 1) % mod;
  return powmod(a * a % mod, b >> 1);
}
long long inv(long long x) { return powmod(x, mod - 2); }
void dfs3(int node) {
  for (int v : G[node]) dfs3(v);
  dp[node][0] = 1;
  for (int v : G[node]) dp[node][0] = dp[node][0] * (dp[v][0] + dp[v][1]) % mod;
  if (vec[node].empty()) {
    for (int v : G[node])
      dp[node][1] = (dp[node][1] + dp[v][1] * inv(dp[v][0] + dp[v][1])) % mod;
    dp[node][1] = dp[node][1] * dp[node][0] % mod;
    return;
  }
  swap(dp[node][0], dp[node][1]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
    if (A[i]) B[i]++;
    vec[A[i]].push_back(i);
  }
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs1(1, 1);
  for (int i = 1; i <= k; i++)
    if (vec[i].size() > 0) {
      int v = vec[i][0];
      for (int j = 1; j < vec[i].size(); j++) v = Lca(v, vec[i][j]);
      B[v] -= vec[i].size();
    }
  dfs2(1, 1);
  for (int i = 1; i <= n; i++) G[i].clear(), vec[i].clear();
  for (int i = 2; i <= n; i++)
    if (B[i]) dsu.join(i, par[i][0]);
  for (int i = 1; i <= n; i++)
    if (A[i]) vec[dsu.get(i)].push_back(A[i]);
  for (int i = 1; i <= n; i++)
    if (vec[i].size()) {
      int shit = vec[i][0];
      for (int j : vec[i])
        if (j != shit) return cout << 0 << '\n', 0;
    }
  for (int i = 2; i <= n; i++)
    if (!B[i]) G[dsu.get(par[i][0])].push_back(dsu.get(i));
  dfs3(1);
  cout << dp[1][1] << '\n';
  return 0;
}

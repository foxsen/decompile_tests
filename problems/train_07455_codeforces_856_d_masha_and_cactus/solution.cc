#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 998244353;
const ll root = 3;
ll binpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}
ll modInv(ll a) { return binpow(a, MOD - 2); }
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll NINFLL = 0xc0c0c0c0c0c0c0c0;
const int mxN = 200001;
vector<int> adj[mxN];
vector<array<int, 3>> prv[mxN];
int par[mxN][19];
int depth[mxN];
int dp[mxN][2];
int n, m;
int BIT[2 * mxN];
struct BIT {
  int sumarr[2 * mxN];
  void add(int p, int x) {
    p++;
    while (p <= 2 * n) {
      sumarr[p] += x;
      p += (p & -p);
    }
  }
  int sum(int p) {
    int res = 0;
    p++;
    while (p) {
      res += sumarr[p];
      p -= (p & -p);
    }
    return res;
  }
} onpath, offpath;
int tin[mxN];
int tout[mxN];
int timer = 0;
void dfs(int u) {
  tin[u] = timer++;
  for (int v : adj[u]) {
    depth[v] = depth[u] + 1;
    dfs(v);
  }
  tout[u] = timer++;
}
int lca(int a, int b) {
  if (depth[a] > depth[b]) {
    for (int d = (19) - 1; d >= (0); --d) {
      if (depth[par[a][d]] >= depth[b]) a = par[a][d];
    }
  } else if (depth[a] < depth[b]) {
    for (int d = (19) - 1; d >= (0); --d) {
      if (depth[par[b][d]] >= depth[a]) b = par[b][d];
    }
  }
  if (a == b) return a;
  for (int d = (19) - 1; d >= (0); --d) {
    if (par[b][d] != par[a][d]) {
      a = par[a][d];
      b = par[b][d];
    }
  }
  return par[a][0];
}
void solve(int u) {
  for (int v : adj[u]) {
    solve(v);
    dp[u][1] += dp[v][0];
  }
  offpath.add(tin[u], dp[u][1]);
  offpath.add(tout[u] + 1, -dp[u][1]);
  dp[u][0] = dp[u][1];
  for (auto p : prv[u]) {
    if (p[1] == -1) {
      int cc = p[0];
      for (int d = (19) - 1; d >= (0); --d) {
        if (depth[par[cc][d]] >= depth[u] + 1) {
          cc = par[cc][d];
        }
      }
      dp[u][0] = max(dp[u][0], dp[u][1] - dp[cc][0] + offpath.sum(tin[p[0]]) -
                                   offpath.sum(tin[u]) + p[2] -
                                   onpath.sum(tin[p[0]]) + onpath.sum(tin[cc]));
    } else {
      int cc1 = p[0];
      int cc2 = p[1];
      for (int d = (19) - 1; d >= (0); --d) {
        if (depth[par[cc1][d]] >= depth[u] + 1) {
          cc1 = par[cc1][d];
        }
        if (depth[par[cc2][d]] >= depth[u] + 1) {
          cc2 = par[cc2][d];
        }
      }
      dp[u][0] =
          max(dp[u][0], dp[u][1] - dp[cc1][0] - dp[cc2][0] +
                            offpath.sum(tin[p[0]]) + offpath.sum(tin[p[1]]) -
                            2 * offpath.sum(tin[u]) + onpath.sum(tin[cc1]) +
                            onpath.sum(tin[cc2]) - onpath.sum(tin[p[0]]) -
                            onpath.sum(tin[p[1]]) + p[2]);
    }
  }
  onpath.add(tin[u], dp[u][0]);
  onpath.add(tout[u] + 1, -dp[u][0]);
}
int main() {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  int p;
  for (int i = (1); i < (n); ++i) {
    cin >> par[i][0];
    par[i][0]--;
    adj[par[i][0]].push_back(i);
  }
  for (int lg = (1); lg < (19); ++lg) {
    for (int i = (0); i < (n); ++i) {
      par[i][lg] = par[par[i][lg - 1]][lg - 1];
    }
  }
  dfs(0);
  int a, b, c;
  for (int i = (0); i < (m); ++i) {
    cin >> a >> b >> c;
    a--;
    b--;
    if (depth[a] > depth[b]) swap(a, b);
    int node = lca(a, b);
    if (node == a) {
      prv[node].push_back({b, -1, c});
    } else {
      prv[node].push_back({a, b, c});
    }
  }
  solve(0);
  cout << dp[0][0] << "\n";
  return 0;
}

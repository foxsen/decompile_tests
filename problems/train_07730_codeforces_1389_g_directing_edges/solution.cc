#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const int N = 1e6;
const int L = 20;
vector<array<int, 2>> adj[N];
array<int, 2> edges[N];
int vis[N], tin[N], low[N], ptr, isBridge[N];
void dfsBridge(int node, int pind) {
  vis[node] = 1;
  low[node] = tin[node] = ++ptr;
  for (auto edge : adj[node]) {
    int nxt = edge[0], ind = edge[1];
    if (ind == pind) continue;
    if (vis[nxt]) {
      low[node] = min(low[node], low[nxt]);
    } else {
      dfsBridge(nxt, ind);
      low[node] = min(low[node], low[nxt]);
      if (low[nxt] > tin[node]) {
        isBridge[ind] = 1;
      }
    }
  }
}
struct DSU {
  vector<int> par, sub;
  DSU(int n) {
    par.resize(n + 1);
    sub.resize(n + 1, 1);
    for (int i = 1; i <= n; i++) par[i] = i;
  }
  int root(int x) {
    if (par[x] != x) {
      par[x] = root(par[x]);
    }
    return par[x];
  }
  void merge(int u, int v) {
    int ru = root(u);
    int rv = root(v);
    if (ru == rv) return;
    if (sub[ru] > sub[rv]) swap(rv, ru);
    sub[rv] += sub[ru];
    par[ru] = rv;
  }
};
int cnt[N];
long long c[N], w[N], dp[N], dpf[N];
vector<array<int, 2>> adjc[N];
int k;
void dfs(int node, int par) {
  dp[node] = c[node];
  for (auto edge : adjc[node]) {
    int nxt = edge[0], ind = edge[1];
    if (nxt != par) {
      dfs(nxt, node);
      if (cnt[nxt] == 0 || cnt[nxt] == k) {
        dp[node] += dp[nxt];
      } else {
        dp[node] += max(0LL, dp[nxt] - w[ind]);
      }
      cnt[node] += cnt[nxt];
    }
  }
}
void dfs_reroot(int node, int par) {
  dpf[node] = dp[node];
  for (auto edge : adjc[node]) {
    int nxt = edge[0], ind = edge[1];
    if (nxt != par) {
      if (cnt[nxt] == 0 || cnt[nxt] == k) {
        dp[node] -= dp[nxt];
      } else {
        dp[node] -= max(0LL, dp[nxt] - w[ind]);
      }
      cnt[node] -= cnt[nxt];
      if (cnt[node] == 0 || cnt[node] == k) {
        dp[nxt] += dp[node];
      } else {
        dp[nxt] += max(0LL, dp[node] - w[ind]);
      }
      cnt[nxt] += cnt[node];
      dfs_reroot(nxt, node);
      cnt[nxt] -= cnt[node];
      if (cnt[node] == 0 || cnt[node] == k) {
        dp[nxt] -= dp[node];
      } else {
        dp[nxt] -= max(0LL, dp[node] - w[ind]);
      }
      cnt[node] += cnt[nxt];
      if (cnt[nxt] == 0 || cnt[nxt] == k) {
        dp[node] += dp[nxt];
      } else {
        dp[node] += max(0LL, dp[nxt] - w[ind]);
      }
    }
  }
}
void solve() {
  int n, m;
  cin >> n >> m >> k;
  for (int i = 1; i <= k; i++) {
    int u;
    cin >> u;
    cnt[u] = 1;
  }
  for (int i = 1; i <= n; i++) cin >> c[i];
  for (int i = 1; i <= m; i++) cin >> w[i];
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
    edges[i] = {u, v};
  }
  dfsBridge(1, 0);
  DSU dsu(n);
  for (int i = 1; i <= m; i++) {
    if (!isBridge[i]) {
      dsu.merge(edges[i][0], edges[i][1]);
    }
  }
  for (int i = 1; i <= m; i++) {
    if (isBridge[i]) {
      int u = dsu.root(edges[i][0]), v = dsu.root(edges[i][1]);
      adjc[u].push_back({v, i});
      adjc[v].push_back({u, i});
    }
  }
  int root = 0;
  for (int i = 1; i <= n; i++) {
    int pi = dsu.root(i);
    if (pi != i) {
      cnt[pi] += cnt[i];
      c[pi] += c[i];
    } else {
      root = i;
    }
  }
  dfs(root, 0);
  dfs_reroot(root, 0);
  for (int i = 1; i <= n; i++) {
    cout << dpf[dsu.root(i)] << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cout << fixed << setprecision(20);
  ;
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}

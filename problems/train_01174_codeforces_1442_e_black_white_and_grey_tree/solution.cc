#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
bool mini(T1 &a, T2 b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T1, typename T2>
bool maxi(T1 &a, T2 b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
const int N = 2e5 + 5;
const int oo = 1e9;
vector<int> adj[N];
int dp[N][2];
int a[N];
int n, ans;
void dfs(int u, int p = -1) {
  for (int v : adj[u])
    if (v != p) dfs(v, u);
  dp[u][0] = dp[u][1] = oo;
  if (a[u] == 0) {
    int d = oo;
    for (int val = 0; val < 2; val++) {
      dp[u][val] = 0;
      pair<int, int> tmp = make_pair(0, 0);
      for (int v : adj[u])
        if (v != p) {
          int res = min(dp[v][0] + val, dp[v][1] + (!val));
          maxi(dp[u][val], res);
          maxi(tmp.second, res);
          if (tmp.second > tmp.first) swap(tmp.second, tmp.first);
        }
      mini(d, tmp.first + tmp.second);
    }
    maxi(ans, d);
  } else {
    int val = a[u] - 1;
    dp[u][val] = 0;
    pair<int, int> tmp = make_pair(0, 0);
    for (int v : adj[u])
      if (v != p) {
        int res = min(dp[v][0] + val, dp[v][1] + (!val));
        maxi(dp[u][val], res);
        maxi(tmp.second, res);
        if (tmp.second > tmp.first) swap(tmp.second, tmp.first);
      }
    maxi(ans, tmp.first + tmp.second);
  }
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    adj[i].clear();
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  ans = 0;
  dfs(1);
  cout << ((ans + 1) >> 1) + 1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

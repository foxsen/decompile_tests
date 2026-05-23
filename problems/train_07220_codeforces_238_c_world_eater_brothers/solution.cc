#include <bits/stdc++.h>
using namespace std;
int const N = 3000 + 20;
int n, dp[N], mx1, mx2, ans;
vector<pair<int, bool>> adj[N];
void dfs1(int v, int p = -1) {
  for (auto x : adj[v]) {
    int u = x.first, f = x.second;
    if (u != p) {
      dfs1(u, v);
      dp[v] += dp[u] + (!f);
    }
  }
  return;
}
void dfs2(int v, int p = -1) {
  for (auto x : adj[v]) {
    int u = x.first, f = x.second;
    if (u != p) {
      dp[u] = dp[v];
      f ? dp[u]++ : dp[u]--;
      dfs2(u, v);
    }
  }
  return;
}
pair<int, int> dfs3(int v, int p = -1) {
  int m1 = 0, m2 = 0;
  for (auto x : adj[v]) {
    int u = x.first, f = x.second;
    if (u != p) {
      m2 = max(m2, dfs3(u, v).first + (f ? -1 : 1));
      if (m2 > m1) swap(m1, m2);
    }
  }
  return {m1, m2};
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  ans = n - 1;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    adj[x].push_back({y, 1});
    adj[y].push_back({x, 0});
  }
  dfs1(0);
  dfs2(0);
  for (int i = 0; i < n; i++) {
    pair<int, int> cur = dfs3(i);
    mx1 = cur.first, mx2 = cur.second;
    ans = min(ans, dp[i] - mx1 - mx2);
  }
  return cout << ans, 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, m, ans[5005];
pair<int, int> pre[5005];
vector<pair<int, int>> adj[5005], q[5005];
void dfs(int u, int par) {
  for (pair<int, int> nxt : adj[u]) {
    int v = nxt.first;
    if (v == par) continue;
    pre[v] = {u, nxt.second};
    dfs(v, u);
  }
}
void update(int u, int v, int val) {
  while (v != u) {
    ans[pre[v].second] = max(ans[pre[v].second], val);
    v = pre[v].first;
  }
}
int check(int u, int v, int val) {
  int cur = INT_MAX;
  while (v != u) {
    cur = min(cur, ans[pre[v].second]);
    v = pre[v].first;
  }
  return cur == val;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
    ans[i] = 1;
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    int u, v, val;
    cin >> u >> v >> val;
    q[u].push_back({v, val});
  }
  for (int i = 1; i <= n; i++) {
    if (q[i].empty()) continue;
    pre[i] = {i, 0};
    dfs(i, i);
    for (pair<int, int> cur : q[i]) {
      update(i, cur.first, cur.second);
    }
  }
  bool ok = true;
  for (int i = 1; i <= n; i++) {
    if (q[i].empty()) continue;
    pre[i] = {i, 0};
    dfs(i, i);
    for (pair<int, int> cur : q[i]) {
      ok &= check(i, cur.first, cur.second);
    }
  }
  if (ok) {
    for (int i = 0; i < n - 1; i++) {
      cout << ans[i] << (i + 1 < n - 1 ? ' ' : '\n');
    }
  } else {
    cout << -1 << '\n';
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> graph(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  int ans = 0;
  int cnt = 0;
  int flag = 0;
  function<int(int, int, int)> dfs = [&](int u, int k, int fa) {
    int is_leaf = 1;
    int sub_sum = 0;
    for (auto &v : graph[u]) {
      if (v == fa) {
        continue;
      }
      is_leaf = 0;
      sub_sum += dfs(v, k + 1, u);
    }
    if (is_leaf) {
      if (k == 1) {
        ans++;
        flag = 1;
      }
      return 1;
    }
    if (sub_sum == 0) {
      if (k == 1) {
        ans++;
        flag = 1;
      }
      return 1;
    }
    if (k) {
      ans += sub_sum;
      cnt++;
    }
    return 0;
  };
  dfs(1, 0, 0);
  if (flag) {
    cout << ans - cnt << endl;
  } else {
    cout << ans - cnt + 1 << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

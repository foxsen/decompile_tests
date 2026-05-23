#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, s, t;
  cin >> n >> m;
  vector<vector<int> > g(n + 1);
  vector<bool> vis(n + 1, 0);
  vector<int> indeg(n + 1, 0);
  vector<int> dp(n + 1, -1);
  deque<int> dq;
  while (m--) {
    int a, b;
    cin >> a >> b;
    g[b].push_back(a);
    indeg[a]++;
  }
  cin >> s >> t;
  dp[t] = 0;
  dq.push_front(t);
  while (!dq.empty()) {
    int v = dq.front();
    dq.pop_front();
    if (vis[v]) continue;
    vis[v] = 1;
    for (auto to : g[v]) {
      --indeg[to];
      if (!indeg[to]) {
        if (dp[to] == -1 || dp[to] > dp[v]) {
          dp[to] = dp[v];
          dq.push_front(to);
        }
      } else {
        if (dp[to] == -1) {
          dp[to] = dp[v] + 1;
          dq.push_back(to);
        }
      }
    }
  }
  cout << dp[s];
  return 0;
}

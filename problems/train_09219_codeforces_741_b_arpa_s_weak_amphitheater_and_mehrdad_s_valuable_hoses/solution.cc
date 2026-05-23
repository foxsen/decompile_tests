#include <bits/stdc++.h>
using namespace std;
long long qpow(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n % 2) {
      res = (res * a) % 998244353;
      n--;
    } else {
      n = n / 2;
      a = (a * a) % 998244353;
    }
  }
  return res;
}
void dfs(vector<vector<int>> &list, vector<int> &vis, int node,
         vector<int> &t) {
  int n = list.size() - 1;
  vis[node] = 1;
  t.push_back(node);
  for (int j = 0; j < list[node].size(); j++) {
    if (vis[list[node][j]] == 0) dfs(list, vis, list[node][j], t);
  }
}
void solve() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> list(n + 1);
  vector<int> w(n + 1), b(n + 1), vis(n + 1);
  for (int i = 1; i <= n; i++) cin >> w[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    list[x].push_back(y);
    list[y].push_back(x);
  }
  vector<vector<pair<int, int>>> a;
  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0) {
      vector<int> t;
      dfs(list, vis, i, t);
      vector<pair<int, int>> second;
      int sw = 0, sb = 0;
      for (int i = 0; i < t.size(); i++) {
        second.push_back({w[t[i]], b[t[i]]});
        sw += w[t[i]];
        sb += b[t[i]];
      }
      if (t.size() > 1) second.push_back({sw, sb});
      a.push_back(second);
      second.clear(), t.clear();
    }
  }
  vector<vector<int>> dp(a.size(), vector<int>(1001));
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a[i].size(); j++) {
      int wi = a[i][j].first;
      int bi = a[i][j].second;
      for (int g = 1; g < 1001; g++) {
        if (i - 1 >= 0) dp[i][g] = max(dp[i][g], dp[i - 1][g]);
        if (wi <= g) {
          if (i - 1 >= 0)
            dp[i][g] = max(dp[i][g], max(dp[i - 1][g], bi + dp[i - 1][g - wi]));
          else
            dp[i][g] = max(bi, dp[i][g]);
        }
      }
    }
  }
  cout << dp[a.size() - 1][k] << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}

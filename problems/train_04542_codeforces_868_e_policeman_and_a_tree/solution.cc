#include <bits/stdc++.h>
using namespace std;
const int maxn = 60, maxc = 1 << 29;
int n, s, m;
int dp[maxn][maxn][maxn][maxn], x[maxn];
map<int, int> dt[maxn];
vector<pair<int, int> > e[maxn];
int dfs(int u, int par) {
  int res = x[u];
  for (auto [v, w] : e[u]) {
    if (v == par) continue;
    res += dfs(v, u);
  }
  return res;
}
int ask(int u, int par, int k, int cnt) {
  int &ans = dp[u][par][k][cnt];
  if (ans != -1) {
    return ans;
  }
  if (k == 0) {
    return ans = 0;
  }
  if (e[u].size() == 1) {
    ans = ask(par, u, k - cnt, k - cnt) + e[u][0].second;
    return ans;
  }
  int dis = dt[u][par];
  int res[60];
  res[0] = maxc;
  for (int i = 1; i < 60; i++) res[i] = -maxc;
  for (auto [v, w] : e[u]) {
    if (v == par) continue;
    for (int j = cnt; j >= 0; j--) {
      for (int l = 1; l <= j; l++)
        res[j] = max(res[j], min(res[j - l], ask(v, u, k, l) + dis));
    }
  }
  return ans = res[cnt];
}
int main() {
  ios_base::sync_with_stdio(false);
  int ans = maxc;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    e[u].push_back({v, w});
    e[v].push_back({u, w});
    dt[u][v] = dt[v][u] = w;
  }
  cin >> s;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int val;
    cin >> val;
    x[val]++;
  }
  memset(dp, -1, sizeof(dp));
  for (auto [v, w] : e[s]) {
    int cnt = dfs(v, s);
    ans = min(ans, ask(v, s, m, cnt));
  }
  cout << ans;
  return 0;
}

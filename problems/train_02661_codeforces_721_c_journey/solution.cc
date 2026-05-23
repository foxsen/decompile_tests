#include <bits/stdc++.h>
using namespace std;
const int infi = 1e9 + 7;
int dp[5010][5010];
int p[5010][5010];
vector<int> lst;
int used[5010];
vector<vector<pair<int, int> > > g;
void dfs(int v) {
  if (used[v]) return;
  used[v] = 1;
  for (int i = 0; i < g[v].size(); ++i) dfs(g[v][i].first);
  lst.push_back(v);
  return;
}
int main() {
  int n, m, t;
  cin >> n >> m >> t;
  g.resize(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= n; j++) dp[i][j] = infi, p[i][j] = -1;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    g[a].push_back(make_pair(b, c));
  }
  dfs(0);
  dp[0][1] = 0;
  reverse(lst.begin(), lst.end());
  for (int i = 0; i < lst.size(); i++) {
    int v = lst[i];
    for (int cnt = 0; cnt <= n; cnt++) {
      if (dp[v][cnt] >= t) continue;
      for (int k = 0; k < g[v].size(); ++k) {
        int to = g[v][k].first;
        int cost = min(infi, dp[v][cnt] + g[v][k].second);
        if (dp[to][cnt + 1] > cost) {
          dp[to][cnt + 1] = cost;
          p[to][cnt + 1] = v;
        }
      }
    }
  }
  vector<int> ans;
  int v = n - 1;
  int cnt = 0;
  for (int i = n; i >= 0; --i) {
    if (dp[v][i] <= t) {
      cnt = i;
      break;
    }
  }
  while (v != -1) {
    ans.push_back(v);
    v = p[v][cnt];
    --cnt;
  }
  cout << ans.size() << endl;
  for (int i = (int)ans.size() - 1; i >= 0; --i) cout << ans[i] + 1 << " ";
  cout << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline void minaj(T1 &x, T2 y) {
  x = (x > y ? y : x);
}
template <typename T1, typename T2>
inline void maxaj(T1 &x, T2 y) {
  x = (x < y ? y : x);
}
const int MAXN = 3005;
int sz[MAXN];
vector<int> e[MAXN];
int a[MAXN];
pair<int, long long> dp[MAXN][MAXN];
pair<int, long long> ndp[MAXN];
int m;
void dfs(int u, int v) {
  sz[v] = 1;
  dp[v][1] = pair<int, long long>(0, a[v]);
  for (int w : e[v]) {
    if (u != w) {
      dfs(v, w);
      for (int i = 0; i < sz[v] + sz[w] + 1; ++i) ndp[i] = {-1, 0};
      for (int i = 1; i < min(sz[v], m) + 1; ++i)
        for (int j = 1; j < min(sz[w], m) + 1; ++j) {
          long long v1 = dp[v][i].second;
          long long v2 = dp[w][j].second;
          maxaj(ndp[i + j - 1],
                pair<int, long long>(dp[v][i].first + dp[w][j].first, v1 + v2));
          maxaj(ndp[i + j],
                pair<int, long long>(dp[v][i].first + dp[w][j].first + (v2 > 0),
                                     v1));
        }
      for (int i = 0; i < sz[v] + sz[w] + 1; ++i) dp[v][i] = ndp[i];
      sz[v] += sz[w];
    }
  }
}
void solve() {
  int n;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    a[i] -= x;
    a[i] *= -1;
    e[i].clear();
  }
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(0, 0);
  cout << dp[0][m].first + (dp[0][m].second > 0) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}

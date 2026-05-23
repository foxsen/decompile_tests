#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<int>;
constexpr int N = 5010, INF = 1000000010;
int n, c[N], d[N], s[N];
int b, dp[N][2][N];
vi g[N];
void dfs(int u) {
  s[u] = 1;
  for (int i = 0; i <= n; ++i) dp[u][0][i] = dp[u][1][i] = INF;
  dp[u][0][0] = 0;
  dp[u][0][1] = c[u];
  dp[u][1][1] = c[u] - d[u];
  for (int v : g[u]) {
    dfs(v);
    for (int i = s[u]; i >= 0; --i)
      for (int j = 1; j <= s[v]; ++j) {
        dp[u][0][i + j] = min(dp[u][0][i + j], dp[u][0][i] + dp[v][0][j]);
        dp[u][1][i + j] =
            min(dp[u][1][i + j], dp[u][1][i] + min(dp[v][0][j], dp[v][1][j]));
      }
    s[u] += s[v];
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(20);
  cin >> n >> b;
  for (int i = 0; i < n; ++i) {
    cin >> c[i] >> d[i];
    if (i) {
      int u;
      cin >> u;
      --u;
      g[u].push_back(i);
    }
  }
  dfs(0);
  for (int ans = n; ans >= 0; --ans)
    if (min(dp[0][0][ans], dp[0][1][ans]) <= b) return cout << ans, 0;
}

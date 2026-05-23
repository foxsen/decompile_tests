#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000 + 50;
vector<int> edge[maxn];
int sub[maxn][maxn], fa[maxn][maxn];
long long n, ans, dp[maxn][maxn];
void dfs(int root, int k, int dad) {
  sub[root][k]++;
  fa[root][k] = dad;
  for (auto t : edge[k]) {
    if (t != dad) {
      dfs(root, t, k);
      sub[root][k] += sub[root][t];
    }
  }
}
long long DP(int a, int b) {
  if (a == b) return 0;
  if (dp[a][b] != -1) return dp[a][b];
  return dp[a][b] =
             sub[a][b] * sub[b][a] + max(DP(fa[a][b], a), DP(fa[b][a], b));
}
int main() {
  cin >> n;
  memset(dp, -1, sizeof(dp));
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) dfs(i, i, -1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i != j) ans = max(ans, DP(i, j));
  cout << ans << endl;
}

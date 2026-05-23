#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
vector<int> G[maxn];
int a[maxn];
long long mx = -1e18, cnt, dp[maxn];
void dfs(int v, int fa, int flag) {
  dp[v] = a[v];
  for (int i = G[v].size() - 1; i >= 0; i--) {
    int to = G[v][i];
    if (to == fa) continue;
    dfs(to, v, flag);
    if (dp[to] > 0) dp[v] += dp[to];
  }
  if (!flag)
    mx = max(mx, dp[v]);
  else if (dp[v] == mx)
    cnt++, dp[v] = 0;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    G[x].push_back(y);
    G[y].push_back(x);
  }
  dfs(1, 0, 0);
  dfs(1, 0, 1);
  printf("%lld %lld\n", cnt * mx, cnt);
  return 0;
}

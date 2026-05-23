#include <bits/stdc++.h>
using namespace std;
namespace FGF {
const int N = 5e5 + 5, mo = 1e9 + 7;
long long n, a[N], m, q, fa[N], vis[N], dep[N], ins[N], dp[N], sum[N];
vector<int> g[N];
void dfs(int u) {
  ins[u] = 1;
  for (auto v : g[u]) sum[v] = a[v] + sum[u], dfs(v), dep[u] = dep[v] + 1;
  m -= dep[u] * a[u];
}
void work() {
  scanf("%lld%lld%lld", &n, &q, &m);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1, u, v; i <= q; i++)
    scanf("%d%d", &u, &v), g[u].push_back(v), vis[v] = 1;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) sum[i] = a[i], dfs(i);
  bool fl = 1;
  for (int i = 1; i <= n; i++) fl &= ins[i];
  if (m < 0 || !fl) {
    puts("0");
    return;
  }
  dp[0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = sum[i]; j <= m; j++) (dp[j] += dp[j - sum[i]]) %= mo;
  printf("%lld", dp[m]);
}
}  // namespace FGF
int main() {
  FGF::work();
  return 0;
}

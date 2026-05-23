#include <bits/stdc++.h>
using namespace std;
int n, k, a[1000001], f[1000001], g[1000001], sz[1000001], fa;
vector<pair<char, int>> d[1000001];
char ch;
void dfs(int x, int pre) {
  f[x] = f[pre] + 1;
  g[x] = min(f[x], g[pre] + sz[pre]);
  if (sz[x]) f[x] = min(f[x], g[x] + 1);
  sort(d[x].begin(), d[x].end());
  for (auto nxt : d[x]) dfs(nxt.second, x), sz[x] += sz[nxt.second];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %c", &fa, &ch);
    d[fa].push_back(make_pair(ch, i));
  }
  scanf("%d", &k);
  for (int i = 1; i <= k; i++) scanf("%d", &a[i]), sz[a[i]] = 1;
  f[0] = -1, dfs(0, 0);
  for (int i = 1; i <= k; i++) printf("%d%c", f[a[i]], i < k ? ' ' : '\n');
  return 0;
}

#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const long long inff = 0x3f3f3f3f3f3f3f3f;
using namespace std;
const int N = 1e6 + 8;
int t, n, m, vis[N], VS[N], qw, ans, sz[N], ans1, VV[N];
pair<int, int> top[N];
string a[N], b[N];
vector<int> g[N];
int id(int x, int y) { return (x - 1) * m + y + 1; }
void dfs(int x, int y, int z) {
  if (vis[id(x, y)]) return;
  if (VS[id(x, y)] < 0) {
    sz[++qw] = VS[id(x, y)] - z;
    ans += sz[qw];
    VV[id(x, y)] = qw;
    for (int i(1); i <= (sz[qw] + 1); ++i) g[qw].push_back(0);
    return;
  }
  int tx = x, ty = y;
  VS[id(x, y)] = z;
  if (a[x][y] == 'U') tx--;
  if (a[x][y] == 'D') tx++;
  if (a[x][y] == 'L') ty--;
  if (a[x][y] == 'R') ty++;
  dfs(tx, ty, z - 1);
  VV[id(x, y)] = VV[id(tx, ty)];
  vis[id(x, y)] = vis[id(tx, ty)] + 1;
  vis[id(x, y)] %= sz[VV[id(x, y)]];
  if (!vis[id(x, y)]) vis[id(x, y)] = sz[VV[id(x, y)]];
  if (b[x][y] == '0' && !g[VV[id(x, y)]][vis[id(x, y)]])
    ans1++, g[VV[id(x, y)]][vis[id(x, y)]] = 1;
}
int main() {
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    scanf("%d", &n), scanf("%d", &m);
    ans1 = qw = ans = 0;
    for (int i(1); i <= (n); ++i) cin >> b[i];
    for (int i(1); i <= (n); ++i) cin >> a[i];
    for (int i(1); i <= (n); ++i)
      for (int j(0); j <= (m - 1); ++j)
        if (!VS[id(i, j)]) dfs(i, j, -1);
    for (int i(1); i <= (qw); ++i) sz[i] = 0, g[i].clear();
    for (int i(1); i <= (n * m); ++i) VV[i] = vis[i] = VS[i] = 0;
    printf("%d %d\n", ans, ans1);
  }
  return 0;
}

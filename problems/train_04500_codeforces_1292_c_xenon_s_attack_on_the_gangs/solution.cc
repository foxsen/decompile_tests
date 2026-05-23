#include <bits/stdc++.h>
using namespace std;
int n;
struct edge {
  int y, next;
} e[3010 << 1];
int first[3010], len = 0;
void buildroad(int x, int y) {
  e[++len] = (edge){y, first[x]};
  first[x] = len;
}
int fa[3010][3010], sz[3010][3010];
void init(int x, int p) {
  sz[p][x] = 1;
  for (int i = first[x]; i; i = e[i].next) {
    int y = e[i].y;
    if (y == fa[p][x]) continue;
    fa[p][y] = x;
    init(y, p);
    sz[p][x] += sz[p][y];
  }
}
long long f[3010][3010], ans = 0;
void dp(int x, int y) {
  if (x == y || f[x][y]) return;
  dp(fa[y][x], y);
  dp(x, fa[x][y]);
  f[x][y] = max(f[fa[y][x]][y], f[x][fa[x][y]]) + sz[y][x] * sz[x][y];
}
int main() {
  scanf("%d", &n);
  for (int i = 1, x, y; i < n; i++) {
    scanf("%d %d", &x, &y);
    buildroad(x, y);
    buildroad(y, x);
  }
  for (int i = 1; i <= n; i++) init(i, i);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (!f[i][j]) dp(i, j);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) ans = max(ans, f[i][j]);
  printf("%lld", ans);
}

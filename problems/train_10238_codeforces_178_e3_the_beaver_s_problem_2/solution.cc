#include <bits/stdc++.h>
const int N = 2008, u[4] = {1, 0, -1, 0}, v[4] = {0, 1, 0, -1};
int n, h, t, L, R, U, D, cnt[2], a[N][N], s[N][N], l[N], r[N], f[N * N],
    g[N * N], b[N][N];
void bfs(int x, int y) {
  h = 0, t = 1, L = R = x, U = D = y;
  f[1] = x, g[1] = y, b[x][y] = 1;
  while (h < t) {
    x = f[++h], y = g[h];
    L = L < x ? L : x, R = R > x ? R : x, D = D < y ? D : y, U = U > y ? U : y;
    l[y] = l[y] < x ? l[y] : x, r[y] = r[y] > x ? r[y] : x;
    for (int k = 0; k <= 3; k++) {
      int i = x + u[k], j = y + v[k];
      if (a[i][j] && !b[i][j]) b[i][j] = 1, f[++t] = i, g[t] = j;
    }
  }
  if (t < 50) return;
  x = (L + R) / 2, y = (U + D) / 2;
  double tmp, near = 1e8, far = 0;
  for (int j = D; j <= U; j++)
    tmp = (l[j] - x) * (l[j] - x) + (j - y) * (j - y),
    near = near < tmp ? near : tmp, far = far > tmp ? far : tmp,
    tmp = (r[j] - x) * (r[j] - x) + (j - y) * (j - y),
    near = near < tmp ? near : tmp, far = far > tmp ? far : tmp, l[j] = N,
    r[j] = 0;
  cnt[(far / near) > 1.8]++;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
  n -= 7;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      a[i][j] = s[i + 7][j + 7] - s[i + 7][j] - s[i][j + 7] + s[i][j] > 24;
  for (int i = 1; i <= n; i++) l[i] = N;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (a[i][j] && !b[i][j]) bfs(i, j);
  printf("%d %d\n", cnt[0], cnt[1]);
  return 0;
}

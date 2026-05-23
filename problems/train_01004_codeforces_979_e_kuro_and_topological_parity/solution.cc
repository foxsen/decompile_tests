#include <bits/stdc++.h>
int c[50 + 5], f[50 + 5][50 + 5][50 + 5], C[50 + 5][50 + 5], F[50 + 5][2],
    p[50 + 5];
inline void rw(int& x, int y) {
  if ((x += y) >= 1000000007) x -= 1000000007;
}
int main() {
  int n, m, i, j, k, l, x, ans = 0;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; ++i) scanf("%d", &c[i]);
  for (i = 0; i <= n; ++i) {
    for (C[i][0] = j = 1; j <= i; ++j)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 1000000007;
    for (j = 0; j <= i; ++j) rw(F[i][j & 1], C[i][j]);
  }
  for (p[0] = i = 1; i <= n; ++i) p[i] = (p[i - 1] + p[i - 1]) % 1000000007;
  f[0][0][0] = 1;
  for (i = 0; i < n; ++i)
    for (j = 0; j <= i; ++j)
      for (k = 0; k <= i; ++k)
        if (f[i][j][k]) {
          if (c[i + 1] != 0)
            rw(f[i + 1][j + 1][k],
               1LL * f[i][j][k] * F[k][0] % 1000000007 * p[i - k] % 1000000007),
                rw(f[i + 1][j][k], 1LL * f[i][j][k] * F[k][1] % 1000000007 *
                                       p[i - k] % 1000000007);
          if (c[i + 1] != 1)
            rw(f[i + 1][j][k + 1],
               1LL * f[i][j][k] * F[j][0] % 1000000007 * p[i - j] % 1000000007),
                rw(f[i + 1][j][k], 1LL * f[i][j][k] * F[j][1] % 1000000007 *
                                       p[i - j] % 1000000007);
        }
  for (i = 0; i <= n; ++i)
    for (j = 0; j <= n; ++j)
      if (((i + j) & 1) == m) rw(ans, f[n][i][j]);
  printf("%d", ans);
}

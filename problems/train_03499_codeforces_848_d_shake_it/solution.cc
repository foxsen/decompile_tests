#include <bits/stdc++.h>
using namespace std;
inline void Add(int& x, int y) { x = (x + y) % 1000000007; }
int i, j, k, n, m, p, q, f[60][60], g[60][60], F[60][60], t, inv[60];
int c;
int main() {
  scanf("%d%d", &n, &m);
  for (i = 2, inv[0] = inv[1] = 1; i <= n; i++)
    inv[i] =
        1ll * inv[1000000007 % i] * (1000000007 - 1000000007 / i) % 1000000007;
  f[0][1] = 1;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= i + 1; j++) {
      for (p = 0; p <= i - 1; p++) {
        for (q = j; q <= p + 1; q++)
          Add(g[i][j], 1ll * f[p][q] * f[i - 1 - p][j] % 1000000007);
        for (q = j + 1; q <= i - p; q++)
          Add(g[i][j], 1ll * f[p][j] * f[i - 1 - p][q] % 1000000007);
      }
      memset(F, 0, sizeof(F));
      for (k = 0; k <= n; k++)
        for (p = 1; p <= k + 1; p++) {
          c = 1;
          for (q = 1; k + q * i <= n; q++) {
            c = 1ll * c * (g[i][j] + q - 1) % 1000000007 * inv[q] % 1000000007;
            Add(F[k + q * i][p + q * j], 1ll * f[k][p] * c % 1000000007);
          }
        }
      for (k = 0; k <= n; k++)
        for (p = 1; p <= k + 1; p++) Add(f[k][p], F[k][p]);
    }
  cout << f[n][m] << endl;
  return 0;
}

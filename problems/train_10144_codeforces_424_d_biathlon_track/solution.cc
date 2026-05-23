#include <bits/stdc++.h>
using namespace std;
int n, m, t, tu, tp, td, pi, pii, pj, pjj;
int U[305][305], D[305][305], L[305][305], R[305][305], a[305][305];
int cal(int x, int y) {
  if (x == y) return tp;
  return x < y ? tu : td;
}
int main() {
  int ans = 0x7fffffff;
  scanf("%d%d%d", &n, &m, &t);
  scanf("%d%d%d", &tp, &tu, &td);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) scanf("%d", &a[i][j]);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      if (i != 1) U[i][j] = U[i - 1][j] + cal(a[i - 1][j], a[i][j]);
      if (i != 1) D[i][j] = D[i - 1][j] + cal(a[i][j], a[i - 1][j]);
      if (j != 1) L[i][j] = L[i][j - 1] + cal(a[i][j - 1], a[i][j]);
      if (j != 1) R[i][j] = R[i][j - 1] + cal(a[i][j], a[i][j - 1]);
    }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      for (int ii = i + 2; ii <= n; ++ii)
        for (int jj = j + 2; jj <= m; ++jj) {
          int lr = L[i][jj] - L[i][j] + R[ii][jj] - R[ii][j],
              ud = D[ii][j] - D[i][j] + U[ii][jj] - U[i][jj];
          if (ans > abs(lr + ud - t)) {
            pii = ii;
            pi = i;
            pjj = jj;
            pj = j;
            ans = abs(lr + ud - t);
          }
        }
  printf("%d %d %d %d\n", pi, pj, pii, pjj);
  return 0;
}

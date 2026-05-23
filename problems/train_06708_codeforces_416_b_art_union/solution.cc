#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j;
  scanf("%d%d", &n, &m);
  int a[n + 1][m + 1];
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) scanf("%d", &a[i][j]);
  int f[n + 1][m + 1];
  f[0][0] = a[0][0];
  for (i = 1; i < n; i++) {
    f[i][0] = f[i - 1][0] + a[i][0];
  }
  for (i = 1; i < m; i++) {
    f[0][i] = f[0][i - 1] + a[0][i];
    for (j = 1; j < n; j++) {
      f[j][i] = max(f[j - 1][i], f[j][i - 1]) + a[j][i];
    }
  }
  for (i = 0; i < n; i++) printf("%d ", f[i][m - 1]);
  return 0;
}

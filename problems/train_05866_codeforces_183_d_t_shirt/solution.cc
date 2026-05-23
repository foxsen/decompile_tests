#include <bits/stdc++.h>
using namespace std;
const int N = 3100, M = 310;
int n, m;
double f[M][N], tmp[N], delt[M], p[N][M], ans;
void upd(int x) {
  for (int j = 0; j <= n; ++j) tmp[j] = f[x][j], f[x][j] = 0;
  for (int j = 1; j <= n; ++j)
    f[x][j] = tmp[j - 1] * p[j][x] + f[x][j - 1] * (1 - p[j][x]);
  delt[x] -= f[x][n];
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1, x; j <= m; ++j) scanf("%lf", &p[i][j]), p[i][j] /= 1000.0;
  for (int i = 1; i <= m; ++i) {
    f[i][0] = 1;
    for (int j = 1; j <= n; ++j) f[i][j] = f[i][j - 1] * (1 - p[j][i]);
    delt[i] = 1.0 - f[i][n];
  }
  for (int i = 1; i <= n; ++i) {
    int tar = 0;
    for (int j = 1; j <= m; ++j)
      if (delt[tar] < delt[j]) tar = j;
    if (!tar) break;
    ans += delt[tar];
    upd(tar);
  }
  printf("%.12lf", ans);
  return 0;
}

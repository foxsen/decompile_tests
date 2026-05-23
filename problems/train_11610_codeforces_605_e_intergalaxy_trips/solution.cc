#include <bits/stdc++.h>
const int N = 1000 + 7;
int n;
double p[N][N], f[N], g[N], h[N][N];
int vis[N], top[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) scanf("%lf", p[i] + j), p[i][j] /= 100;
  vis[top[1] = n] = 1;
  for (int j = 1; j <= n; ++j) h[j][1] = 1 - p[j][n];
  for (int i = 2; i <= n; ++i) {
    int k = 0;
    for (int j = 1; j <= n; ++j) {
      if (vis[j]) continue;
      g[j] += f[top[i - 1]] * h[j][i - 2] * p[j][top[i - 1]];
      f[j] = (g[j] + 1) / (1 - h[j][i - 1]);
      if (!k || f[j] < f[k]) k = j;
    }
    vis[top[i] = k] = 1;
    for (int j = 1; j <= n; ++j) h[j][i] = h[j][i - 1] * (1 - p[j][k]);
  }
  printf("%.15lf", f[1]);
  return 0;
}

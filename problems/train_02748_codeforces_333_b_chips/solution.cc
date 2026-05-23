#include <bits/stdc++.h>
bool g[1111][1111];
int main() {
  int n, m;
  memset(g, false, sizeof(g));
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u][v] = true;
  }
  int count = 0;
  for (int i = 2; i < n; i++) {
    bool flag = false;
    for (int j = 1; j <= n; j++)
      if (g[i][j] == true) {
        flag = true;
        break;
      }
    if (flag) continue;
    count++;
  }
  for (int j = 2; j < n; j++) {
    bool flag = false;
    for (int i = 1; i <= n; i++)
      if (g[i][j]) {
        flag = true;
        break;
      }
    if (flag) continue;
    count++;
  }
  if (n & 1) {
    int i, j;
    for (i = 1; i <= n; i++)
      if (g[i][n / 2 + 1]) break;
    for (j = 1; j <= n; j++)
      if (g[n / 2 + 1][j]) break;
    if (i > n && j > n)
      if (count) count--;
  }
  printf("%d\n", count);
  return 0;
}

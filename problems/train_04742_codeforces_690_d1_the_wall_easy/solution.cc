#include <bits/stdc++.h>
char map[100][100];
int n, m, vis[100][100] = {};
int mx[] = {-1, 0, 0, 1};
int my[] = {0, -1, 1, 0};
void solve(int i, int a, int counter) {
  if (i < 0 || a < 0 || i >= n || a >= m || map[i][a] == '.' ||
      (vis[i][a] != 0 && vis[i][a] <= counter))
    return;
  vis[i][a] = counter;
  for (int j = 0; j < 4; ++j) {
    solve(i + mx[j], a + my[j], counter);
  }
  return;
}
int main() {
  int i, a, c[10000] = {}, x[10000], y[10000], counter = 1;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; ++i) scanf("%s", map[i]);
  for (i = 0; i < n; ++i) {
    for (a = 0; a < m; ++a) {
      if (map[i][a] == 'B' && !vis[i][a]) {
        solve(i, a, counter);
        c[counter] = 1;
        ++counter;
      }
    }
  }
  counter = 0;
  int ln = -1;
  for (i = 0; i < 10000; ++i) {
    if (c[i]) ++counter;
  }
  printf("%d\n", counter);
}

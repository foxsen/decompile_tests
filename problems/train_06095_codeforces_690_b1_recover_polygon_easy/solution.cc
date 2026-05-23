#include <bits/stdc++.h>
const int maxn = 1e2 + 10;
using namespace std;
int n, m, x[2], y[2];
char a[maxn][maxn];
bool check() {
  int i, j;
  for (i = 0; i <= 1; i++)
    for (j = 0; j <= 1; j++)
      if (a[x[i]][y[j]] != '1') return false;
  for (i = x[0] + 1; i <= x[1] - 1; i++)
    if (a[i][y[0]] != '2') return false;
  for (i = x[0] + 1; i <= x[1] - 1; i++)
    if (a[i][y[1]] != '2') return false;
  for (i = y[0] + 1; i <= y[1] - 1; i++)
    if (a[x[0]][i] != '2') return false;
  for (i = y[0] + 1; i <= y[1] - 1; i++)
    if (a[x[1]][i] != '2') return false;
  for (i = x[0] + 1; i <= x[1] - 1; i++)
    for (j = y[0] + 1; j <= y[1] - 1; j++)
      if (a[i][j] != '4') return false;
  return true;
}
int main() {
  int i, j, k, t;
  scanf("%d", &n);
  for (i = 0; i <= n - 1; i++) scanf("%s", a[i]);
  x[0] = y[0] = 0x3f3f3f3f, x[1] = y[1] = -1;
  for (i = 0; i <= n - 1; i++)
    for (j = 0; j <= n - 1; j++)
      if (a[i][j] != '0') {
        x[0] = min(x[0], i), x[1] = max(x[1], i), y[0] = min(y[0], j),
        y[1] = max(y[1], j);
      }
  if (check())
    puts("Yes");
  else
    puts("No");
  return 0;
}

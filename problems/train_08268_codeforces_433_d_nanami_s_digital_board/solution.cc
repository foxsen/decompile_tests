#include <bits/stdc++.h>
using namespace std;
int i, j, k, m, n, q, x, y;
int u[1090][1090], d[1090][1090], l[1090][1090], r[1090][1090];
int a[1090][1090];
void precacu() {
  int i, j;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (a[i][j]) {
        if (a[i - 1][j])
          u[i][j] = u[i - 1][j];
        else
          u[i][j] = i;
        if (a[i][j - 1])
          l[i][j] = l[i][j - 1];
        else
          l[i][j] = j;
      }
  for (i = n; i >= 1; i--)
    for (j = m; j >= 1; j--)
      if (a[i][j]) {
        if (a[i + 1][j])
          d[i][j] = d[i + 1][j];
        else
          d[i][j] = i;
        if (a[i][j + 1])
          r[i][j] = r[i][j + 1];
        else
          r[i][j] = j;
      }
}
void op1() {
  a[x][y] ^= 1;
  if (a[x][y]) {
    if (a[x - 1][y])
      u[x][y] = u[x - 1][y];
    else
      u[x][y] = x;
    if (a[x + 1][y])
      d[x][y] = d[x + 1][y];
    else
      d[x][y] = x;
    if (a[x][y - 1])
      l[x][y] = l[x][y - 1];
    else
      l[x][y] = y;
    if (a[x][y + 1])
      r[x][y] = r[x][y + 1];
    else
      r[x][y] = y;
    i = y - 1;
    while (i && r[x][i] == y - 1) r[x][i] = r[x][y], i--;
    i = y + 1;
    while (i <= m && l[x][i] == y + 1) l[x][i] = l[x][y], i++;
    i = x - 1;
    while (i && d[i][y] == x - 1) d[i][y] = d[x][y], i--;
    i = x + 1;
    while (i <= n && u[i][y] == x + 1) u[i][y] = u[x][y], i++;
  } else {
    u[x][y] = d[x][y] = l[x][y] = r[x][y] = 0;
    i = y - 1;
    while (i && r[x][i] >= y) r[x][i] = y - 1, i--;
    i = y + 1;
    while (i <= m && l[x][i] <= y) l[x][i] = y + 1, i++;
    i = x - 1;
    while (i && d[i][y] >= x) d[i][y] = x - 1, i--;
    i = x + 1;
    while (i <= n && u[i][y] <= x) u[i][y] = x + 1, i++;
  }
}
int op2() {
  int ans = 0;
  if (a[x][y] == 0) return ans;
  int up = u[x][y], down = d[x][y];
  ans = max(ans, down - up + 1);
  for (i = y + 1; i <= m; i++) {
    if (!a[x][i]) break;
    up = max(up, u[x][i]);
    down = min(down, d[x][i]);
    ans = max(ans, (down - up + 1) * (i - y + 1));
  }
  up = u[x][y], down = d[x][y];
  for (i = y - 1; i >= 1; i--) {
    if (!a[x][i]) break;
    up = max(up, u[x][i]);
    down = min(down, d[x][i]);
    ans = max(ans, (down - up + 1) * (-i + y + 1));
  }
  int left = l[x][y], right = r[x][y];
  ans = max(ans, (right - left + 1));
  for (i = x + 1; i <= n; i++) {
    if (!a[i][y]) break;
    left = max(left, l[i][y]);
    right = min(right, r[i][y]);
    ans = max(ans, (right - left + 1) * (i - x + 1));
  }
  left = l[x][y], right = r[x][y];
  for (i = x - 1; i >= 1; i--) {
    if (!a[i][y]) break;
    left = max(left, l[i][y]);
    right = min(right, r[i][y]);
    ans = max(ans, (right - left + 1) * (-i + x + 1));
  }
  return ans;
}
int main() {
  cin >> n >> m >> q;
  memset(a, 0, sizeof(a));
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  precacu();
  int op;
  while (q--) {
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1) op1();
    if (op == 2) printf("%d\n", op2());
  }
  return 0;
}

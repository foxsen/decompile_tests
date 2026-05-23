#include <bits/stdc++.h>
using namespace std;
int n, k, r[2005], a[2005][2005], c[2005], row[2005][2005], column[2005][2005],
    ans;
char ch;
int sum(int x, int y, int n, int m) {
  return a[x][y] - a[n - 1][y] - a[x][m - 1] + a[n - 1][m - 1];
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      cin >> ch;
      a[i][j] = ch == 'B' ? 0 : 1;
      a[i][j] = a[i][j] + a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
      r[i] += ch == 'B' ? 0 : 1;
      c[j] += ch == 'B' ? 0 : 1;
    }
  for (int i = 1; i <= n; i++) r[i] = (r[i] == n) + r[i - 1];
  for (int j = 1; j <= n; j++) c[j] = (c[j] == n) + c[j - 1];
  for (int i = 1; i <= n; i++)
    for (int j = k; j <= n; j++)
      row[i][j] =
          (sum(i, n, i, 1) - sum(i, j, i, j - k + 1) == n - k) + row[i - 1][j];
  for (int i = k; i <= n; i++)
    for (int j = 1; j <= n; j++)
      column[i][j] = (sum(n, j, 1, j) - sum(i, j, i - k + 1, j) == n - k) +
                     column[i][j - 1];
  for (int i = k; i <= n; i++)
    for (int j = k; j <= n; j++) {
      int res = row[i][j] - row[i - k][j];
      res = res + column[i][j] - column[i][j - k];
      res = res + r[n] - r[i] + r[i - k];
      res = res + c[n] - c[j] + c[j - k];
      ans = max(ans, res);
    }
  cout << ans;
  return 0;
}

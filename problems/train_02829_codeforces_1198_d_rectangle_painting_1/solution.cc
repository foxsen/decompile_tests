#include <bits/stdc++.h>
using namespace std;
int k, i, n, j, ii, jj, f[51][51], d[51][51][51][51], val;
char c[51][51];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) cin >> c[i][j];
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + (c[i][j] == '#');
  auto check = [&](int x, int y, int xx, int yy) {
    return f[xx][yy] - f[x - 1][yy] - f[xx][y - 1] + f[x - 1][y - 1];
  };
  for (i = n; i >= 1; i--)
    for (j = n; j >= 1; j--)
      for (ii = i; ii <= n; ii++)
        for (jj = j; jj <= n; jj++) {
          if (check(i, j, ii, jj) == 0) {
            d[i][j][ii][jj] = 0;
            continue;
          }
          val = max(jj - j + 1, ii - i + 1);
          for (k = j; k < jj; k++)
            val = min(val, d[i][j][ii][k] + d[i][k + 1][ii][jj]);
          for (k = i; k < ii; k++)
            val = min(val, d[i][j][k][jj] + d[k + 1][j][ii][jj]);
          d[i][j][ii][jj] = val;
        }
  cout << d[1][1][n][n];
}

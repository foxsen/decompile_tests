#include <bits/stdc++.h>
using namespace std;
int n, m = 3000001, i, j, k, ans, l, y, x, z, c, t;
int a[101][101] = {0}, b[101];
bool can = false;
int main() {
  std::ios_base::sync_with_stdio(false);
  cin >> n >> m;
  if (m < 3) {
    cout << -1;
    return 0;
  }
  for (i = 1; i <= n; i++) cin >> b[i];
  for (i = 0; i < m; i++) {
    cin >> x >> y;
    a[x][y] = a[y][x] = 1;
  }
  m = 3000001;
  for (i = 1; i < n - 1; i++)
    for (j = i + 1; j < n; j++)
      for (k = j + 1; k <= n; k++)
        if (a[i][j] && a[j][k] && a[i][k]) m = min(m, b[i] + b[j] + b[k]);
  if (m == 3000001) m = -1;
  cout << m;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
bool a[2002][2002];
vector<int> vec;
int main() {
  long long x, y, i, t, n, m, ans = 0;
  cin >> n >> m;
  for (i = 1; i <= m; i++) {
    cin >> x >> y;
    if (a[x][y])
      a[x][y] = 0;
    else
      a[x][y] = 1;
    if (ans == 0) {
      if (a[x][y] && a[x][y + 1] && a[x][y + 2] && a[x + 1][y] &&
          a[x + 1][y + 1] && a[x + 1][y + 2] && a[x + 2][y] &&
          a[x + 2][y + 1] && a[x + 2][y + 2])
        ans = i;
      if (a[x][y] && a[x][y - 1] && a[x][y + 1] && a[x + 1][y] &&
          a[x + 1][y - 1] && a[x + 1][y + 1] && a[x + 2][y] &&
          a[x + 2][y - 1] && a[x + 2][y + 1])
        ans = i;
      if (a[x][y] && a[x][y - 1] && a[x][y - 2] && a[x + 1][y] &&
          a[x + 1][y - 1] && a[x + 1][y - 2] && a[x + 2][y] &&
          a[x + 2][y - 1] && a[x + 2][y - 2])
        ans = i;
      if (a[x][y] && a[x][y + 1] && a[x][y + 2] && a[x - 1][y] &&
          a[x - 1][y + 1] && a[x - 1][y + 2] && a[x + 1][y] &&
          a[x + 1][y + 1] && a[x + 1][y + 2])
        ans = i;
      if (a[x][y] && a[x][y - 1] && a[x][y + 1] && a[x - 1][y] &&
          a[x - 1][y - 1] && a[x - 1][y + 1] && a[x + 1][y] &&
          a[x + 1][y - 1] && a[x + 1][y + 1])
        ans = i;
      if (a[x][y] && a[x][y - 1] && a[x][y - 2] && a[x + 1][y] &&
          a[x + 1][y - 1] && a[x + 1][y - 2] && a[x - 1][y] &&
          a[x - 1][y - 1] && a[x - 1][y - 2])
        ans = i;
      if (a[x][y] && a[x][y + 1] && a[x][y + 2] && a[x - 1][y] &&
          a[x - 1][y + 1] && a[x - 1][y + 2] && a[x - 2][y] &&
          a[x - 2][y + 1] && a[x - 2][y + 2])
        ans = i;
      if (a[x][y] && a[x][y - 1] && a[x][y + 1] && a[x - 1][y] &&
          a[x - 1][y - 1] && a[x - 1][y + 1] && a[x - 2][y] &&
          a[x - 2][y - 1] && a[x - 2][y + 1])
        ans = i;
      if (a[x][y] && a[x][y - 1] && a[x][y - 2] && a[x - 1][y] &&
          a[x - 1][y - 1] && a[x - 1][y - 2] && a[x - 2][y] &&
          a[x - 2][y - 1] && a[x - 2][y - 2])
        ans = i;
    }
  }
  if (ans == 0)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}

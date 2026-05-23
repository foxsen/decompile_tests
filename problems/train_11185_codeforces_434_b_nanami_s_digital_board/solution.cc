#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int arr[1001][1001], up[1001][1001], d[1001][1001], r[1001][1001],
    l[1001][1001];
int main() {
  cin >> n >> m >> q;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      up[i][j] = arr[i][j];
      d[i][j] = arr[i][j];
      r[i][j] = arr[i][j];
      l[i][j] = arr[i][j];
    }
  for (int i = 1; i < n; i++)
    for (int j = 0; j < m; j++)
      if (up[i][j] == 1) up[i][j] += up[i - 1][j];
  for (int i = n - 2; i >= 0; i--)
    for (int j = 0; j < m; j++)
      if (d[i][j] == 1) d[i][j] += d[i + 1][j];
  for (int i = 1; i < m; i++)
    for (int j = 0; j < n; j++)
      if (l[j][i] == 1) l[j][i] += l[j][i - 1];
  for (int i = m - 2; i >= 0; i--)
    for (int j = 0; j < n; j++)
      if (r[j][i] == 1) r[j][i] += r[j][i + 1];
  for (int i = 0; i < q; i++) {
    int op, x, y;
    cin >> op >> x >> y;
    x--;
    y--;
    if (op == 1) {
      if (up[x][y] == 0 && x > 0)
        up[x][y] = up[x - 1][y] + 1;
      else if (up[x][y] == 0)
        up[x][y] = 1;
      else
        up[x][y] = 0;
      for (int i = x + 1; i < n; i++)
        if (up[i][y] > 0) up[i][y] = up[i - 1][y] + 1;
      if (d[x][y] == 0 && x < n - 1)
        d[x][y] = d[x + 1][y] + 1;
      else if (d[x][y] == 0)
        d[x][y] = 1;
      else
        d[x][y] = 0;
      for (int i = x - 1; i >= 0; i--)
        if (d[i][y] > 0) d[i][y] = d[i + 1][y] + 1;
      if (l[x][y] == 0 && y > 0)
        l[x][y] = l[x][y - 1] + 1;
      else if (l[x][y] == 0)
        l[x][y] = 1;
      else
        l[x][y] = 0;
      for (int j = y + 1; j < m; j++)
        if (l[x][j] > 0) l[x][j] = l[x][j - 1] + 1;
      if (r[x][y] == 0 && y < m - 1)
        r[x][y] = r[x][y + 1] + 1;
      else if (r[x][y] == 0)
        r[x][y] = 1;
      else
        r[x][y] = 0;
      for (int j = y - 1; j >= 0; j--)
        if (r[x][j] > 0) r[x][j] = r[x][j + 1] + 1;
    } else {
      int he = up[x][y];
      int le = y, re = y, ans = he;
      for (int i = he; i > 0; i--) {
        while (le > 0 && up[x][le - 1] >= i) le--;
        while (re < m - 1 && up[x][re + 1] >= i) re++;
        ans = max(ans, (re - le + 1) * i);
      }
      he = d[x][y];
      le = y, re = y;
      for (int i = he; i > 0; i--) {
        while (le > 0 && d[x][le - 1] >= i) le--;
        while (re < m - 1 && d[x][re + 1] >= i) re++;
        ans = max(ans, (re - le + 1) * i);
      }
      he = l[x][y];
      le = x, re = x;
      for (int i = he; i > 0; i--) {
        while (le < n - 1 && l[le + 1][y] >= i) le++;
        while (re > 0 && l[re - 1][y] >= i) re--;
        ans = max(ans, (le - re + 1) * i);
      }
      he = r[x][y];
      le = x, re = x;
      for (int i = he; i > 0; i--) {
        while (le < n - 1 && r[le + 1][y] >= i) le++;
        while (re > 0 && r[re - 1][y] >= i) re--;
        ans = max(ans, (le - re + 1) * i);
      }
      cout << ans << endl;
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
int n, m;
int pnt[N * 4], last;
char tab[N][N], a[N][N];
int find(int x) {
  if (x != pnt[x]) pnt[x] = find(pnt[x]);
  return pnt[x];
}
int id(int x, int y, int d) { return (x * m + y) * 4 + d; }
void add(int x, int y) {
  pnt[id(x, y, 0)] = x - 1 >= 0 ? id(x - 1, y, 0) : last;
  pnt[id(x, y, 1)] = x + 1 < n ? id(x + 1, y, 1) : last;
  pnt[id(x, y, 2)] = y - 1 >= 0 ? id(x, y - 1, 2) : last;
  pnt[id(x, y, 3)] = y + 1 < m ? id(x, y + 1, 3) : last;
}
void solve() {
  int ans = 0, cnt;
  last = n * m * 4;
  for (int i = 0; i < n; ++i) scanf("%s", tab[i]);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (tab[i][j] == '.') continue;
      for (int u = 0; u <= last; ++u) pnt[u] = u;
      for (int u = 0; u < n; ++u)
        for (int v = 0; v < m; ++v) {
          a[u][v] = tab[u][v];
          if (a[u][v] == '.') add(u, v);
        }
      int x = i, y = j, t = 0;
      while (1) {
        t++;
        int dir;
        if (a[x][y] == 'U') dir = 0;
        if (a[x][y] == 'D') dir = 1;
        if (a[x][y] == 'L') dir = 2;
        if (a[x][y] == 'R') dir = 3;
        add(x, y);
        int p = find(id(x, y, dir));
        if (p == last) break;
        x = p / 4 / m;
        y = p / 4 % m;
      }
      if (ans < t)
        ans = t, cnt = 1;
      else if (ans == t)
        cnt++;
    }
  printf("%d %d\n", ans, cnt);
}
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    solve();
  }
  return 0;
}

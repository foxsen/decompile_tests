#include <bits/stdc++.h>
using namespace std;
const int mn = 1005;
const int mod = 1e9 + 7;
int n, m;
int ans;
char s[mn][mn];
int up[mn][mn];
int down[mn][mn];
bool vis[mn][mn];
void draw(int x0, int x1, int y0, int y1) {
  for (int i = x0; i <= x1; i++)
    for (int j = y0; j <= y1; j++) vis[i][j] = 1;
}
inline int delta(int x, int y) { return down[x][y] - up[x][y]; }
bool judge(int x, int y) {
  int delt = delta(x, y);
  int u = up[x][y] - 1;
  int d = down[x][y] + 1;
  if (u > 0 && d <= n) {
    if (delta(u, y) >= delt && delta(d, y) >= delt) return 1;
  }
  return 0;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      if (s[i][j] != s[i - 1][j])
        up[i][j] = i;
      else
        up[i][j] = up[i - 1][j];
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = n; i; i--) {
      if (s[i][j] != s[i + 1][j])
        down[i][j] = i;
      else
        down[i][j] = down[i + 1][j];
    }
  }
  for (int i = 2; i < n; i++) {
    for (int j = 1; j <= m; j++) {
      if (vis[i][j]) continue;
      if (judge(i, j)) {
        int curr = 1;
        int y1 = j + 1;
        int u = up[i][j] - 1;
        int d = down[i][j] + 1;
        while (y1 <= m && judge(i, y1) && up[i][y1] == up[i][j] &&
               down[i][y1] == down[i][j] && s[u][j] == s[u][y1] &&
               s[i][j] == s[i][y1] && s[d][j] == s[d][y1]) {
          y1++;
          curr += (y1 - j);
        }
        ans += curr;
        draw(up[i][j], down[i][j], j, y1 - 1);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}

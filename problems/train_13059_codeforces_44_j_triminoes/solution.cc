#include <bits/stdc++.h>
int dx[] = {-1, 0, 0, 1, 1, 2, 2, 3}, dy[] = {0, 1, -1, 1, -1, 1, -1, 0}, n, m;
char str[1005][1005];
inline void fail() {
  puts("NO");
  exit(0);
}
inline void paint(int x, int y, bool f) {
  for (int i = 0; i < 4; i++) {
    str[x][y] = str[x + f][y + !f] = str[x + f + f][y + !f + !f] = 'a' + i;
    bool g = true;
    for (int j = 0; j < 8 && g; j++) {
      int newx = x + (f ? dx : dy)[j], newy = y + (f ? dy : dx)[j];
      if (newx >= 0 && newx < n && newy >= 0 && newy < m &&
          str[newx][newy] == 'a' + i)
        g = false;
    }
    if (g) return;
  }
  fail();
}
int main() {
  int w = 0, b = 0;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", str[i]);
    for (int j = 0; j < m; j++) {
      if (str[i][j] == '.') continue;
      (str[i][j] == 'w' ? w : b)++;
      str[i][j] = str[i][j] - 'a' + 'A';
    }
  }
  if (w != (b << 1)) fail();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (str[i][j] == 'B') fail();
      if (str[i][j] != 'W') continue;
      if (str[i][j + 1] == 'B') {
        if (str[i][j + 2] != 'W') fail();
        paint(i, j, false);
      } else {
        if (str[i + 1][j] != 'B' || str[i + 2][j] != 'W') fail();
        paint(i, j, true);
      }
    }
  }
  puts("YES");
  for (int i = 0; i < n; i++) puts(str[i]);
  return 0;
}

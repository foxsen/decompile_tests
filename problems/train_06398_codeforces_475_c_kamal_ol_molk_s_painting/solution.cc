#include <bits/stdc++.h>
using namespace std;
int getint() {
  int s = 0, o = 1;
  char c;
  for (c = getchar(); c < '0' || c > '9'; c = getchar())
    if (c == '-') o = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) s *= 10, s += c - '0';
  return s * o;
}
const int maxn = 1010;
int a[maxn][maxn], b[maxn][maxn], n, m, len;
inline bool all(int x, int y, int lx, int ly) {
  for (int i = x; i < x + lx; ++i)
    for (int j = y; j < y + ly; ++j)
      if (!a[i][j]) return 0;
  return 1;
}
inline void paint(int x, int y, int lx, int ly) {
  for (int i = x; i < x + lx; ++i)
    for (int j = y; j < y + ly; ++j) b[i][j] = 1;
}
inline int chk(int x, int y, int lx, int ly) {
  if (!all(x, y, lx, ly)) return 2;
  memset(b, 0, sizeof(b));
  paint(x, y, lx, ly);
  for (int t = 0;;) {
    int can[2];
    can[0] = (y + ly < m) & all(x, y + ly, lx, 1);
    can[1] = (x + lx < n) & all(x + lx, y, 1, ly);
    if (!can[0] && !can[1]) break;
    if (can[t]) {
      if (t == 0) {
        for (int i = 0; i < x; i++)
          if (a[i][y + ly] == 1) return 0;
        paint(x, y + ly, lx, 1);
        ++y;
      } else {
        for (int i = 0; i < y; i++)
          if (a[x + lx][i] == 1) return 0;
        paint(x + lx, y, 1, ly);
        ++x;
      }
      continue;
    }
    if (can[t ^ 1]) {
      t ^= 1;
      if (t == 0) {
        for (int i = 0; i < x; i++)
          if (a[i][y + ly] == 1) return 0;
        paint(x, y + ly, lx, 1);
        ++y;
      } else {
        for (int i = 0; i < y; i++)
          if (a[x + lx][i] == 1) return 0;
        paint(x + lx, y, 1, ly);
        ++x;
      }
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (a[i][j] != b[i][j]) return 2;
  return 1;
}
int work() {
  int x, y, lenx, l, r;
  int fg = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      if (a[i][j]) {
        x = i, y = j, fg = 1;
        break;
      }
    if (fg) break;
  }
  lenx = 1;
  while (x + lenx < n && a[x + lenx][y] == 1) ++lenx;
  l = 0, r = 1;
  while (y + r < m && a[x][y + r] == 1) ++r;
  ++r;
  while (l + 1 < r) {
    int mid = (l + r) >> 1;
    if (chk(x, y, lenx, mid) == 0)
      l = mid;
    else
      r = mid;
  }
  if (chk(x, y, lenx, r) == 2)
    return n * m * 2;
  else
    return lenx * r;
}
char s[1001];
int main(int argc, char const *argv[]) {
  n = getint(), m = getint(), len = max(n, m);
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    for (int j = 0; j < m; j++) a[i][j] = s[j] == 'X';
  }
  int r = work();
  for (int i = 0; i < len; i++)
    for (int j = 0; j < len; j++)
      if (i < j) swap(a[i][j], a[j][i]);
  swap(n, m);
  r = min(r, work());
  printf("%d\n", r > n * m ? -1 : r);
  return 0;
}

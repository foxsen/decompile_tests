#include <bits/stdc++.h>
using namespace std;
const int inf = 2147483647;
const double pi = acos(-1.0);
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
int main() {
  int n = read(), m = read();
  while (n--) {
    int s = read(), f = read(), t = read(), ans = t;
    if (s == f) {
      printf("%d\n", t);
      continue;
    }
    int x = t % (2 * m - 2), c, o;
    if (x <= m - 2)
      c = x + 1, o = 0;
    else
      c = 2 * m - 1 - x, o = 1;
    if (o == 0) {
      if (s >= c)
        ans += (s - c), o = 0;
      else
        ans += (m - c + m - s), o = 1;
    } else {
      if (s <= c)
        ans += (c - s), o = 1;
      else
        ans += (c - 1 + s - 1), o = 0;
    }
    c = s;
    if (o == 0) {
      if (f >= c)
        ans += (f - c), o = 0;
      else
        ans += (m - c + m - f), o = 1;
    } else {
      if (f <= c)
        ans += (c - f), o = 1;
      else
        ans += (c - 1 + f - 1), o = 0;
    }
    printf("%d\n", ans);
  }
}

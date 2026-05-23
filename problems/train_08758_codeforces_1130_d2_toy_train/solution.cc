#include <bits/stdc++.h>
using namespace std;
char getc() {
  char c = getchar();
  while ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z') && (c < '0' || c > '9'))
    c = getchar();
  return c;
}
int gcd(int n, int m) { return m == 0 ? n : gcd(m, n % m); }
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return x * f;
}
int n, m;
int dis(int x, int y) {
  if (x <= y)
    return y - x;
  else
    return n - x + y;
}
struct data {
  int x, y;
  bool operator<(const data& a) const {
    return x < a.x || x == a.x && dis(x, y) > dis(a.x, a.y);
  }
} a[20010 << 1];
signed main() {
  n = read(), m = read();
  for (int i = 1; i <= m; i++) a[i].x = read(), a[i].y = read();
  sort(a + 1, a + m + 1);
  for (int i = 1; i <= n; i++) {
    int ans = 0;
    for (int j = 1; j <= m; j++) {
      int t = j;
      while (t < m && a[t + 1].x == a[j].x) t++;
      ans = max(ans, dis(i, a[t].x) + dis(a[t].x, a[t].y) + (t - j) * n);
      j = t;
    }
    printf("%d ", ans);
  }
  return 0;
}

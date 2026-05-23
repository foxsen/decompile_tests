#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y;
  friend bool operator<(const point &p, const point &q) {
    if (p.x != q.x) return p.x < q.x;
    return p.y < q.y;
  }
  void read() { scanf("%d%d", &x, &y); }
  point() {}
  point(int x, int y) : x(x), y(y) {}
} a[200010], ans[210];
int n;
int find(int id, point p) {
  int lt = n - id - 50, rt = n - id + 50, mid;
  if (lt < 1) lt = 1;
  if (rt > n) rt = n;
  while (lt <= rt) {
    mid = (lt + rt) / 2;
    if (a[mid].x == p.x && a[mid].y == p.y) return mid;
    if (a[mid].x > p.x)
      rt = mid - 1;
    else if (a[mid].x < p.x)
      lt = mid + 1;
    else if (a[mid].y > p.y)
      rt = mid - 1;
    else
      lt = mid + 1;
  }
  return 0;
}
int main() {
  int m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) a[i].read();
  if (n <= m) {
    printf("-1\n");
    return 0;
  }
  sort(a + 1, a + n + 1);
  int cnt = 0;
  for (int i = 1; i <= m + 1; i++) {
    for (int j = max(n - m, i); j <= n; j++) {
      if (i - 1 + n - j > m) continue;
      int x = a[i].x + a[j].x;
      int y = a[i].y + a[j].y;
      int tot = 0;
      for (int k = 1; k <= n && tot <= m; k++) {
        if (!find(k, point(x - a[k].x, y - a[k].y))) tot++;
      }
      if (tot <= m) ans[++cnt] = point(x, y);
    }
  }
  sort(ans + 1, ans + cnt + 1);
  if (cnt == 0) {
    printf("0\n");
    return 0;
  }
  m = cnt;
  cnt = 1;
  for (int i = 2; i <= m; i++)
    if (!(ans[i].x == ans[cnt].x && ans[i].y == ans[cnt].y))
      ans[++cnt] = ans[i];
  printf("%d\n", cnt);
  for (int i = 1; i <= cnt; i++)
    printf("%.10lf %.10lf\n", ans[i].x / 2.0, ans[i].y / 2.0);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n;
struct rect {
  int x1, y1, x2, y2;
} a[1005];
bool solve(int l, int r) {
  if (l == r) return true;
  sort(a + l, a + r + 1,
       [&](const rect &x, const rect &y) -> bool { return x.x1 < y.x1; });
  for (int i = l, mx = 0; i < r; ++i) {
    mx = max(mx, a[i].x2);
    if (a[i + 1].x1 >= mx) return solve(l, i) && solve(i + 1, r);
  }
  sort(a + l, a + r + 1,
       [&](const rect &x, const rect &y) -> bool { return x.y1 < y.y1; });
  for (int i = l, mx = 0; i < r; ++i) {
    mx = max(mx, a[i].y2);
    if (a[i + 1].y1 >= mx) return solve(l, i) && solve(i + 1, r);
  }
  return false;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
  puts(solve(1, n) ? "YES" : "NO");
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long n;
struct node {
  long long x, y;
} d[100005];
bool cmp(node x, node y) { return x.x < y.x; }
long long a[100005][15];
long long chk(long long x) {
  for (long long i = 1, j = 1; i <= n; i++) {
    while (j < n && d[j + 1].x - d[i].x <= x) j++;
    if (max(a[i - 1][1], a[j + 1][3]) - min(a[i - 1][2], a[j + 1][4]) <= x)
      return 1;
  }
  return 0;
}
signed main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    long long x, y;
    scanf("%lld%lld", &x, &y);
    d[i].x = x - y, d[i].y = x + y;
  }
  sort(d + 1, d + n + 1, cmp);
  a[0][1] = (-1ll) << 40, a[0][2] = 1ll << 40, a[n + 1][3] = (-1ll) << 40,
  a[n + 1][4] = 1ll << 40;
  for (long long i = 1; i <= n; i++) {
    a[i][1] = max(a[i - 1][1], d[i].y), a[i][2] = min(a[i - 1][2], d[i].y);
    a[n - i + 1][3] = max(a[n - i + 2][3], d[n - i + 1].y),
              a[n - i + 1][4] = min(a[n - i + 2][4], d[n - i + 1].y);
  }
  long long l = 0, r = 1ll << 40, mid;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (chk(mid)) {
      r = mid - 1;
    } else
      l = mid + 1;
  }
  printf("%.6lf", l / 2.0);
  return 0;
}

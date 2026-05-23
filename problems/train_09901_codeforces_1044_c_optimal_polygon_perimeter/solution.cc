#include <bits/stdc++.h>
using namespace std;
const int maxn = 312345;
int x[maxn], y[maxn], n;
inline int dis(pair<int, int> a, pair<int, int> b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}
int main() {
  scanf("%d", &n);
  int xmx = -1e9, xmn = 1e9, ymx = -1e9, ymn = 1e9;
  int r[4];
  for (int(i) = (1); (i) <= (n); (i)++) {
    scanf("%d%d", x + i, y + i);
    if (x[i] > xmx) {
      r[0] = i;
      xmx = x[i];
    }
    if (x[i] < xmn) {
      r[1] = i;
      xmn = x[i];
    }
    if (y[i] > ymx) {
      r[2] = i;
      ymx = y[i];
    }
    if (y[i] < ymn) {
      r[3] = i;
      ymn = y[i];
    }
  }
  int ans = 0;
  for (int(i) = (0); (i) <= ((4) - 1); (i)++)
    for (int(j) = (i + 1); (j) <= (3); (j)++) {
      pair<int, int> p[2] = {{x[r[i]], y[r[i]]}, {x[r[j]], y[r[j]]}};
      for (int(k) = (1); (k) <= (n); (k)++) {
        if (k == r[i] || k == r[j]) continue;
        pair<int, int> now = {x[k], y[k]};
        ans = max(ans, dis(now, p[0]) + dis(now, p[1]) + dis(p[0], p[1]));
      }
    }
  printf("%d ", ans);
  for (int(i) = (4); (i) <= (n); (i)++)
    printf("%d ", 2 * (xmx - xmn + ymx - ymn));
}

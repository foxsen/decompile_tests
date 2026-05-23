#include <bits/stdc++.h>
using namespace std;
long long ara[300005], tmp[300005];
int main() {
  long long test, t, i, j, k, a, b, c, x, y, z, n, m;
  scanf("%lld", &test);
  for (t = 1; t <= test; t++) {
    scanf("%lld", &n);
    scanf("%lld%lld", &z, &m);
    for (i = 1; i <= n; i++) scanf("%lld", &ara[i]);
    for (i = 1; i <= n; i++) {
      if (ara[i] > m) {
        z = -1;
        break;
      }
      tmp[i] = min(z, m - ara[i]);
    }
    if (z == -1) {
      printf("NO\n");
      continue;
    }
    x = tmp[1];
    y = x == 0 ? 1 : -1;
    for (i = 1; i <= n; i++) {
      if (x > tmp[i]) break;
      if (tmp[i] >= z) {
        x = tmp[i + 1];
        y = x == 0 ? 1 : -1;
      } else {
        if (y > 0)
          x += y;
        else {
          x = min(x - 1, tmp[i + 1]);
        }
        if (x == 0)
          y = 1;
        else if (x == z)
          y = -1;
      }
    }
    if (i <= n)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}

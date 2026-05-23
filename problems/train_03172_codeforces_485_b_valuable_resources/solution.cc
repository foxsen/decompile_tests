#include <bits/stdc++.h>
using namespace std;
int x[1005], y[1005];
int main(void) {
  memset(x, 0, sizeof(x));
  memset(y, 0, sizeof(y));
  int n, i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d%d", &x[i], &y[i]);
  long long dx, dy, d;
  sort(x, x + n);
  sort(y, y + n);
  dx = x[n - 1] - x[0];
  dy = y[n - 1] - y[0];
  d = max(dx, dy);
  printf("%lld\n", d * d);
  return 0;
}

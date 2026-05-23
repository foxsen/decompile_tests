#include <bits/stdc++.h>
int main() {
  int n, k, m, t, i;
  scanf("%d%d%d%d", &n, &k, &m, &t);
  int a, b;
  for (i = 0; i < t; i++) {
    scanf("%d %d", &a, &b);
    if (a == 0) {
      if (b < k) {
        n -= b;
        k -= b;
      } else {
        n = b;
      }
    }
    if (a == 1) {
      if (b <= k) {
        n += 1;
        k += 1;
      } else {
        n += 1;
      }
    }
    printf("%d %d\n", n, k);
  }
  return 0;
}

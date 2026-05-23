#include <bits/stdc++.h>
int n, a[200011], buc[30];
int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 0; i < 30; ++i) buc[i] = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = 0; j < 30; ++j)
        if (a[i] >> j & 1) ++buc[j];
    int x = 0;
    for (int i = 0; i < 30; ++i) x = gcd(x, buc[i]);
    for (int i = 1; i <= n; ++i) {
      if (x % i == 0) printf("%d ", i);
    }
    putchar(10);
  }
  return 0;
}

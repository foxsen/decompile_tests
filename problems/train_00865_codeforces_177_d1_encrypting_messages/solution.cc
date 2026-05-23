#include <bits/stdc++.h>
long a[100001], b[100001];
long m, n, c;
int main() {
  long k, i, j, s, x;
  scanf("%ld %ld %ld", &n, &m, &c);
  for (i = 1; i <= n; i++) scanf("%ld", &a[i]);
  b[0] = 0;
  for (i = 1; i <= m; i++) scanf("%ld", &b[i]);
  s = 0;
  for (i = 1; i <= n; i++) {
    if (i <= m) s += b[i];
    x = i - (n - m + 1);
    if (x > 0) s -= b[x];
    s += c;
    a[i] += s;
    a[i] = a[i] % c;
  }
  printf("%ld", a[1] % c);
  for (i = 2; i <= n; i++) {
    a[i] = a[i] % c;
    printf(" %ld", a[i]);
  }
  printf("\n");
}

#include <bits/stdc++.h>
long long k, n, m, i, ans, j, d, a[100009], b[100009], c[100009];
int main() {
  scanf("%I64d%I64d%I64d", &n, &m, &k);
  for (i = 0; i < m; i++) scanf("%I64d%I64d%I64d", &a[i], &b[i], &c[i]);
  for (i = 0; i < k; i++) {
    scanf("%I64d", &d);
    for (j = 0; j < m; j++)
      if (a[j] <= d && d <= b[j]) ans += d - a[j] + c[j];
  }
  printf("%I64d", ans);
}

#include <bits/stdc++.h>
int main() {
  int a[111], b[111];
  int n, m, i, j;
  memset(b, 0, sizeof(b));
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++) scanf("%d", &a[i]);
  for (i = 1; i <= m; i++) {
    for (j = a[i]; j <= n; j++) {
      if (b[j] == 0) b[j] = a[i];
    }
  }
  for (i = 1; i < n; i++) printf("%d ", b[i]);
  printf("%d\n", b[n]);
  return 0;
}

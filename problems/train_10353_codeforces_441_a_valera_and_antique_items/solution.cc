#include <bits/stdc++.h>
int main() {
  int n, i, j, k, count = 0, v, l, h, a, f;
  int b[100];
  scanf("%d%d", &n, &v);
  for (i = 0; i < n; i++) {
    scanf("%d", &k);
    f = 1;
    for (j = 0; j < k; j++) {
      scanf("%d", &a);
      if (a < v && f) {
        b[count] = i + 1;
        count++;
        f = 0;
      }
    }
  }
  printf("%d\n", count);
  for (i = 0; i < count; i++) printf("%d ", b[i]);
}

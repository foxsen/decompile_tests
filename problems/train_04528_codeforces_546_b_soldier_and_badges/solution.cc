#include <bits/stdc++.h>
int main() {
  int n, num, i, j, cost = 0, len, a[100000] = {0};
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d", &num);
    a[num] += 1;
  }
  for (i = 1; i <= n; ++i) {
    if (a[i] > 1) {
      len = a[i] - 1;
      for (j = i + 1; j < 100000 && len > 0; ++j)
        if (a[j] == 0) {
          cost += (j - i);
          a[j] = 1;
          --len;
          --a[i];
        }
    }
  }
  printf("%d", cost);
  return 0;
}

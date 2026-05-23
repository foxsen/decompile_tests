#include <bits/stdc++.h>
int main() {
  int n, k, t;
  register int icount;
  while (scanf("%d%d", &n, &k) != EOF) {
    icount = 0;
    while ((n--) > 0) {
      scanf("%d", &t);
      icount += (t + k - 1) / k;
    }
    printf("%d\n", (icount + 1) / 2);
  }
  return 0;
}

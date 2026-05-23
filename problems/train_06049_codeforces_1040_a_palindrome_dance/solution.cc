#include <bits/stdc++.h>
int ara[111];
int main() {
  int i, a, b, n, zerocount = 0, onecount = 0, count = 0, rem, cost;
  scanf("%d %d %d", &n, &a, &b);
  for (i = 1; i <= n; i++) {
    scanf("%d", &ara[i]);
    if (ara[i] == 1 || ara[i] == 0) {
      count++;
    }
  }
  for (i = 1; i <= n; i++) {
    if (ara[i] == 1) {
      if (ara[n - i + 1] == 1) {
        continue;
      } else if (ara[n - i + 1] == 0) {
        printf("-1\n");
        return 0;
      } else {
        ara[n - i + 1] = 1;
        onecount++;
      }
    }
    if (ara[i] == 0) {
      if (ara[n - i + 1] == 0) {
        continue;
      } else if (ara[n - i + 1] == 1) {
        printf("-1\n");
        return 0;
      } else {
        ara[n - i + 1] = 0;
        zerocount++;
      }
    }
  }
  rem = n - (count + zerocount + onecount);
  if (a >= b) {
    cost = onecount * b + zerocount * a + rem * b;
  }
  if (b > a) {
    cost = onecount * b + zerocount * a + rem * a;
  }
  printf("%d\n", cost);
  return 0;
}

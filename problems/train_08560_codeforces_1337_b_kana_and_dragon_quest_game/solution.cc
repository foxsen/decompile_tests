#include <bits/stdc++.h>
int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    long int x;
    int n, m;
    scanf("%ld %d %d", &x, &n, &m);
    if (x > 10) {
      while (n > 0) {
        x = x / 2 + 10;
        n--;
      }
    }
    while (m > 0 && x > 0) {
      x = x - 10;
      m--;
    }
    if (x <= 0)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}

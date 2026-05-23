#include <bits/stdc++.h>
int main() {
  int i, n, a, b, c = 0;
  int cap = 0;
  scanf(" %d", &n);
  for (i = 1; i <= n; i++) {
    scanf(" %d %d", &a, &b);
    c += -a + b;
    if (c > cap) {
      cap = c;
    }
  }
  printf("%d", cap);
  return 0;
}

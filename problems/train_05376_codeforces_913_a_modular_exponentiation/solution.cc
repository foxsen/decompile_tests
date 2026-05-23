#include <bits/stdc++.h>
int main() {
  int m, n, ans = 1, rem;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    ans = ans * 2;
    if (ans > m) {
      printf("%d", m);
      return 0;
    }
  }
  rem = m % ans;
  printf("%d", rem);
  return 0;
}

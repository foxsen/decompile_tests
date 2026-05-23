#include <bits/stdc++.h>
int main() {
  int n, m, a, b, ans;
  ans = 3;
  scanf("%d%d%d%d", &n, &m, &a, &b);
  a--;
  b--;
  if (a % m == 0 || b % m == m - 1) ans = 2;
  if (a % m == ((b % m) + 1) % m) ans = 2;
  if (a % m == 0 && b % m == m - 1) ans = 1;
  if (ans > 1 && b == n - 1) {
    if (a % m == 0)
      ans = 1;
    else
      ans = 2;
  }
  if (a / m == b / m) ans = 1;
  if (ans > 2) {
    if (abs(a / m - b / m) == 1) ans = 2;
  }
  printf("%d\n", ans);
  return 0;
}

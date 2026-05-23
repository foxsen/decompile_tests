#include <bits/stdc++.h>
int main() {
  int h, w, n, i;
  scanf("%d %d", &h, &w);
  long long s1;
  s1 = 1;
  n = h + w;
  for (i = 1; i <= n; i++) s1 = (2 * s1) % 998244353;
  printf("%I64d\n", s1);
}

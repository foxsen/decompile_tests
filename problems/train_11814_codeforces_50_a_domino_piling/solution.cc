#include <bits/stdc++.h>
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  if (m % 2 == 0)
    printf("%d", n * m / 2);
  else
    printf("%d", n * (m / 2) + n / 2);
  return 0;
}

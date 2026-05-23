#include <bits/stdc++.h>
int main() {
  long long int a, b, c, x, y, z, k;
  long long int d;
  scanf("%lld%lld%lld", &a, &b, &c);
  d = sqrt(a * b * c);
  x = d / a;
  y = d / b;
  z = d / c;
  k = 4 * (x + y + z);
  printf("%lld", k);
  return 0;
}

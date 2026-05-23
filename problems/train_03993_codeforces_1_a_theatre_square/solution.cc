#include <bits/stdc++.h>
int main() {
  unsigned long long int n, m, a;
  scanf("%llu %llu %llu", &n, &m, &a);
  if (n % a == 0) {
    if (m % a == 0) {
      printf("%llu\n", (n / a) * (m / a));
    } else {
      printf("%llu\n", (n / a) * ((m / a) + 1));
    }
  } else {
    if (m % a == 0) {
      printf("%llu\n", ((n / a) + 1) * (m / a));
    } else {
      printf("%llu\n", ((n / a) + 1) * ((m / a) + 1));
    }
  }
  return 0;
}

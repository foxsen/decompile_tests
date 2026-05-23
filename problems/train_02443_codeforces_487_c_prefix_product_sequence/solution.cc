#include <bits/stdc++.h>
long long n;
bool isprime() {
  for (long long k = 2; k <= sqrt(n); k++) {
    if (n % k == 0) return false;
  }
  return true;
}
long long int fast(long long a, long long x) {
  if (x == 1) return a;
  long long y = fast(a, x / 2);
  if (x % 2 == 0)
    return (y * y) % n;
  else
    return (y * y * a) % n;
}
int main() {
  scanf("%I64d", &n);
  if (n == 1) {
    printf("YES\n1");
    return 0;
  }
  if (n == 4) {
    printf("YES\n1\n3\n2\n4");
    return 0;
  }
  if (!isprime()) {
    printf("NO");
    return 0;
  }
  printf("YES\n1\n");
  for (long long k = 2; k < n; k++) {
    printf("%I64d\n", (k * (fast(k - 1, n - 2))) % n);
  }
  printf("%I64d", n);
}

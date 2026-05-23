#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) {
  return (x % y == 0) ? y : gcd(y, x % y);
}
int main() {
  long long n, m, k;
  scanf("%lld%lld%lld", &n, &m, &k);
  if (2LL * n * m % k != 0) {
    puts("NO");
    return 0;
  }
  puts("YES");
  if (gcd(n, k) > 1) {
    n = 2LL * n;
    long long d = gcd(n, k);
    n /= d;
    k /= d;
    m /= k;
  } else {
    m = 2LL * m;
    long long d = gcd(m, k);
    m /= d;
    k /= d;
    n /= k;
  }
  printf("0 0\n%lld 0\n0 %lld\n", n, m);
  return 0;
}

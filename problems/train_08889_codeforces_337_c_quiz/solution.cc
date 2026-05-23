#include <bits/stdc++.h>
using namespace std;
long long bigmod(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  if (b % 2 == 0) {
    long long r = bigmod(a, b / 2);
    r = r * r;
    r = r % 1000000009;
    return r;
  } else {
    long long r = bigmod(a, b - 1);
    r = r * a;
    r = r % 1000000009;
    return r;
  }
}
int main() {
  long long n, m, k;
  scanf("%lld %lld %lld", &n, &m, &k);
  long long t = min(n - m, m / (k - 1));
  long long r = m - t * (k - 1);
  long long p = r / k;
  long long ans = t * (k - 1);
  ans += ((bigmod(2, p + 1) + 1000000009 - 2) * k) % 1000000009;
  ans %= 1000000009;
  ans += r % k;
  ans %= 1000000009;
  printf("%lld\n", ans);
  return 0;
}

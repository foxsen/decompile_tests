#include <bits/stdc++.h>
using namespace std;
long long quo_floor(long long x, long long y) {
  return (x < 0) ^ (y < 0) ? -(abs(x) + abs(y) - 1) / abs(y) : x / y;
}
long long quo_ceil(long long x, long long y) {
  return (x < 0) ^ (y < 0) ? -abs(x) / abs(y) : (x + y - 1) / y;
}
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b) return x = 1, y = 0, a;
  long long d = exgcd(b, a % b, y, x);
  return y -= a / b * x, d;
}
long long a1, a2, b1, b2, l, r;
signed main() {
  cin >> a1 >> b1 >> a2 >> b2 >> l >> r;
  long long x, y, gcd = exgcd(a1, -a2, x, y);
  if ((b2 - b1) % gcd) return puts("0"), 0;
  x *= (b2 - b1) / gcd;
  y *= (b2 - b1) / gcd;
  long long dx = abs(a2 / gcd), dy = abs(a1 / gcd);
  ((x %= dx) += dx) %= dx;
  y = (a1 * x - (b2 - b1)) / a2;
  if (y < 0) ((y %= dy) += dy) %= dy, x = (a2 * y + (b2 - b1)) / a1;
  long long l0 = max(0ll, quo_ceil(l - a1 * x - b1, a1 * dx)),
            r0 = quo_floor(r - a1 * x - b1, a1 * dx);
  cout << max(0ll, r0 - l0 + 1);
  return 0;
}

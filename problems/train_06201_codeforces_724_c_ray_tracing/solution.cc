#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int MAX = 100017;
int n, m, k;
int x, y;
long long gcd(long long a, long long b, long long& x, long long& y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long x1, frgrwegreg;
  long long d = gcd(b % a, a, x1, frgrwegreg);
  x = frgrwegreg - (b / a) * x1;
  y = x1;
  return d;
}
long long gcd(long long a, long long b) {
  if (!a || !b) return a + b;
  return gcd(b % a, a);
}
long long solve(long long a, long long b, long long c, long long val) {
  int d = gcd(abs(a), abs(b));
  if (abs(c) % d != 0) return 1e18;
  a /= d;
  b /= d;
  c /= d;
  long long x, y;
  gcd(a, b, x, y);
  if (a * x + b * y == -1) x *= -1, y *= -1;
  x *= c;
  y *= c;
  if (val + 2 * y * m < 0) {
    long long res = abs(val + 2 * y * m) / (2 * a * m);
    y += a * res;
  }
  if (val + 2 * y * m > 0) {
    long long res = abs(val + 2 * y * m) / (2 * a * m);
    y -= a * res;
  }
  while (val + 2 * y * m - 2 * a * m > 0) y -= a;
  while (val + 2 * y * m < 0) y += a;
  return val + 2 * y * m;
}
int main() {
  cin >> n >> m >> k;
  for (int i = (0); i < (k); ++i) {
    scanf("%d%d", &x, &y);
    long long res = 1e18;
    res = min(res, solve(2 * n, -2 * m, y - x, y));
    res = min(res, solve(2 * n, -2 * m, y - (2 * n - x), y));
    res = min(res, solve(2 * n, -2 * m, (2 * m - y) - x, 2 * m - y));
    res = min(res, solve(2 * n, -2 * m, (2 * m - y) - (2 * n - x), 2 * m - y));
    if (res == 1e18)
      cout << "-1\n";
    else
      cout << res << "\n";
    long long x0 = 0, y0 = 0, dx = 1, dy = 1;
  }
  return 0;
}

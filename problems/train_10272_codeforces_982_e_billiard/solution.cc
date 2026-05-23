#include <bits/stdc++.h>
using namespace std;
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (b) {
    long long g = exgcd(b, a % b, x, y);
    long long tmp = x;
    x = y, y = tmp - a / b * y;
    return g;
  } else {
    x = 1, y = 0;
    return a;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, x, y, vx, vy;
  cin >> n >> m >> x >> y >> vx >> vy;
  long long da = 0, db = 0;
  if (vx)
    da = vx > 0 ? n - x : x;
  else {
    if (vy && (x == 0 || x == n))
      cout << x << ' ' << (vy > 0 ? m : 0);
    else
      cout << "-1" << endl;
    return 0;
  }
  if (vy)
    db = vy > 0 ? m - y : y;
  else {
    if (vx && (y == 0 || y == m))
      cout << (vx > 0 ? n : 0) << ' ' << y;
    else
      cout << "-1" << endl;
    return 0;
  }
  long long t = db - da, dx, dy;
  long long gcd = exgcd(n, -m, dx, dy);
  if (t % gcd) {
    cout << "-1" << endl;
    return 0;
  }
  dx = (long long)dx * t / gcd, dy = (long long)dy * t / gcd;
  long long xdel = m / gcd, ydel = n / gcd;
  if (dx < 0) {
    long long f = (-dx - 1) / xdel + 1;
    dx += f * xdel, dy += f * ydel;
  }
  if (dx > xdel) {
    long long f = dx / xdel;
    dx -= f * xdel, dy -= f * ydel;
  }
  cout << ((dx & 1) ^ (vx > 0) ? n : 0) << ' ' << ((dy & 1) ^ (vy > 0) ? m : 0)
       << endl;
  return 0;
}

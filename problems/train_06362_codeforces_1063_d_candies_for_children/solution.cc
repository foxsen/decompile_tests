#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long N = 2e3 + 10;
const long long inf = 1e18 + 10ll;
const long long mod = 1e9 + 7;
const long long eps = 1e-9;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
using namespace std;
long long n, l, r, k;
long long len1;
long long len2;
long long gcd(long long a, long long b, long long &first, long long &second) {
  if (b == 0) {
    first = 1;
    second = 0;
    return a;
  }
  long long g = gcd(b, a % b, first, second);
  long long nx = second;
  long long ny = first - second * (a / b);
  first = nx;
  second = ny;
  return g;
}
bool findsol(long long a, long long b, long long c, long long &x0,
             long long &y0, long long &g) {
  g = gcd(a, b, x0, y0);
  if (c % g != 0) return false;
  x0 *= c / g;
  y0 *= c / g;
  return true;
}
void shift(long long &first, long long &second, long long a, long long b,
           long long cnt) {
  first += b * cnt;
  second -= a * cnt;
}
bool findmxsol(long long a, long long b, long long c, long long &first,
               long long &second) {
  long long g = -1;
  if (!findsol(a, b, c, first, second, g)) return false;
  a /= g;
  b /= g;
  if (first < len1) shift(first, second, a, b, (len1 - first) / b);
  if (first > len1) shift(first, second, a, b, -((first - len1 + b - 1) / b));
  pair<long long, long long> p1 = {first, second};
  if (first < 0 || first > len1 || second < 0 || second > len2) p1 = {-1, -1};
  if (first < 0) shift(first, second, a, b, (0 - first + b - 1) / b);
  if (first > 0) shift(first, second, a, b, -(first - 0) / b);
  pair<long long, long long> p2 = {first, second};
  if (first < 0 || first > len1 || second < 0 || second > len2) p2 = {-1, -1};
  if (second < len2) shift(first, second, a, b, -(len2 - second) / a);
  if (second > len2) shift(first, second, a, b, (second - len2 + a - 1) / a);
  pair<long long, long long> p3 = {first, second};
  if (first < 0 || first > len1 || second < 0 || second > len2) p3 = {-1, -1};
  if (second < 0) shift(first, second, a, b, -(0 - second + a - 1) / a);
  if (second > 0) shift(first, second, a, b, (second - 0) / a);
  pair<long long, long long> p4 = {first, second};
  if (first < 0 || first > len1 || second < 0 || second > len2) p4 = {-1, -1};
  pair<long long, long long> mxp = {-1, -1};
  if (p1.first <= len1 && p1.second <= len2 && p1.first >= 0 &&
      p1.second >= 0 && (mxp.first + mxp.second < p1.first + p1.second))
    mxp = p1;
  if (p2.first <= len1 && p2.second <= len2 && p2.first >= 0 &&
      p2.second >= 0 && (mxp.first + mxp.second < p2.first + p2.second))
    mxp = p2;
  if (p3.first <= len1 && p3.second <= len2 && p3.first >= 0 &&
      p3.second >= 0 && (mxp.first + mxp.second < p3.first + p3.second))
    mxp = p3;
  if (p4.first <= len1 && p4.second <= len2 && p4.first >= 0 &&
      p4.second >= 0 && (mxp.first + mxp.second < p4.first + p4.second))
    mxp = p4;
  first = mxp.first;
  second = mxp.second;
  return true;
}
pair<long long, long long> calc(long long t, bool is) {
  long long second = k - n * t - len1 + is;
  pair<long long, long long> p = {-1, -1};
  findmxsol((t + 1), t, second, p.first, p.second);
  return p;
}
long long mul(long long a, long long b) {
  if (a <= 1e9 && b <= 1e9) return a * b;
  return inf;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(10);
  cin >> n >> l >> r >> k;
  if (r < l)
    len1 = (n - l) + r + 1;
  else
    len1 = r - l + 1;
  len2 = n - len1;
  long long ans = -1;
  if (n <= 7e7) {
    for (long long i = 0; i <= n; ++i) {
      long long t = (k - len1) / (i + n);
      long long second = k - len1 - t * (i + n);
      if (second >= max(0ll, (i - len2)) && second <= len1) ans = max(ans, i);
      t = (k + 1 - len1) / (i + n);
      second = k + 1 - len1 - t * (i + n);
      if (second >= max(0ll, (i - len2)) && second <= len1 && second)
        ans = max(ans, i);
    }
  } else {
    long long kneed = (k + 1) / 2;
    if (kneed <= len1 && kneed + k / 2 >= len1)
      ans = max(ans, k / 2 - (len1 - kneed) + len2);
    ++k;
    kneed = (k + 1) / 2;
    if (kneed <= len1 && kneed + k / 2 >= len1)
      ans = max(ans, k / 2 - (len1 - kneed) + len2);
    --k;
    for (long long i = 1; i <= k / n; ++i) {
      long long y1 = k - n * i - len1;
      long long y2 = k - n * i - len1 + 1;
      pair<long long, long long> p1 = calc(i, false);
      pair<long long, long long> p2 = calc(i, true);
      if (p1.first <= len1 && p1.second <= len2 &&
          ((i + 1) * p1.first + i * p1.second == y1) && y1 >= 0 &&
          p1.first >= 0 && p1.second >= 0)
        ans = max(ans, p1.first + p1.second);
      if (p2.first <= len1 && p2.second <= len2 &&
          ((i + 1) * p2.first + i * p2.second == y2) && y2 >= 0 &&
          p2.first >= 1 && p2.second >= 0)
        ans = max(ans, p2.first + p2.second);
    }
  }
  cout << ans << "\n";
}

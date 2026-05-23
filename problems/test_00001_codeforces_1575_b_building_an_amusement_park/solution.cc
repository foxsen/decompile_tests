#include <bits/stdc++.h>
const double PI = 3.1415926535897932384626433;
const int KL = 3e5 + 10;
const long long MOD = 1e9 + 7;
using namespace std;
struct point {
  long double x, y;
  void go(long long x1, long long y1) {
    x = x1;
    y = y1;
  }
  void read() { cin >> x >> y; }
  point operator-(point b) { return point{x - b.x, y - b.y}; }
  point operator+(point b) { return point{x + b.x, y + b.y}; }
};
long double fnd_angle(point p) {
  long double len = sqrt(p.x * p.x + p.y * p.y);
  long double angle = acos(fabs(p.x) / len);
  if (p.y < 0) {
    if (p.x >= 0)
      angle = 2 * PI - angle;
    else
      angle += PI;
  } else if (p.x < 0)
    angle = PI - angle;
  return angle;
}
int n, k;
vector<point> A;
vector<pair<long double, long double>> a, b;
multiset<long double> s;
bool ok(long double mid) {
  a.clear();
  b.clear();
  for (int i = 0; i < n; i++) {
    long double dis = sqrt(A[i].x * A[i].x + A[i].y * A[i].y);
    if (dis > 2 * mid) continue;
    long double angle = fnd_angle(A[i]);
    long double angle2 = acos(dis / (2.0 * mid));
    a.push_back({angle - angle2, 2 * angle2});
    b.push_back({angle + angle2, -2.0 * angle2});
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  reverse(b.begin(), b.end());
  int sz = a.size();
  for (int i = 0; i < sz; i++) a.push_back({a[i].first + 2 * PI, a[i].second});
  for (int i = 0; i < sz; i++) b.push_back({b[i].first - 2 * PI, b[i].second});
  int mx = 0;
  s.clear();
  for (int i = 0; i < a.size(); i++) {
    while (s.size() > 0 && *s.begin() < a[i].first) s.erase(s.begin());
    if (s.size() + 1 >= k) return 1;
    s.insert(a[i].first + a[i].second);
  }
  s.clear();
  for (int i = 0; i < b.size(); i++) {
    while (s.size() > 0 && *(--s.end()) > b[i].first) s.erase(--s.end());
    if (s.size() + 1 >= k) return 1;
    s.insert(b[i].first + b[i].second);
  }
  return mx >= k;
  return (mx >= k);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    point pp;
    pp.read();
    if (pp.x == 0 && pp.y == 0) {
      k--;
      continue;
    }
    A.push_back(pp);
  }
  n = A.size();
  long double lo = 0.0, hi = 2e5;
  int cnt = 35;
  while (cnt--) {
    long double mid = (lo + hi) / 2.0;
    if (ok(mid))
      hi = mid;
    else
      lo = mid;
  }
  cout << fixed << setprecision(8) << lo << "\n";
  return 0;
}

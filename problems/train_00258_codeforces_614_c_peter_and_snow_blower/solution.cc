#include <bits/stdc++.h>
using namespace std;
int sign(double x, double eps = 1e-9) { return x < -eps ? -1 : x > eps; }
struct point {
  double x, y;
  point(double x = 0, double y = 0) : x(x), y(y) {}
  double det(point p) { return x * p.y - y * p.x; }
  double dis2(point p) { return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y); }
  void show() { cout << x << " " << y << endl; }
};
point operator+(point a, point b) { return point(a.x + b.x, a.y + b.y); }
point operator-(point a, point b) { return point(a.x - b.x, a.y - b.y); }
point operator*(point a, double k) { return point(a.x * k, a.y * k); }
point operator/(point a, double k) { return point(a.x / k, a.y / k); }
struct line {
  point a, b;
  line(point a = point(0, 0), point b = point(0, 0)) : a(a), b(b) {}
  point intersect(line l) {
    double s1 = (b - a).det(l.a - a);
    double s2 = (b - a).det(l.b - a);
    return (l.a * s2 - l.b * s1) / (s2 - s1);
  }
  line vertical(point p) { return line(p, p + point(b.y - a.y, a.x - b.x)); }
  int include(point p) {
    return sign((b.x - p.x) * (p.x - a.x)) >= 0 &&
           sign((b.y - p.y) * (p.y - a.y)) >= 0;
  }
};
int main() {
  int n;
  double r = 1e14, R = 0;
  point p, pre, now, first;
  cin >> n >> p.x >> p.y >> first.x >> first.y;
  now = first;
  for (int i = 0; i < n; i++) {
    if (i < n - 1) {
      pre = now;
      cin >> now.x >> now.y;
    } else
      pre = first;
    r = min(r, p.dis2(now));
    r = min(r, p.dis2(pre));
    line temp = line(now, pre), vtemp = temp.vertical(p);
    point inter = temp.intersect(vtemp);
    if (temp.include(inter)) r = min(r, p.dis2(inter));
    R = max(R, p.dis2(now));
    R = max(R, p.dis2(pre));
  }
  printf("%.18f\n", 3.14159265358979323846 * (R - r));
}

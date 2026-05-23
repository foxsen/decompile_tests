#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
struct circle {
  double x, y, r;
  circle() {}
  circle(double x, double y, double r = 0) : x(x), y(y), r(r) {}
  circle operator+(circle b) { return circle(x + b.x, y + b.y); }
  circle operator-(circle b) { return circle(x - b.x, y - b.y); }
  circle operator*(double d) { return circle(x * d, y * d); }
  double squareLength() { return ((x) * (x)) + ((y) * (y)); }
  double length() { return sqrt(squareLength()); }
  void normalize() {
    double d = length();
    x /= d;
    y /= d;
  }
};
circle dot(circle a, circle b) { return circle(a.x * b.y, a.y * b.x); }
circle a, b, c;
double get_angle(circle a, circle b) { return asin(a.r / (a - b).length()); }
bool check(circle p) {
  return fabs(get_angle(a, p) - get_angle(b, p)) < 1e-8 &&
         fabs(get_angle(b, p) - get_angle(c, p)) < 1e-8 &&
         fabs(get_angle(c, p) - get_angle(a, p)) < 1e-8;
}
circle get_circle(circle a, circle b) {
  double br = ((b.r) * (b.r));
  double ar = ((a.r) * (a.r));
  double A = br - ar;
  double x = (br * a.x - ar * b.x) / A;
  double y = (br * a.y - ar * b.y) / A;
  double aa = ((a.y - y) * (a.y - y));
  double bb = ((b.y - y) * (b.y - y));
  double B = -2 * (br * a.x - ar * b.x);
  double C = br * (aa + ((a.x) * (a.x))) - ar * (bb + ((b.x) * (b.x)));
  double D = sqrt(((B) * (B)) - 4 * A * C);
  return circle(x, y, fabs(D / (2 * A)));
}
int main() {
  cin >> a.x >> a.y >> a.r;
  cin >> b.x >> b.y >> b.r;
  cin >> c.x >> c.y >> c.r;
  if (a.r == b.r && b.r == c.r) {
    if (fabs(c.y - b.y) < 1e-10) swap(a, b);
    double y = ((((c.x) * (c.x)) - ((a.x) * (a.x)) + ((c.y) * (c.y)) -
                 ((a.y) * (a.y))) *
                    (b.x - a.x) -
                (((b.x) * (b.x)) - ((a.x) * (a.x)) + ((b.y) * (b.y)) -
                 ((a.y) * (a.y))) *
                    (c.x - a.x)) /
               (2 * ((c.y - a.y) * (b.x - a.x) - (b.y - a.y) * (c.x - a.x)));
    double x = (((b.x) * (b.x)) - ((a.x) * (a.x)) + ((b.y) * (b.y)) -
                ((a.y) * (a.y)) - 2 * y * (b.y - a.y)) /
               (2 * (b.x - a.x));
    if (check(circle(x, y))) cout << setprecision(5) << fixed << x << " " << y;
    return 0;
  }
  if (fabs(a.r - b.r) < 1e-10) swap(a, c);
  if (fabs(a.r - c.r) < 1e-10) swap(a, b);
  circle p1 = get_circle(a, b);
  circle p2 = get_circle(a, c);
  double length = (p2 - p1).length();
  if (length < p1.r + p2.r + 1e-8)
    if (p1.r < p2.r + length + 1e-8 && p2.r < p1.r + length + 1e-8 &&
        length < p1.r + p2.r + 1e-8) {
      double x =
          (((p2.r) * (p2.r)) - ((p1.r) * (p1.r)) - ((length) * (length))) /
          (-2 * length);
      double h = sqrt(((p1.r) * (p1.r)) - ((x) * (x)));
      circle vec = (p2 - p1);
      vec.normalize();
      vec = vec * x;
      circle point = p1 + vec;
      vec = dot(circle(-1, 1), vec);
      vec.normalize();
      vec = vec * h;
      circle x1 = point + vec;
      circle x2 = point - vec;
      cout << setprecision(5) << fixed;
      if (check(x1) && !check(x2))
        cout << x1.x << " " << x1.y;
      else if (!check(x1) && check(x2))
        cout << x2.x << " " << x2.y;
      else if (check(x1) && check(x2))
        if (get_angle(a, x1) > get_angle(a, x2))
          cout << x1.x << " " << x1.y;
        else
          cout << x2.x << " " << x2.y;
    }
  return 0;
}

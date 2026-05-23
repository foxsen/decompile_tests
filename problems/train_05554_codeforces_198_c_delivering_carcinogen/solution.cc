#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-10;
const double PI = atan(1.0) * 4.0;
struct Point {
  double x, y;
  Point();
  Point(double x, double y);
};
Point::Point() {}
Point::Point(double x, double y) : x(x), y(y) {}
bool cmp_x(const Point& lhs, const Point& rhs) {
  return lhs.x != rhs.x ? lhs.x < rhs.x : lhs.y < rhs.y;
}
bool cmp_y(const Point& lhs, const Point& rhs) {
  return lhs.y != rhs.y ? lhs.y < rhs.y : lhs.x < rhs.x;
}
bool operator<(const Point& lhs, const Point& rhs) { return cmp_x(lhs, rhs); }
Point const operator+(const Point& lhs, const Point& rhs) {
  return Point(lhs.x + rhs.x, lhs.y + rhs.y);
}
Point const operator-(const Point& lhs, const Point& rhs) {
  return Point(lhs.x - rhs.x, lhs.y - rhs.y);
}
Point const operator*(const double lhs, const Point& rhs) {
  return Point(lhs * rhs.x, lhs * rhs.y);
}
Point const operator*(const Point& lhs, const double rhs) { return rhs * lhs; }
Point const operator/(const Point& lhs, const double rhs) {
  return Point(lhs.x / rhs, lhs.y / rhs);
}
Point& operator+=(Point& lhs, const Point& rhs) {
  lhs.x += rhs.x;
  lhs.y += rhs.y;
  return lhs;
}
Point& operator-=(Point& lhs, const Point& rhs) {
  lhs.x -= rhs.x;
  lhs.y -= rhs.y;
  return lhs;
}
Point& operator*=(Point& lhs, const double rhs) {
  lhs.x *= rhs;
  lhs.y *= rhs;
  return lhs;
}
Point& operator/=(Point& lhs, const double rhs) {
  lhs.x /= rhs;
  lhs.y /= rhs;
  return lhs;
}
Point const operator+(const Point& obj) { return obj; }
Point const operator-(const Point& obj) { return Point(-obj.x, -obj.y); }
ostream& operator<<(ostream& os, const Point& obj) {
  return (os << '(' << obj.x << ", " << obj.y << ')');
}
bool eq(const double lhs, const double rhs) {
  return abs(lhs - rhs) <= EPS * max((double)1, abs(lhs) + abs(rhs));
}
bool sle(const double lhs, const double rhs) {
  return lhs < rhs - EPS * max((double)1, abs(lhs) + abs(rhs));
}
bool leq(const double lhs, const double rhs) {
  return lhs <= rhs + EPS * max((double)1, abs(lhs) + abs(rhs));
}
bool sge(const double lhs, const double rhs) { return !leq(lhs, rhs); }
bool geq(const double lhs, const double rhs) { return !sle(lhs, rhs); }
double sq(double x) { return x * x; }
double abs2(const Point& p) { return sq(p.x) + sq(p.y); }
double abs(const Point& p) { return sqrt(abs2(p)); }
int sign(double x) { return sge(x, 0) ? 1 : sle(x, 0) ? -1 : 0; }
Point rot90(const Point& p) { return Point(-p.y, p.x); }
double get_square_dist(const Point& lhs, const Point& rhs) {
  return sq(lhs.x - rhs.x) + sq(lhs.y - rhs.y);
}
double get_dist(const Point& lhs, const Point& rhs) {
  return sqrt(get_square_dist(lhs, rhs));
}
double iprod(const Point& lhs, const Point& rhs) {
  return lhs.x * rhs.x + lhs.y * rhs.y;
}
double oprod(const Point& lhs, const Point& rhs) {
  return lhs.x * rhs.y - lhs.y * rhs.x;
}
double det(const Point& a, const Point& b, const Point& c) {
  return oprod(a, b) + oprod(b, c) + oprod(c, a);
}
double arg(const Point& p) {
  if (leq(fabs(p.x), 0)) {
    return sge(p.y, 0) ? PI / 2.0 : sle(p.y, 0) ? 3.0 * PI / 2.0 : -1.0;
  }
  return atan(p.y / p.x) + (geq(p.x, 0) ? 0.0 : PI);
}
bool on_segment(const Point& p1, const Point& p2, const Point& q) {
  return eq(oprod(p1 - q, p2 - q), 0) && leq(iprod(p1 - q, p2 - q), 0);
}
Point get_intersection_LL(const Point& p1, const Point& p2, const Point& q1,
                          const Point& q2) {
  return p1 + (p2 - p1) * (oprod(q2 - q1, q1 - p1) / oprod(q2 - q1, p2 - p1));
}
struct Circle {
  Point center;
  double radius;
  Circle();
  Circle(const Point c, const double r);
};
Point rot(const Point& p, double angle) {
  Point ret;
  ret.x = p.x * cos(angle) - p.y * sin(angle);
  ret.y = p.x * sin(angle) + p.y * cos(angle);
  return ret;
}
Circle::Circle() {}
Circle::Circle(const Point c, const double r) : center(c), radius(r) {}
bool cross_CC(const Circle& c1, const Circle& c2) {
  double d = abs(c1.center - c2.center);
  return leq(d, c1.radius + c2.radius) && leq(abs(c1.radius - c2.radius), d);
}
Point get_projection(const Point& p, const Point& q1, const Point& q2) {
  return q1 + iprod(q2 - q1, p - q1) / abs2(q2 - q1) * (q2 - q1);
}
double distance_line_point(Point p1, Point p2, Point q) {
  return abs(oprod((p2 - p1), (q - p1))) / abs(p2 - p1);
}
double distance_segment_point(Point p1, Point p2, Point q) {
  if (iprod((p2 - p1), (q - p1)) < 0) return abs(q - p1);
  if (iprod((p1 - p2), (q - p2)) < 0) return abs(q - p2);
  return distance_line_point(p1, p2, q);
}
pair<Point, Point> tanCP(Point c, double r, Point p) {
  pair<Point, Point> ans;
  double x = abs2(p - c);
  double d = x - r * r;
  if (d < 0) d = 0;
  Point q1 = (r * r / x) * (p - c);
  Point q2 = rot((p - c) * (-r * sqrt(d) / x), PI / 2);
  ans.first = (c + q1 - q2);
  ans.second = (c + q1 + q2);
  return ans;
}
Point D, P, S;
double Vp, V, R;
void init() {
  double x, y;
  D = Point(0, 0);
  scanf("%lf %lf %lf", &x, &y, &Vp);
  P = Point(x, y);
  scanf("%lf %lf %lf %lf", &x, &y, &V, &R);
  S = Point(x, y);
}
Point get_target(double time) {
  double dist = abs(P);
  double angle = arg(P);
  return Point(dist * cos((Vp / dist) * time + angle),
               dist * sin((Vp / dist) * time + angle));
}
double myabs(double x) { return x > 0 ? x : -x; }
double diff(double x, double y) {
  double d = myabs(x - y);
  for (; d <= 2 * PI;) d += 2 * PI;
  for (; d > 2 * PI;) d -= 2 * PI;
  return min(2 * PI - d, d);
}
bool check(double time) {
  Point tar = get_target(time);
  double cd = distance_segment_point(S, tar, D);
  if (cd >= R) {
    return abs(S - tar) <= time * V;
  }
  double d = 0.0;
  pair<Point, Point> SC = tanCP(D, R, S), TC = tanCP(D, R, tar);
  d += get_dist(S, SC.first) + get_dist(tar, TC.first);
  double mini = 1e9;
  mini = min(mini, diff(arg(SC.first), arg(TC.second)));
  mini = min(mini, diff(arg(SC.second), arg(TC.first)));
  d += R * mini;
  return d <= time * V;
}
double solve() {
  double low = 0.0, high = 1e9;
  for (int _ = 0; _ < 100; ++_) {
    double mid = (high + low) * 0.5;
    if (check(mid)) {
      high = mid;
    } else {
      low = mid;
    }
  }
  return low;
}
int main() {
  init();
  printf("%.13f\n", solve());
  return 0;
}

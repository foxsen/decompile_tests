#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
inline int sgn(double x) { return (x > eps) - (x < -eps); }
inline double sqr(double x) { return x * x; }
struct point {
  double x, y;
  point(double _x = 0, double _y = 0) { x = _x, y = _y; }
  point operator-(const point &a) { return point(x - a.x, y - a.y); }
  void input() { scanf("%lf%lf", &x, &y); }
  void output() { printf("%f %f\n", x, y); }
} p[150000];
inline double mult(point a, point b, point c) {
  return (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x);
}
inline double dist(point a, point b) {
  return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}
inline double dot(point a, point b) { return a.x * b.x + a.y * b.y; }
inline double cross(point a, point b) { return a.x * b.y - a.y * b.x; }
inline double _angle(point a, point b) {
  double res =
      acos(dot(a, b) /
           ((sqrt(a.x * a.x + a.y * a.y) * sqrt(b.x * b.x + b.y * b.y))));
  if (sgn(cross(a, b)) < 0) return 2 * pi - res;
  return res;
}
inline point intersection(point u1, point u2, point v1, point v2) {
  point ret = u1;
  double t = ((u1.x - v1.x) * (v1.y - v2.y) - (u1.y - v1.y) * (v1.x - v2.x)) /
             ((u1.x - u2.x) * (v1.y - v2.y) - (u1.y - u2.y) * (v1.x - v2.x));
  ret.x += (u2.x - u1.x) * t;
  ret.y += (u2.y - u1.y) * t;
  return ret;
}
inline point p_to_l(point p, point l1, point l2) {
  point t = p;
  t.x += l1.y - l2.y, t.y += l2.x - l1.x;
  return intersection(p, t, l1, l2);
}
inline void solve(point p[], int n, double &ans) {
  int j = 0;
  double sum = 0;
  for (int i = 0; i < n; i++) {
    j = max(j, i + 1);
    double angle = _angle(p[i + 1] - p[i], p[j + 1] - p[j]);
    while (sgn(angle - pi / 2) < 0 && j < i + n) {
      j++;
      sum += mult(p[j], p[j - 1], p[i]);
      angle = _angle(p[i + 1] - p[i], p[j + 1] - p[j]);
    }
    sum -= mult(p[j], p[i + 1], p[i]);
    point tmp = p_to_l(p[j], p[i + 1], p[i + n]);
    double res = dist(tmp, p[j]) * dist(tmp, p[i + 1]) / 2;
    ans = min(ans, res - fabs(sum) / 2);
  }
}
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++) p[i].input(), p[i + n] = p[i];
    double ans = 1e20;
    if (sgn(mult(p[2], p[1], p[0])) > 0) reverse(p, p + 2 * n);
    solve(p, n, ans);
    reverse(p, p + 2 * n);
    for (int i = 0; i < 2 * n; i++) p[i].x = -p[i].x;
    solve(p, n, ans);
    printf("%.20f\n", ans);
  }
}

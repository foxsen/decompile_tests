#include <bits/stdc++.h>
using namespace std;
const int maxn = 600;
const double eps = 1e-8;
inline int dcmp(double x) { return fabs(x) < eps ? 0 : (x > 0 ? 1 : -1); }
struct Point {
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  void scan() { scanf("%lf%lf", &x, &y); }
};
Point operator+(Point a, Point b) { return Point(a.x + b.x, a.y + b.y); }
Point operator-(Point a, Point b) { return Point(a.x - b.x, a.y - b.y); }
double operator^(Point a, Point b) { return a.x * b.x + a.y * b.y; }
double operator*(Point a, Point b) { return a.x * b.y - a.y * b.x; }
struct Rect {
  Point p[5];
  Point& operator[](int i) { return p[i]; }
  void scan() {
    int i;
    for (i = 0; i < 4; i++) p[i].scan();
    p[4] = p[0];
  }
  double area() {
    int i;
    double s = 0;
    for (i = 0; i < 4; i++) s += p[i] * p[i + 1];
    return s / 2;
  }
};
int n;
Rect r[maxn];
double ans = 0;
pair<double, int> pos[maxn * 8];
int ps;
inline double get_pos(Point a, Point b, Point p) {
  return dcmp(b.x - a.x) ? (p.x - a.x) / (b.x - a.x)
                         : (p.y - a.y) / (b.y - a.y);
}
double areaunion() {
  int i, j, ii, jj, d1, d2;
  double sum = 0, s1, s2, s0;
  for (i = 0; i < n; i++)
    for (ii = 0; ii < 4; ii++) {
      s0 = 0;
      ps = 0;
      pos[ps++] = make_pair(0, 0), pos[ps++] = make_pair(1, 0);
      for (j = 0; j < n; j++)
        if (i != j)
          for (jj = 0; jj < 4; jj++) {
            d1 = dcmp((r[i][ii + 1] - r[i][ii]) * (r[j][jj] - r[i][ii]));
            d2 = dcmp((r[i][ii + 1] - r[i][ii]) * (r[j][jj + 1] - r[i][ii]));
            if (!d1 && !d2) {
              if (dcmp((r[i][ii + 1] - r[i][ii]) ^ (r[j][jj + 1] - r[j][jj])) >
                      0 &&
                  i > j) {
                pos[ps++] =
                    make_pair(get_pos(r[i][ii], r[i][ii + 1], r[j][jj]), 1);
                pos[ps++] = make_pair(
                    get_pos(r[i][ii], r[i][ii + 1], r[j][jj + 1]), -1);
              }
            } else {
              s1 = (r[j][jj + 1] - r[j][jj]) * (r[i][ii] - r[j][jj]);
              s2 = (r[j][jj + 1] - r[j][jj]) * (r[i][ii + 1] - r[j][jj]);
              if (d1 < 0 && d2 >= 0)
                pos[ps++] = make_pair(s1 / (s1 - s2), -1);
              else if (d1 >= 0 && d2 < 0)
                pos[ps++] = make_pair(s1 / (s1 - s2), 1);
            }
          }
      sort(pos, pos + ps);
      double now, prv = min(max(pos[0].first, 0.0), 1.0);
      int cur = pos[0].second;
      for (j = 1; j < ps; j++) {
        now = min(max(pos[j].first, 0.0), 1.0);
        if (!cur) s0 += now - prv;
        cur += pos[j].second;
        prv = now;
      }
      sum += r[i][ii] * r[i][ii + 1] * s0;
    }
  return sum / 2;
}
int main() {
  int i, j;
  double s0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    r[i].scan();
    s0 = r[i].area();
    if (dcmp(s0) < 0) {
      reverse(r[i].p, r[i].p + 4);
      r[i][4] = r[i][0];
      s0 = -s0;
    }
    ans += s0;
  }
  ans /= areaunion();
  printf("%.9lf\n", ans);
  return 0;
}

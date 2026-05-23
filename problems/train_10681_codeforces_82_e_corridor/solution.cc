#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 + 5;
const double eps = 1e-10;
const int INF = 10000000;
struct point {
  double x, y;
  point() {}
  point(double x, double y) : x(x), y(y) {}
};
point operator-(point a, point b) { return point(a.x - b.x, a.y - b.y); }
point operator+(point a, point b) { return point(a.x + b.x, a.y + b.y); }
point operator*(point a, double b) { return point(a.x * b, a.y * b); }
bool operator==(point a, point b) { return a.x == b.x && a.y == b.y; }
double cross(point a, point b) { return a.x * b.y - a.y * b.x; }
int dcmp(double a) {
  if (fabs(a) < eps) return 0;
  return a > 0 ? 1 : -1;
}
double h, f, ans, l, r, l1[maxn], r1[maxn], l2[maxn], r2[maxn];
bool on(point a, point b, point c) {
  if ((a.x - b.x) * (a.x - c.x) <= 0 && (a.y - b.y) * (a.y - c.y) <= 0)
    return true;
  return false;
}
point get(point a, point b, point c, point d) {
  point u = a - c;
  double t = cross(d, u) / cross(b, d);
  point x = a + b * t;
  return x;
}
vector<point> cut(vector<point> poly, point A, point B) {
  vector<point> newpoly;
  int n = poly.size();
  for (int i = 0; i < n; i++) {
    point C = poly[i];
    point D = poly[(i + 1) % n];
    if (dcmp(cross(B - A, C - A)) >= 0) newpoly.push_back(C);
    if (dcmp(cross(B - A, C - D)) != 0) {
      point ip = get(A, B - A, C, D - C);
      if (on(ip, C, D)) newpoly.push_back(ip);
    }
  }
  return newpoly;
}
vector<point> poly;
void work() {
  while (poly.size() >= 3) {
    ans -= 0.5 * fabs(cross(poly[0] - poly[1], poly[2] - poly[1]));
    poly.erase(poly.begin() + 1);
  }
}
void pre() {
  poly.clear();
  poly.push_back(point(-INF, -h));
  poly.push_back(point(INF, -h));
  poly.push_back(point(INF, h));
  poly.push_back(point(-INF, h));
}
int main() {
  int n;
  scanf("%d %lf %lf", &n, &h, &f);
  for (int i = 0; i < n; i++) {
    scanf("%lf %lf", &l, &r);
    l1[i] = l, r1[i] = r, l2[i] = (f + h) / (f - h) * l,
    r2[i] = (f + h) / (f - h) * r;
    ans += 4 * f * h * (r - l) / (f - h);
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      pre();
      poly = cut(poly, point(l1[i], h), point(l2[i], -h));
      poly = cut(poly, point(r2[i], -h), point(r1[i], h));
      poly = cut(poly, point(l2[j], h), point(l1[j], -h));
      poly = cut(poly, point(r1[j], -h), point(r2[j], h));
      work();
    }
  printf("%.5lf\n", ans);
  return 0;
}

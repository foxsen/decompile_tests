#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct Pt {
  T x, y;
  Pt() {}
  Pt(T _x, T _y) : x(_x), y(_y) {}
  Pt(const Pt<T> &p) : x(p.x), y(p.y) {}
  Pt<T> operator+(const Pt<T> p) const { return Pt<T>(x + p.x, y + p.y); }
  Pt<T> operator-() const { return Pt<T>(-x, -y); }
  Pt<T> operator-(const Pt<T> p) const { return Pt<T>(x - p.x, y - p.y); }
  Pt<T> operator*(T t) const { return Pt<T>(x * t, y * t); }
  Pt<T> operator/(T t) const { return Pt<T>(x / t, y / t); }
  T dot(Pt<T> v) const { return x * v.x + y * v.y; }
  T cross(Pt<T> v) const { return x * v.y - y * v.x; }
  Pt<T> mid(const Pt<T> p) { return Pt<T>((x + p.x) / 2, (y + p.y) / 2); }
  T d2() { return x * x + y * y; }
  double d() { return sqrt(d2()); }
  Pt<T> rot(double th) {
    double c = cos(th), s = sin(th);
    return Pt<T>(c * x - s * y, s * x + c * y);
  }
  Pt<T> rot90() { return Pt<T>(-y, x); }
  bool operator==(const Pt<T> pt) const { return x == pt.x && y == pt.y; }
  bool operator<(const Pt<T> &pt) const {
    return x < pt.x || (x == pt.x && y < pt.y);
  }
  void print() { printf("(%d,%d)", x, y); }
};
Pt<double> qs[7];
int main() {
  Pt<double> p, v;
  int a, b, c, d;
  scanf("%lf%lf%lf%lf%d%d%d%d", &p.x, &p.y, &v.x, &v.y, &a, &b, &c, &d);
  qs[0] = Pt<double>(b, 0);
  qs[1] = Pt<double>(0, 0.5 * a);
  qs[2] = Pt<double>(0, 0.5 * c);
  qs[3] = Pt<double>(-d, 0.5 * c);
  qs[4] = Pt<double>(-d, -0.5 * c);
  qs[5] = Pt<double>(0, -0.5 * c);
  qs[6] = Pt<double>(0, -0.5 * a);
  double th = atan2(v.y, v.x);
  for (int i = 0; i < 7; i++) {
    Pt<double> r = qs[i].rot(th) + p;
    printf("%.12lf %.12lf\n", r.x, r.y);
  }
  return 0;
}

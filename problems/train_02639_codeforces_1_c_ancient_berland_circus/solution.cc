#include <bits/stdc++.h>
using namespace std;
const double PI = 3.1415926535897932;
struct Point {
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  Point operator+(const Point &A) const { return Point(x + A.x, y + A.y); }
  Point operator-(const Point &A) const { return Point(x - A.x, y - A.y); }
  Point operator*(double p) const { return Point(x * p, y * p); }
  Point operator/(double p) const { return Point(x / p, y / p); }
};
double Cross(Point A, Point B) { return A.x * B.y - A.y * B.x; }
Point getLineIntersection(Point P, Point v, Point Q, Point w) {
  Point u = P - Q;
  double t = Cross(w, u) / Cross(v, w);
  return P + v * t;
}
inline double Dot(Point A, Point B) { return A.x * B.x + A.y * B.y; }
inline double Length(Point A) { return sqrt(Dot(A, A)); }
Point A, B, C;
inline Point read_p() {
  Point P;
  scanf("%lf%lf", &P.x, &P.y);
  return P;
}
inline Point rev(Point A) { return Point(-A.y, A.x); }
inline Point getR() {
  Point D = (A + B) / 2, E = (B + C) / 2;
  Point ret = getLineIntersection(D, rev(B - A), E, rev(C - B));
  return ret;
}
int main() {
  A = read_p();
  B = read_p();
  C = read_p();
  Point o = getR();
  double R = Length(o - A);
  double ang[3];
  ang[0] = 2 * PI - acos((R * R * 2 - Dot(A - B, A - B)) / 2 / R / R);
  ang[1] = 2 * PI - acos((R * R * 2 - Dot(A - C, A - C)) / 2 / R / R);
  ang[2] = 2 * PI - acos((R * R * 2 - Dot(B - C, B - C)) / 2 / R / R);
  int num = 0;
  for (int i = 3; i <= 100; ++i) {
    double can = (double)2 * PI / i;
    int flag = 0;
    for (int j = 0; j < 3; ++j) {
      int t = (int)(ang[j] / can + 0.5);
      if (fabs(ang[j] - t * can) < 0.0001) flag++;
    }
    if (flag == 3) {
      num = i;
      break;
    }
  }
  double sum = (double)num * R * R * sin(2.0 * PI / (double)num) / 2.0;
  printf("%.6lf\n", sum);
}

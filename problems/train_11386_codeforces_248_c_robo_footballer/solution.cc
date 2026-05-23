#include <bits/stdc++.h>
using namespace std;
double cross(complex<double> a, complex<double> b) {
  return a.real() * b.imag() - a.imag() * b.real();
}
double distanceLnPt(complex<double> a, complex<double> b, complex<double> c) {
  return abs(cross(c - a, b - a)) / abs(b - a);
}
complex<double> intersectionLn(complex<double> a1, complex<double> a2,
                               complex<double> b1, complex<double> b2) {
  complex<double> a = a2 - a1;
  complex<double> b = b2 - b1;
  return a1 + a * cross(b, b1 - a1) / cross(b, a);
}
int main() {
  int y1, y2, yw, xb, yb, r;
  cin >> y1 >> y2 >> yw >> xb >> yb >> r;
  yw -= r;
  complex<double> a(xb, yb);
  complex<double> b(0, 2 * yw - (y1 + r));
  complex<double> c(0, 2 * yw - y2);
  double d = distanceLnPt(a, b, c);
  complex<double> pw =
      intersectionLn(a, b, complex<double>(0, yw), complex<double>(1, yw));
  if (d + (1e-8) > r)
    printf("%.18lf", pw.real());
  else
    puts("-1");
  return 0;
}

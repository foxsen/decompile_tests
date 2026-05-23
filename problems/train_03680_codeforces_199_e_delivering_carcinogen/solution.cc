#include <bits/stdc++.h>
double xp, yp, vp, x, y, v, r, xpr, xpa;
int ok(double tim) {
  double jd = tim * vp / xpr;
  double xpnow = cos(xpa + jd) * xpr;
  double ypnow = sin(xpa + jd) * xpr;
  double dis1 = sqrt(x * x + y * y);
  double hd1 = acos(r / dis1);
  double dis2 = sqrt(xpnow * xpnow + ypnow * ypnow);
  double hd2 = acos(r / dis2);
  double dis = sqrt((x - xpnow) * (x - xpnow) + (y - ypnow) * (y - ypnow));
  if (dis >= dis1 * sin(hd1) + dis2 * sin(hd2)) {
    double jiajiao = acos((x * xpnow + y * ypnow) / dis1 / dis2);
    double hc = (jiajiao - hd1 - hd2) * r;
    double disllh = dis1 * sin(hd1) + dis2 * sin(hd2) + hc;
    if (disllh > v * tim)
      return 0;
    else
      return 1;
  } else {
    double disptp = sqrt((x - xpnow) * (x - xpnow) + (y - ypnow) * (y - ypnow));
    if (disptp > v * tim)
      return 0;
    else
      return 1;
  }
}
int main() {
  while (~scanf("%lf%lf%lf%lf%lf%lf%lf", &xp, &yp, &vp, &x, &y, &v, &r)) {
    xpr = sqrt(xp * xp + yp * yp);
    xpa = atan2(yp, xp);
    double L = 0;
    double R = 1000000;
    while (L - R <= -1e-6) {
      double M = (L + R) / 2;
      if (ok(M)) {
        R = M;
      } else {
        L = M;
      }
    }
    printf("%.9f\n", L);
  }
  return 0;
}

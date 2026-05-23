#include <bits/stdc++.h>
using namespace std;
double a, v, l, d, w;
double Move(double v1, double v2, double a, double d) {
  double ret = 0;
  double s_2 = (v2 * v2 - v1 * v1) / (2 * a);
  if (d > s_2) {
    ret += (v2 - v1) / a;
    ret += (d - s_2) / v2;
  } else {
    double v_tmp = sqrt(v1 * v1 + 2 * a * d);
    ret += (v_tmp - v1) / a;
  }
  return ret;
}
int main() {
  scanf("%lf%lf", &a, &v);
  scanf("%lf%lf%lf", &l, &d, &w);
  double ans = 0;
  if (w < v) {
    double s_2 = w * w / (2 * a);
    if (s_2 >= d)
      ans = Move(0, v, a, l);
    else {
      double s_3 = (2 * v * v - w * w) / (2 * a);
      if (d > s_3) {
        ans += (2 * v - w) / a;
        ans += (d - s_3) / v;
      } else {
        double v_2 = sqrt((w * w + 2 * a * d) / 2);
        ans += (2 * v_2 - w) / a;
      }
      ans += Move(w, v, a, l - d);
    }
  } else
    ans = Move(0, v, a, l);
  printf("%.12lf\n", ans);
  return 0;
}

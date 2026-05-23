#include <bits/stdc++.h>
using namespace std;
const int INF_MAX = 1 << 30;
const double INF_MIN = 1e-10;
const int MAX_N = 1000 + 5;
const int MAX_M = 1000 + 5;
const long long int MOD = 7;
const double PI = acos(-1.0);
const double E = exp(1.0);
bool lt(double a, double b) { return a - b < -INF_MIN * (abs(a) + abs(b)); }
bool leq(double a, double b) { return a - b <= INF_MIN * (abs(a) + abs(b)); }
bool eq(double a, double b) {
  return abs(a - b) <= INF_MIN * (abs(a) + abs(b));
}
double add(double a, double b) {
  if (abs(a + b) < INF_MIN * (abs(a) + abs(b))) {
    return 0;
  }
  return a + b;
}
int main() {
  ios::sync_with_stdio(false);
  double r, x1, y1, x2, y2;
  scanf("%lf %lf %lf %lf %lf", &r, &x1, &y1, &x2, &y2);
  double r1 =
      sqrt(add(add(x1, -x2) * add(x1, -x2), add(y1, -y2) * add(y1, -y2)));
  if (lt(r, r1)) {
    printf("%f %f %f\n", x1, y1, r);
  } else {
    double r2, x3, y3;
    if (eq(r1, 0)) {
      x3 = add(x1, r / 2), y3 = y1;
      r2 = r / 2;
    } else {
      double dx, dy;
      dx = r * (add(x1, -x2) / r1);
      dy = r * (add(y1, -y2) / r1);
      double tmpX = add(x1, dx), tmpY = add(y1, dy);
      x3 = add(x2, tmpX) / 2, y3 = add(y2, tmpY) / 2;
      r2 = add(r, r1) / 2;
    }
    printf("%.20f %.20f %.20f\n", x3, y3, r2);
  }
  return 0;
}

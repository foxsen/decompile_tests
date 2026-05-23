#include <bits/stdc++.h>
using namespace std;
const long long INF = 999999999999999999;
const double PI = acos(-1.0);
void stop() { exit(0); }
int main() {
  double a, b, c, x1, y1, x2, y2;
  cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;
  double var1 = abs(x1 - x2) + abs(y1 - y2);
  double var2 = 0, var3 = 0, var4 = 0, var5 = 0;
  double y11;
  if (-x1 * a - c == 0 && b == 0) {
    y11 = 0;
  } else if (b == 0) {
    y11 = INF;
  } else {
    y11 = (-x1 * a - c) / b;
  }
  double x11;
  if (-y1 * b - c == 0 && a == 0) {
    x11 = 0;
  } else if (a == 0) {
    x11 = INF;
  } else {
    x11 = (-y1 * b - c) / a;
  }
  double y22;
  if (-x2 * a - c == 0 && b == 0) {
    y22 = 0;
  } else if (b == 0) {
    y22 = INF;
  } else {
    y22 = (-x2 * a - c) / b;
  }
  double x22;
  if (-y2 * b - c == 0 && a == 0) {
    x22 = 0;
  } else if (a == 0) {
    x22 = INF;
  } else {
    x22 = (-y2 * b - c) / a;
  }
  var2 += abs(x1 - x11);
  var2 += abs(x2 - x22);
  var2 += sqrt((y1 - y2) * (y1 - y2) + (x11 - x22) * (x11 - x22));
  var3 += abs(x1 - x11);
  var3 += abs(y2 - y22);
  var3 += sqrt((y1 - y22) * (y1 - y22) + (x11 - x2) * (x11 - x2));
  var4 += abs(y1 - y11);
  var4 += abs(x2 - x22);
  var4 += sqrt((y11 - y2) * (y11 - y2) + (x1 - x22) * (x1 - x22));
  var5 += abs(y1 - y11);
  var5 += abs(y2 - y22);
  var5 += sqrt((y11 - y22) * (y11 - y22) + (x1 - x2) * (x1 - x2));
  double res = var1;
  res = min(res, var2);
  res = min(res, var3);
  res = min(res, var4);
  res = min(res, var5);
  printf("%.8lf", res);
  stop();
}

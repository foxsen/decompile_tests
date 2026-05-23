#include <bits/stdc++.h>
using namespace std;
bool eq(double x, double y) { return fabs(x - y) < 1e-6; }
bool ls(double x, double y) { return x + 1e-6 < y; }
bool gr(double x, double y) { return x - 1e-6 > y; }
bool circleThroughPoints(double x1, double y1, double x2, double y2, double x3,
                         double y3, double &x, double &y, double &r) {
  double d = 2 * (y1 * x3 + y2 * x1 - y2 * x3 - y1 * x2 - y3 * x1 + y3 * x2);
  if (eq(d, 0)) return false;
  x = (y2 * x1 * x1 - y3 * x1 * x1 - y2 * y2 * y1 + y3 * y3 * y1 +
       x2 * x2 * y3 + y1 * y1 * y2 + x3 * x3 * y1 - y3 * y3 * y2 -
       x3 * x3 * y2 - x2 * x2 * y1 + y2 * y2 * y3 - y1 * y1 * y3) /
      d;
  y = (x1 * x1 * x3 + y1 * y1 * x3 + x2 * x2 * x1 - x2 * x2 * x3 +
       y2 * y2 * x1 - y2 * y2 * x3 - x1 * x1 * x2 - y1 * y1 * x2 -
       x3 * x3 * x1 + x3 * x3 * x2 - y3 * y3 * x1 + y3 * y3 * x2) /
      d;
  r = sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y));
  return true;
}
double sqr(double h) { return h * h; }
int n;
double x[128], y[128];
vector<double> v;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  double a, b, r;
  bool cand;
  bool found = false;
  double ans;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if (!circleThroughPoints(x[i], y[i], x[j], y[j], x[k], y[k], a, b, r))
          continue;
        v.clear();
        cand = true;
        for (int t = 0; t < n; t++) {
          if (ls(sqrt(sqr(x[t] - a) + sqr(y[t] - b)), r)) {
            cand = false;
            break;
          }
          if (eq(sqrt(sqr(x[t] - a) + sqr(y[t] - b)), r))
            v.push_back(atan2(y[t] - b, x[t] - a));
        }
        if (cand == false) continue;
        sort(v.begin(), v.end());
        v.push_back(v[0] + 2 * 3.1415926535897932384626433832795);
        for (int g = 0; g < v.size() - 1; g++) {
          double dif = v[g + 1] - v[g];
          if (gr(dif, 3.1415926535897932384626433832795) ||
              eq(dif, 3.1415926535897932384626433832795)) {
            cand = false;
          }
        }
        if (cand == true) {
          if (found == false) {
            ans = r;
            found = true;
          } else {
            ans = max(ans, r);
          }
        }
      }
    }
  }
  if (found == false)
    cout << -1 << endl;
  else
    printf("%0.9lf\n", ans);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long t1, t2, x1, x2, t0;
int main() {
  long long i;
  while (cin >> t1 >> t2 >> x1 >> x2 >> t0) {
    if (t2 == t0 && t0 != t1) {
      cout << "0"
           << " " << x2 << endl;
      continue;
    }
    if (t2 != t0 && t0 == t1) {
      cout << x1 << " "
           << "0" << endl;
      continue;
    }
    if (t2 == t0 && t0 == t1) {
      cout << x1 << " " << x2 << endl;
      continue;
    }
    long long y1, y2;
    double tt = 99999999;
    long long tmp;
    for (i = 0; i <= x1; i++) {
      if (i == 0)
        tmp = x2;
      else {
        tmp = i * (t0 - t1);
        if (tmp % (t2 - t0) != 0)
          tmp = (tmp / (t2 - t0)) + 1;
        else
          tmp = (tmp / (t2 - t0));
        if (tmp > x2 || tmp < 0) continue;
        if (tmp < 0)
          while (1)
            ;
      }
      double t;
      t = (tmp * 1.0 * t2 * 1.0 + i * 1.0 * t1 * 1.0) * 1.0 /
          (i * 1.0 + tmp * 1.0);
      if (t >= t0 * 1.0 && t < tt) {
        y1 = i, y2 = tmp;
        tt = t;
      } else if (t >= t0 * 1.0 && fabs(t - tt) < 1e-20) {
        if (i + tmp > y1 + y2) {
          y1 = i, y2 = tmp;
          tt = t;
        }
      }
    }
    cout << y1 << " " << y2 << endl;
  }
  return 0;
}

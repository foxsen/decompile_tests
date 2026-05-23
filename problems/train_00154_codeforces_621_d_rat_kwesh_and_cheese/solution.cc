#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979;
const double eps = 1e-6;
const long long _INF = 1e18;
const int INF = 1e9;
const int maxn = 1000010;
const int maxm = 1000010;
double x, y, z;
char ans[12][10] = {"x^y^z", "x^z^y", "(x^y)^z", "(x^z)^y",
                    "y^x^z", "y^z^x", "(y^x)^z", "(y^z)^x",
                    "z^x^y", "z^y^x", "(z^x)^y", "(z^y)^x"};
double a[12];
int main() {
  while (~scanf("%lf %lf %lf", &x, &y, &z)) {
    if (x > 1 || y > 1 || z > 1) {
      if (x > 1) {
        a[0] = z * log(y) + log(log(x));
        a[1] = y * log(z) + log(log(x));
        a[2] = log(y) + log(z) + log(log(x));
        a[3] = -_INF;
      } else
        a[0] = a[1] = a[2] = a[3] = -_INF;
      if (y > 1) {
        a[4] = z * log(x) + log(log(y));
        a[5] = x * log(z) + log(log(y));
        a[6] = log(x) + log(z) + log(log(y));
        a[7] = -_INF;
      } else
        a[4] = a[5] = a[6] = a[7] = -_INF;
      if (z > 1) {
        a[8] = y * log(x) + log(log(z));
        a[9] = x * log(y) + log(log(z));
        a[10] = log(x) + log(y) + log(log(z));
        a[11] = -_INF;
      } else
        a[8] = a[9] = a[10] = a[11] = -_INF;
      int idx = 0;
      double x = a[0];
      for (int i = 1; i < 12; ++i)
        if (a[i] > x) {
          idx = i;
          x = a[i];
        }
      puts(ans[idx]);
    } else {
      a[0] = z * log(y) + log(log(1.0 / x));
      a[1] = y * log(z) + log(log(1.0 / x));
      a[2] = log(y) + log(z) + log(log(1.0 / x));
      a[3] = _INF;
      a[4] = z * log(x) + log(log(1.0 / y));
      a[5] = x * log(z) + log(log(1.0 / y));
      a[6] = log(x) + log(z) + log(log(1.0 / y));
      a[7] = _INF;
      a[8] = y * log(x) + log(log(1.0 / z));
      a[9] = x * log(y) + log(log(1.0 / z));
      a[10] = log(x) + log(y) + log(log(1.0 / z));
      a[11] = _INF;
      int idx = 0;
      double x = a[0];
      for (int i = 1; i < 12; ++i)
        if (a[i] < x) {
          idx = i;
          x = a[i];
        }
      puts(ans[idx]);
    }
  }
  return 0;
}

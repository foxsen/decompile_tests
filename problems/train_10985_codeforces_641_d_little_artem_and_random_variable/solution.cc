#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
pair<long double, long double> SolveSqr(long double b, long double c) {
  long double D = b * b - 4 * c;
  if (D < 0)
    D = 0;
  else
    D = sqrt(D);
  long double x = (-b - D) / 2;
  long double y = (-b + D) / 2;
  return make_pair(x, y);
}
int n;
double max_p[MAXN];
double min_p[MAXN];
long double a[MAXN], b[MAXN];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lf", &max_p[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%lf", &min_p[i]);
  }
  long double _sum = 0.0;
  long double _prod = 0.0;
  a[0] = b[0] = 0.0;
  for (int i = 1; i <= n; ++i) {
    long double amb = ((long double)max_p[i]) + _prod;
    long double apb = ((long double)max_p[i]) + ((long double)min_p[i]) + _sum;
    auto res = SolveSqr(-apb, amb);
    a[i] = res.first;
    b[i] = res.second;
    _sum = apb;
    _prod = amb;
  }
  for (int i = 1; i <= n; ++i) {
    double val = a[i] - a[i - 1];
    if (val < 0.0) val = 0.0;
    if (val > 1.0) val = 1.0;
    printf("%.12f%c", val, (i == n) ? '\n' : ' ');
  }
  for (int i = 1; i <= n; ++i) {
    double val = b[i] - b[i - 1];
    if (val < 0.0) val = 0.0;
    if (val > 1.0) val = 1.0;
    printf("%.12f%c", val, (i == n) ? '\n' : ' ');
  }
  return 0;
}

#include <bits/stdc++.h>
double x, y;
int n;
int main(void) {
  int i;
  double a, b, tmp;
  while (scanf("%lf %lf %d", &x, &y, &n) != EOF) {
    a = floor(x / y);
    b = 1.0;
    for (i = 1; i <= n; i++) {
      tmp = floor((x * (double)i) / y);
      if (fabs(x / y - tmp / (double)i) + 1E-15 < fabs(x / y - a / b)) {
        a = tmp;
        b = (double)i;
      }
      tmp = ceil((x * (double)i) / y);
      if (fabs(x / y - tmp / (double)i) + 1E-15 < fabs(x / y - a / b)) {
        a = tmp;
        b = (double)i;
      }
    }
    printf("%.0lf/%.0lf\n", a, b);
  }
  return 0;
}

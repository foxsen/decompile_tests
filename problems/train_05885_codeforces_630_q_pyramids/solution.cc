#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;
int main() {
  double a, b, c;
  scanf("%lf%lf%lf", &a, &b, &c);
  printf("%.18lf\n", a * a * a * sqrt(2) / 12 + b * b * b / 3 / sqrt(2) +
                         c * c * c * 0.301502832395831588);
  return 0;
}

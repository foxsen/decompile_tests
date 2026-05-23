#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int Mod = 1000000007;
const int INF = 0x3f3f3f3f;
const long long LL_INF = 0x3f3f3f3f3f3f3f3f;
const double e = exp(1);
const double PI = acos(-1);
const double ERR = 1e-10;
int main() {
  double y_1, y_2, y_w, x_b, y_b, r;
  scanf("%lf%lf%lf%lf%lf%lf", &y_1, &y_2, &y_w, &x_b, &y_b, &r);
  y_w -= r;
  y_1 += r;
  double x_w = x_b / (1.0 + (y_w - y_b) / (y_w - y_1));
  double h = (y_2 - y_1) * x_w / sqrt(x_w * x_w + (y_w - y_1) * (y_w - y_1));
  if (h < r + 1e-8)
    printf("-1\n");
  else
    printf("%.20f\n", x_w);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
double a, b, c, d;
double ans = 0;
int main() {
  cin >> a >> b >> c >> d;
  ans = (a / b) / (1 - (1 - a / b) * (1 - c / d));
  printf("%.12lf\n", ans);
}

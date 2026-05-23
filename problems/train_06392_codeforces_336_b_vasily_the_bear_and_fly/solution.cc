#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
double a[N];
int main() {
  int m, r;
  scanf("%d %d", &m, &r);
  double ans = 0;
  a[0] = 2 * r, a[1] = (2 + sqrt(2)) * r, a[2] = (2 + 2 * sqrt(2)) * r;
  for (int i = 3; i < m; i++) {
    a[i] = a[i - 1] + 2 * r;
  }
  ans = a[0] * m;
  for (int i = 1; i < m; i++) {
    ans = ans + a[i] * (m - i) * 2;
  }
  ans = ans / m / m;
  printf("%.10lf\n", ans);
  return 0;
}

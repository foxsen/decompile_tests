#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  double t1, t2, v1, v2, l;
  int s;
  cin >> n >> l >> v1 >> v2 >> k;
  if (n % k == 0)
    s = n / k - 1;
  else
    s = n / k;
  if (k >= n) {
    printf("%0.9lf\n", l / v2);
    return 0;
  }
  t1 = l / (s * (2 * v1 * v2 / (v1 + v2)) + v2);
  t2 = (l - v2 * t1) / v1;
  printf("%0.9lf\n", t1 + t2);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
inline bool Ok(long double a, long double b, long double c) {}
int main() {
  long double x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int n, ret = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    long double a, b, c;
    cin >> a >> b >> c;
    long double Y1 = (-a * x1 - c) / b;
    long double Y2 = (-a * x2 - c) / b;
    ret += ((Y1 - y1) * (Y2 - y2) <= 0);
  }
  cout << ret;
  return 0;
}

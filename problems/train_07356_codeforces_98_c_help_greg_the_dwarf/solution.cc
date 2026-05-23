#include <bits/stdc++.h>
using namespace std;
long long a, b, l;
const double pi = acos(-1);
double d(double theta) {
  return (a + b * tan(theta) - l * sin(theta)) * cos(theta);
}
double solve() {
  double beg = 0, end = pi / 2;
  while (end - beg > 1e-8) {
    double m1 = beg + (end - beg) / 3;
    double m2 = end - (end - beg) / 3;
    if (d(m1) < d(m2))
      end = m2;
    else
      beg = m1;
  }
  return d(beg);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> a >> b >> l;
  double ans;
  if (l <= b)
    ans = min(l, a);
  else if (l <= a)
    ans = min(l, b);
  else {
    ans = solve();
    if (ans < 0) return cout << "My poor head =(", 0;
  }
  cout << ans;
}

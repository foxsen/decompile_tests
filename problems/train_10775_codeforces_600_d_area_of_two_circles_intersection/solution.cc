#include <bits/stdc++.h>
using namespace std;
int main() {
  long double x, y, r, X, Y, R, d, a, b, pi = acos(-1), ans;
  cin >> x >> y >> r >> X >> Y >> R;
  d = sqrt((X - x) * (X - x) + (Y - y) * (Y - y));
  if (R + r <= d)
    ans = 0;
  else if (R + d <= r || r + d <= R)
    ans = pi * min(r, R) * min(r, R);
  else {
    a = acos((r * r + d * d - R * R) / (2.0 * d * r));
    b = acos((R * R + d * d - r * r) / (2.0 * d * R));
    ans = (long double)(r * r * (a - sin(a) * cos(a)) +
                        R * R * (b - sin(b) * cos(b)));
  }
  cout << fixed << setprecision(20) << ans << endl;
  return 0;
}

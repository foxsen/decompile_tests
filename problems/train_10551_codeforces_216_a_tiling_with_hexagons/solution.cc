#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
int dblcmp(double d) {
  if (fabs(d) < eps) return 0;
  return d > eps ? 1 : -1;
}
int a, b, c;
int main() {
  int i, ans = 0;
  cin >> a >> b >> c;
  for (i = 1; i <= a + b - 1; i++) {
    ans += c;
    if (i < min(a, b))
      c++;
    else if (i >= min(a, b) && i < max(a, b))
      ;
    else
      c--;
  }
  cout << ans << endl;
  return 0;
}

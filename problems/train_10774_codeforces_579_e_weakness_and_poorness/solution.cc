#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)2e5 + 10;
const int INF = (int)0x7f7f7f7f;
int n, a[MAXN];
double b[MAXN], s[MAXN];
double MCS() {
  s[0] = 0;
  for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + b[i];
  double m = 0;
  double ans = -INF;
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, s[i] - m);
    m = min(m, s[i]);
  }
  return ans;
}
void Cal(double x, double &p, double &q) {
  for (int i = 1; i <= n; ++i) b[i] = a[i] - x;
  p = MCS();
  for (int i = 1; i <= n; ++i) b[i] = x - a[i];
  q = MCS();
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  double l = *min_element(a + 1, a + 1 + n);
  double r = *max_element(a + 1, a + 1 + n);
  for (int k = 0; k <= 500; ++k) {
    double m = (l + r) / 2;
    double x, y;
    Cal(m, x, y);
    if (x > y)
      l = m;
    else
      r = m;
  }
  double x, y, ans;
  Cal(l, x, y);
  ans = max(x, y);
  Cal(r, x, y);
  ans = max(ans, max(x, y));
  cout << fixed << setprecision(10) << ans;
  return 0;
}

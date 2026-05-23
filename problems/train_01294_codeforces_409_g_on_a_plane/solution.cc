#include <bits/stdc++.h>
using namespace std;
int main() {
  double x, y[1010], n, ans, all = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y[i];
    all += y[i];
  }
  ans = 5 + all * 1.0 / n;
  printf("%.3lf", ans);
  return 0;
}

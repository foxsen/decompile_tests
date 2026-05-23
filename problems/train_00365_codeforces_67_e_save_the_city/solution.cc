#include <bits/stdc++.h>
using namespace std;
long long test(double x) {
  if (x < 0) {
    return (test(-x + 1.0 - 0.000000001)) * -1;
  }
  return x;
}
int main() {
  int n;
  long long x[2000] = {};
  long long y[2000] = {};
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
  long long minx = min(x[1], x[2]);
  long long maxx = max(x[1], x[2]);
  for (int i = 3; i < n; i++) {
    if (y[i] == y[i + 1]) {
      if (y[3] < y[1] && x[i + 1] > x[i]) {
        minx = 1e9;
      }
      if (y[3] > y[1] && x[i + 1] < x[i]) {
        minx = 1e9;
      }
      continue;
    }
    long long disty = y[i] - y[i + 1];
    long long distx = x[i + 1] - x[i];
    long long distcom = x[i] * disty + y[i] * distx;
    double inter = (distcom - y[1] * distx) * 1.0 / disty;
    if (y[i] < y[i + 1]) {
      minx = max(minx, test(inter + 1 - 0.000000001));
    } else {
      maxx = min(maxx, test(inter));
    }
  }
  if (minx > maxx) {
    minx = maxx + 1;
  }
  cout << maxx - minx + 1 << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int a[100001];
int main() {
  int n, m, k, c, d;
  cin >> c >> d >> n >> m >> k;
  int t = n * m - k;
  if (t <= 0) {
    cout << 0;
    return 0;
  }
  int min = 2e9;
  int x, y;
  x = ceil(1.0 * t / n);
  y = 0;
  while (x >= 0) {
    if (min > c * x + d * y) min = c * x + d * y;
    --x;
    y = t - n * x;
  }
  cout << min;
  return 0;
}

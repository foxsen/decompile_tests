#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
const double PI = acos(-1.0);
const int oo = 1 << 29;
const int N = 101111;
int n, x, y, c;
long long calc(long long m) {
  int d[4] = {x - 1, y - 1, n - x, n - y};
  long long ret = m * (m + 1) * 2 + 1;
  for (int i = 0; i < 4; i++) {
    if (m <= d[i]) continue;
    long long t = m - d[i];
    ret -= t * t;
  }
  for (int i = 0; i < 4; i += 2) {
    for (int j = 1; j < 4; j += 2) {
      long long t = m - d[i] - d[j] - 1;
      if (t <= 0) continue;
      ret += t * (t + 1) / 2;
    }
  }
  return ret;
}
int main() {
  scanf("%d%d%d%d", &n, &x, &y, &c);
  long long l = 0, r = 2ll * 1000000000;
  while (l < r) {
    long long m = (l + r) / 2;
    if (calc(m) >= c) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  cout << r << endl;
  return 0;
}

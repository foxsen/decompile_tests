#include <bits/stdc++.h>
using namespace std;
int main() {
  cout << fixed;
  cout.precision(9);
  int n, x1, y1, x2, y2;
  cin >> n >> x1 >> y1 >> x2 >> y2;
  int res = 1000000;
  if (x1 == x2 && (x1 == 0 || x1 == n)) {
    res = min(res, abs(y1 - y2));
  }
  if (y1 == y2 && (y1 == 0 || y1 == n)) {
    res = min(res, abs(x1 - x2));
  }
  for (int i = 0; i <= n; i += n) {
    for (int j = 0; j <= n; j += n) {
      int ch = abs(x1 - i) + abs(x2 - i) + abs(y1 - j) + abs(y2 - j);
      res = min(res, ch);
    }
  }
  cout << res << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y) {
  if (y == 0)
    return 1;
  else if (y % 2 == 0)
    return power(x, y / 2) * power(x, y / 2);
  else
    return x * power(x, y / 2) * power(x, y / 2);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2) {
      cout << abs(y1 - y2) << '\n';
    } else if (y1 == y2) {
      cout << abs(x1 - x2) << '\n';
    } else {
      cout << abs(x1 - x2) + abs(y1 - y2) + 2 << '\n';
    }
  }
  return 0;
}

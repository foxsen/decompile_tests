#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, a, jwb = 0, jwbn = 0;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a;
    if (a <= k && a > 0) {
      if (jwbn == 0) {
        jwbn = i;
        jwb = a;
      } else if (abs(m - i) < abs(m - jwbn)) {
        jwbn = i;
        jwb = a;
      }
    }
  }
  cout << abs(jwbn - m) * 10 << endl;
  return 0;
}

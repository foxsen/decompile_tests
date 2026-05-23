#include <bits/stdc++.h>
using namespace std;
int main() {
  int i = 0, k = 0, m, s1 = 0, j, n, r = 0, l = 0, l1 = 0, c = 0, t, d = 0, na,
      nb;
  cin >> n >> m >> k;
  for (i = 1; i <= n; i++) {
    if (m >= 2 * i && k >= 4 * i) {
      d = i;
    }
  }
  cout << (d)*7;
  return 0;
}

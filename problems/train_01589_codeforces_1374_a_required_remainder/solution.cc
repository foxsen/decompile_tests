#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y, k, t, i, r;
  cin >> t;
  for (i = 0; i < t; i++) {
    cin >> x >> y >> n;
    r = ((n / x) * x) + y;
    if (r > n) {
      r -= x;
    }
    cout << r << endl;
  }
}

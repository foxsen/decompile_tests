#include <bits/stdc++.h>
using namespace std;
int main() {
  long cn1, cn2, x, y;
  cin >> cn1 >> cn2 >> x >> y;
  int lo = 1, hi = 0x7FFFFFFF, mid;
  while (lo < hi) {
    mid = lo + (hi - lo) / 2;
    int rex = mid - (mid / x);
    int rey = mid - (mid / y);
    int total = mid - (mid / (x * y));
    if (cn1 <= rex && cn2 <= rey && (cn1 + cn2) <= total)
      hi = mid;
    else
      lo = mid + 1;
  }
  cout << hi << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t) {
    t--;
    long long l;
    cin >> l;
    long long r;
    cin >> r;
    long long m;
    cin >> m;
    long long a = -1;
    long long b = -1;
    long long c = -1;
    for (long long i = l; i <= r; i++) {
      long long z = m % i;
      long long y = m / i;
      if (z == 0 && y != 0) {
        cout << i << " " << l << " " << l << endl;
        break;
      }
      if (y != 0 && z <= (r - l)) {
        cout << i << " " << l + z << " " << l << endl;
        break;
      }
      if ((r - l) >= (i - z)) {
        cout << i << " " << l << " " << l + (i - z) << endl;
        break;
      }
    }
  }
}

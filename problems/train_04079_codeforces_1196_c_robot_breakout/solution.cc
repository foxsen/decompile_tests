#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int q;
  cin >> q;
  for (int j = 0; j < q; j++) {
    int n;
    cin >> n;
    int x, y, f1, f2, f3, f4;
    int a = -100000;
    int b = 100000;
    int c = 100000;
    int d = -100000;
    for (int i = 0; i < n; i++) {
      cin >> x >> y >> f1 >> f2 >> f3 >> f4;
      if (f1 == 0) {
        if (x > a) {
          a = x;
        }
      }
      if (f2 == 0) {
        if (y < b) {
          b = y;
        }
      }
      if (f3 == 0) {
        if (x < c) {
          c = x;
        }
      }
      if (f4 == 0) {
        if (y > d) {
          d = y;
        }
      }
    }
    if (a > c || b < d) {
      cout << 0 << endl;
      continue;
    }
    cout << 1 << " " << a << " " << d << endl;
  }
  return 0;
}

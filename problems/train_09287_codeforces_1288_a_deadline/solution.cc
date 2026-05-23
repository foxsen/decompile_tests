#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    double n, d;
    cin >> n >> d;
    if (n >= d) {
      cout << "YES" << endl;
      continue;
    }
    double x = 1, f = 0;
    double y;
    for (int i = 0; i < d; i++) {
      y = double(d / (x + 1));
      y = ceil(y);
      if ((x + y) <= n) {
        cout << "YES" << endl;
        f = 1;
        break;
      }
      x++;
      if (x >= n) {
        break;
      }
    }
    if (f == 1) {
      continue;
    } else
      cout << "NO" << endl;
  }
}

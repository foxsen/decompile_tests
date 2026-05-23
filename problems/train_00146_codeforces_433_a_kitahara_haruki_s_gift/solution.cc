#include <bits/stdc++.h>
using namespace std;
const int max1 = 100010;
long long a[max1], b[max1];
int main() {
  int n, x, y = 0, z = 0;
  cin >> n;
  if (n == 1) {
    cout << "NO\n";
  } else {
    for (int i = 0; i < n; i++) {
      cin >> x;
      if (x == 200) {
        z++;
      }
      y += x;
    }
    if ((y % 200 == 0)) {
      if ((z == n) && (z % 2 != 0)) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
      }
    } else {
      cout << "NO\n";
    }
  }
}

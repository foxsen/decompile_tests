#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x, y, key, m, l;
    cin >> n >> x >> y;
    if (n == 2) {
      cout << x << ' ' << y;
    } else {
      m = (y - x) % (n - 1);
      key = (y - x) / (n - 1);
      if (m == 0) {
        for (int i = 0; i < n; i++) {
          cout << x + i * key << ' ';
        }
      } else {
        for (int i = n - 2; i > 0; i--) {
          if ((y - x) % i == 0) {
            key = (y - x) / i;
            for (int j = 1;; j++) {
              if (j > n - i - 1) {
                l = j;
                break;
              }
              if (x - key * j <= 0) {
                l = j;
                break;
              }
            }
            for (int j = 1; j <= n; j++) {
              cout << x - (l - j) * key << ' ';
            }
            break;
          }
        }
      }
    }
    cout << endl;
  }
}

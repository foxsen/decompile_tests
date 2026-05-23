#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      int c;
      cin >> c;
      a[i] = c % k;
    }
    sort(a + 1, a + 1 + n);
    long long x = 0, y = 0, cur = 0, tmp = 0;
    for (int i = n; i >= 1; i--) {
      if (a[i] != 0) {
        if (a[i] == cur)
          tmp++;
        else {
          if (tmp >= x) {
            x = tmp;
            y = cur;
          }
          cur = a[i];
          tmp = 1;
        }
      }
    }
    if (tmp >= x && cur != 0) {
      x = tmp;
      y = cur;
    }
    if (x == 0)
      cout << 0 << endl;
    else
      cout << (x - 1) * k + (k + 1 - y) << endl;
  }
  return 0;
}

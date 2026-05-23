#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, x = 0, k = 0;
  cin >> t;
  while (t--) {
    int m, n, x, y = 0;
    cin >> m;
    cin >> n;
    x = m * n;
    int a[x];
    for (int i = 0; i < x; i++) {
      cin >> a[i];
      if (a[i] < 0) {
        a[i] = 0 - a[i];
        k++;
      }
      y = y + a[i];
    }
    sort(a, a + x);
    if (k % 2 == 0)
      cout << y << endl;
    else
      cout << y - 2 * a[0] << endl;
    k = 0;
  }
  return 0;
}

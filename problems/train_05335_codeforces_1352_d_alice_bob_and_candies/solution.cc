#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n, a[1005] = {0}, t = 0, x = 0, y = 0, dx = 0, dy = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int i = 1, j = n, judge = 1;
    for (;;) {
      dx = 0;
      if (a[i] == 0) {
        judge = 0;
        break;
      } else {
        t++;
      }
      while (dx <= dy) {
        if (a[i] == 0) {
          judge = 0;
          break;
        }
        dx += a[i];
        a[i] = 0;
        i++;
      }
      x += dx;
      if (judge == 0) break;
      dy = 0;
      if (a[j] == 0) {
        judge = 0;
        break;
      } else {
        t++;
      }
      while (dy <= dx) {
        if (a[j] == 0) {
          judge = 0;
          break;
        }
        dy += a[j];
        a[j] = 0;
        j--;
      }
      y += dy;
      if (judge == 0) break;
    }
    cout << t << ' ' << x << ' ' << y << endl;
  }
}

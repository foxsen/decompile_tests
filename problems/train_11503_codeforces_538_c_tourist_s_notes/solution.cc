#include <bits/stdc++.h>
using namespace std;
const int MX = (1 << 17);
int n, m, ld, lh, d, h, mx;
int cel(int x, int y) {
  if (x % y == 0) return x / y;
  return x / y + 1;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &d, &h);
  mx = d - 1 + h;
  for (int i = 1; i < m; i++) {
    ld = d;
    lh = h;
    scanf("%d%d", &d, &h);
    mx = max(mx, h);
    mx = max(mx, lh);
    int x = d - ld;
    int y = abs(h - lh);
    if (y > x) {
      puts("IMPOSSIBLE");
      return 0;
    }
    mx = max(mx, max(lh, h) + (((abs(y - x)) / 2)));
  }
  mx = max(mx, n - d + h);
  cout << mx << endl;
}

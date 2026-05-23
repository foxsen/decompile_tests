#include <bits/stdc++.h>
using namespace std;
int main() {
  int testCase;
  cin >> testCase;
  for (int id = 0; id < testCase; id++) {
    int a, b, h, w;
    cin >> a >> b;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> w >> h;
    int ans;
    int dx = min(max(0, w - x1), max(0, x2 - (a - w)));
    int dy = min(max(0, h - y1), max(0, y2 - (b - h)));
    if (x2 - x1 + w > a) {
      if (y2 - y1 + h > b)
        ans = -1;
      else
        ans = dy;
    } else {
      if (y2 - y1 + h > b)
        ans = dx;
      else
        ans = min(dx, dy);
    }
    cout << ans << "\n";
  }
  return 0;
}

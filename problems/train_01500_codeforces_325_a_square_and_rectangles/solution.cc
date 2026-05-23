#include <bits/stdc++.h>
using namespace std;
struct coord {
  int x1, x2, y1, y2;
};
int main() {
  int n;
  cin >> n;
  coord rect[n];
  int mnX = 31401, mnY = 31401, mxX = 0, mxY = 0;
  long long area = 0;
  for (int i = 0; i < n; i++) {
    cin >> rect[i].x1 >> rect[i].y1 >> rect[i].x2 >> rect[i].y2;
    area += 1LL * abs(rect[i].x1 - rect[i].x2) * abs(rect[i].y1 - rect[i].y2);
    mnX = min(mnX, rect[i].x1);
    mnY = min(mnY, rect[i].y1);
    mxX = max(mxX, rect[i].x2);
    mxY = max(mxY, rect[i].y2);
  }
  int x = mxX - mnX, y = mxY - mnY;
  if (x == y && area == (1LL * x * y)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}

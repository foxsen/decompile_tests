#include <bits/stdc++.h>
using namespace std;
double eps = 1e-9;
int n;
int ox[10000], oy[10000], r[10000];
bool can(int x, int y) {
  for (int i = 0; i < n; i++)
    if ((x - ox[i]) * (x - ox[i]) + (y - oy[i]) * (y - oy[i]) <= r[i] * r[i])
      return true;
  return false;
}
int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2 >> n;
  for (int i = 0; i < n; i++) cin >> ox[i] >> oy[i] >> r[i];
  int sx, gx, sy, gy;
  sx = min(x1, x2);
  gx = max(x1, x2);
  sy = min(y1, y2);
  gy = max(y1, y2);
  int r = 0;
  for (int i = sx; i <= gx; i++) {
    if (!can(i, sy)) r++;
    if (!can(i, gy)) r++;
  }
  for (int i = sy + 1; i < gy; i++) {
    if (!can(sx, i)) r++;
    if (!can(gx, i)) r++;
  }
  cout << r << endl;
  return 0;
}

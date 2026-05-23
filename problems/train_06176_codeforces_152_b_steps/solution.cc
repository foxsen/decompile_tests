#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int x, y;
  scanf("%d %d", &x, &y);
  int k;
  scanf("%d", &k);
  long long counter = 0;
  for (int i = 1; i <= k; i++) {
    int dx, dy;
    scanf("%d %d", &dx, &dy);
    int delta;
    if (dx == 0 && dy == 0) {
      delta = 0;
    } else if (dx == 0 && dy > 0) {
      delta = (m - y) / dy;
    } else if (dx == 0 && dy < 0) {
      delta = (y - 1) / abs(dy);
    } else if (dy == 0 && dx > 0) {
      delta = (n - x) / dx;
    } else if (dy == 0 && dx < 0) {
      delta = (x - 1) / abs(dx);
    } else if (dx > 0 && dy > 0) {
      delta = min((n - x) / dx, (m - y) / dy);
    } else if (dx > 0 && dy < 0) {
      delta = min((n - x) / dx, (y - 1) / abs(dy));
    } else if (dx < 0 && dy > 0) {
      delta = min((x - 1) / abs(dx), (m - y) / dy);
    } else if (dx < 0 && dy < 0) {
      delta = min((x - 1) / abs(dx), (y - 1) / abs(dy));
    }
    counter += (long long)delta;
    x += delta * dx;
    y += delta * dy;
  }
  cout << counter << endl;
  return 0;
}

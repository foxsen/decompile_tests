#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, y, c = 0;
  cin >> x >> y;
  long long u = 1;
  x = x * 100;
  y = y * 10;
  if ((x == 0 && y < 220) || y <= 10 || (x + y < 220)) {
    cout << "Hanako";
    return 0;
  }
  while (1) {
    if ((x == 0 && y == 0) || (x == 0 && y <= 210)) {
      cout << "Hanako";
      return 0;
    }
    if (u == 1) {
      if (x >= 200 && y >= 20) {
        x = x - 200;
        y = y - 20;
        u = 2;
      } else if (x >= 100 && y >= 120) {
        x = x - 100;
        y = y - 120;
        u = 2;
      } else {
        y = y - 220;
        u = 2;
      }
    } else if (u == 2) {
      if (y >= 220) {
        y = y - 220;
        u = 1;
      } else if (x >= 100 && y >= 120) {
        x = x - 100;
        y = y - 120;
        u = 1;
      } else {
        x = x - 200;
        y = y - 20;
        u = 1;
      }
    }
    if ((x == 0 && y < 220) || y <= 10 || (x + y < 220)) {
      break;
    }
  }
  if (u == 2)
    cout << "Ciel";
  else
    cout << "Hanako";
}

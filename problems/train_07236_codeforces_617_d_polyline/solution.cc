#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
int main() {
  int x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  if ((x1 == x2 && x2 == x3) || (y1 == y2 && y2 == y3))
    cout << 1;
  else {
    bool ok1 = (x1 == x2 && (y3 >= max(y1, y2) || y3 <= min(y1, y2)));
    bool ok2 = (x1 == x3 && (y2 >= max(y1, y3) || y2 <= min(y1, y3)));
    bool ok3 = (x2 == x3 && (y1 >= max(y2, y3) || y1 <= min(y2, y3)));
    bool ok4 = (y1 == y2 && (x3 >= max(x1, x2) || x3 <= min(x1, x2)));
    bool ok5 = (y1 == y3 && (x2 >= max(x1, x3) || x2 <= min(x1, x3)));
    bool ok6 = (y2 == y3 && (x1 >= max(x2, x3) || x1 <= min(x2, x3)));
    if (ok1 || ok2 || ok3 || ok4 || ok5 || ok6)
      cout << 2;
    else
      cout << 3;
  }
  return 0;
}

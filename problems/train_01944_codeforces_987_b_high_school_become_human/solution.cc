#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  if (x == y) {
    cout << "=";
  } else if (x < y) {
    if (x >= 3 && y > 3)
      cout << ">";
    else if (x == 2 && y == 3)
      cout << "<";
    else if ((x == 2 && y == 4) || (x == 2 && y == 8))
      cout << "=";
    else if (x == 2 && y > 3) {
      cout << ">";
    } else
      cout << "<";
  } else {
    int c = y;
    y = x;
    x = c;
    if (x >= 3 && y > 3)
      cout << "<";
    else if (x == 2 && y == 3)
      cout << ">";
    else if ((x == 2 && y == 4) || (x == 2 && y == 8))
      cout << "=";
    else if (x == 2 && y > 3) {
      cout << "<";
    } else
      cout << ">";
  }
  return 0;
}

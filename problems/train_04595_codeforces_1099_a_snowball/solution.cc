#include <bits/stdc++.h>
using namespace std;
int main() {
  int w, h, u1, d1, u2, d2, i;
  cin >> w >> h >> u1 >> d1 >> u2 >> d2;
  for (i = h; i > 0; i--) {
    w += i;
    if (i == d1) {
      w = w - u1;
      if (w < 0) w = 0;
    } else if (i == d2) {
      w = w - u2;
      if (w < 0) w = 0;
    }
  }
  cout << w;
}

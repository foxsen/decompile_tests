#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  int q;
  cin >> q;
  int x, y, cx = 0, cy = 0;
  char c;
  for (int(i) = (0); (i) < (q); ++(i)) {
    cin >> c >> x >> y;
    if (x < y) swap(x, y);
    if (c == '+') {
      if (cx < x) cx = x;
      if (cy < y) cy = y;
    } else {
      cout << (cx <= x && cy <= y ? "YES" : "NO") << endl;
    }
  }
}

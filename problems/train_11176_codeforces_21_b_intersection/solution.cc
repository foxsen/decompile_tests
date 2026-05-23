#include <bits/stdc++.h>
using namespace std;
int main() {
  int a1, b1, c1, a2, b2, c2, ans = 1;
  cin >> a1 >> b1 >> c1;
  cin >> a2 >> b2 >> c2;
  if (a1 * b2 != a2 * b1)
    ans = 1;
  else if (a1 == 0 && b1 == 0 && c1 != 0 || a2 == 0 && b2 == 0 && c2 != 0)
    ans = 0;
  else if (b1 * c2 != b2 * c1 || a1 * c2 != a2 * c1)
    ans = 0;
  else if (a1 == 0 && b1 == 0 && c1 == 0 || a2 == 0 && b2 == 0 && c2 == 0)
    ans = -1;
  else if (c1 == 0 && c2 == 0 && a1 * b2 == a2 * b1)
    ans = -1;
  else if (a2 * b1 == a1 * b2 && a1 * c2 == a2 * c1 && b1 * c2 == b2 * c1)
    ans = -1;
  cout << ans << endl;
  return 0;
}

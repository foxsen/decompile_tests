#include <bits/stdc++.h>
using namespace std;
int main() {
  long long l, a, b, c, r;
  cin >> l >> r;
  if ((r - l < 2) || (r - l == 2 && l % 2 == 1))
    cout << -1;
  else {
    if (l % 2 == 0) {
      a = l;
      b = a + 1;
      c = b + 1;
    } else {
      a = l + 1;
      b = a + 1;
      c = b + 1;
    }
    cout << a << ' ' << b << ' ' << c;
  }
  return 0;
}

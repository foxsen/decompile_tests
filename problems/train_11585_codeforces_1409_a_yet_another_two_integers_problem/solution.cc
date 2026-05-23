#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a, b, n = 0;
  cin >> t;
  while (t--) {
    n = 0;
    cin >> a >> b;
    if (a == b)
      cout << 0 << '\n';
    else {
      if (a > b) swap(a, b);
      n = (b - a) / 10;
      if ((b - a) % 10) n++;
      cout << n << '\n';
    }
  }
  return 0;
}

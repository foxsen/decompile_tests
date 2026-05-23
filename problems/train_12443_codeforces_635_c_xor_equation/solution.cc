#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long s, x;
  cin >> s >> x;
  int delta = 2 * (s == x);
  unsigned long long s1x1 = ((s & 1) << 1) | (x & 1);
  unsigned long long c0 = (s1x1 == 0) + 2 * (s1x1 == 3);
  unsigned long long c1 = s1x1 == 0;
  for (int k = 0; k < 60; k++) {
    x >>= 1;
    s >>= 1;
    unsigned long long sx = ((s & 1) << 1) | (x & 1);
    unsigned long long d0, d1;
    if (sx == 0) {
      d0 = d1 = c0;
    } else if (sx == 1) {
      d0 = 0;
      d1 = 2 * c1;
    } else if (sx == 2) {
      d0 = d1 = c1;
    } else {
      d0 = 2 * c0;
      d1 = 0;
    }
    c0 = d0;
    c1 = d1;
  }
  cout << c0 - delta;
}

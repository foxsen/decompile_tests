#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, l, m, n, d, i, c;
  cin >> k >> l >> m >> n >> d;
  i = 0;
  c = 0;
  while (i < d) {
    if ((i + 1) % k != 0 and (i + 1) % l != 0 and (i + 1) % m != 0 and
        (i + 1) % n != 0) {
      ++c;
    }
    ++i;
  }
  cout << (d - c);
  return 0;
}

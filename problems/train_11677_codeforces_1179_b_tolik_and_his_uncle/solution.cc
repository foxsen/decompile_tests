#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int r1 = 1, r2 = n;
  while (r1 <= r2) {
    int c1 = 1, c2 = m;
    if (r1 == r2) {
      while (c1 <= c2) {
        cout << r1 << " " << c1 << "\n";
        if (c1 != c2) cout << r2 << " " << c2 << "\n";
        c1++, c2--;
      }
    } else {
      while (c1 <= m) {
        cout << r1 << " " << c1 << "\n";
        cout << r2 << " " << c2 << "\n";
        c1++, c2--;
      }
    }
    r1++, r2--;
  }
  return 0;
}

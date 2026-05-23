#include <bits/stdc++.h>
using namespace std;
int n, x, a, b, t;
int main() {
  cin >> t;
  while (t--) {
    cin >> a >> b;
    n = (a - b);
    if (n == 0) cout << "0\n";
    if (n > 0) {
      if (n % 2 == 0)
        cout << "1\n";
      else
        cout << "2\n";
    }
    if (n < 0) {
      if (n % 2 == 0)
        cout << "2\n";
      else
        cout << "1\n";
    }
  }
  return 0;
}

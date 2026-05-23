#include <bits/stdc++.h>
using namespace std;
const double PI = 3.1415926535897932384626433832795;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    if (a1 > b1) swap(a1, b1);
    if (a2 > b2) swap(a2, b2);
    if ((a1 == a2 && b1 + b2 == a1) || (b1 == b2 && a1 + a2 == b1))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a;
    int odd = -1, even = -1;
    cin >> a;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0 && a[i] % 2 != 0)
        odd = 1;
      else if (i % 2 != 0 && a[i] % 2 == 0)
        even = 1;
    }
    if (n % 2 == 0) {
      if (even != -1)
        cout << 2 << endl;
      else
        cout << 1 << endl;
    } else {
      if (odd != -1)
        cout << 1 << endl;
      else
        cout << 2 << endl;
    }
  }
}

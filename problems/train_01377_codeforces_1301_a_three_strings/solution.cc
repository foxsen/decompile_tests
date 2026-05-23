#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string a, b, c;
    cin >> a >> b >> c;
    int v = 0;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] != c[i] && b[i] != c[i]) {
        v = 1;
        break;
      }
    }
    if (v == 1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}

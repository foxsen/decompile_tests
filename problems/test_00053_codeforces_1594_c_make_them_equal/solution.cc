#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    int cn = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] != c) {
        cn++;
      }
    }
    if (cn == 0) {
      cout << "0\n";
      continue;
    }
    int p = -1;
    for (int x = n; x >= 2; --x) {
      if (n - (n / x) < cn) continue;
      bool f = true;
      for (int i = x - 1; i < n; i += x) {
        if (s[i] != c) {
          f = false;
          break;
        }
      }
      if (f) {
        p = x;
        break;
      }
    }
    if (p != -1) {
      cout << "1\n" << p << "\n";
    } else {
      cout << "2\n";
      cout << n - 1 << " " << n << "\n";
    }
  }
}

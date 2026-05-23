#include <bits/stdc++.h>
using namespace std;
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    long long r = 0;
    long long s = 0;
    long long p = 0;
    for (long long i = 0; i < str.length(); i++) {
      if (str[i] == 'R') r++;
      if (str[i] == 'S') s++;
      if (str[i] == 'P') p++;
    }
    if (r >= s && r >= p) {
      for (long long i = 0; i < str.length(); i++) {
        cout << "P";
      }
    } else if (s >= r && s >= p) {
      for (long long i = 0; i < str.length(); i++) {
        cout << "R";
      }
    } else {
      for (long long i = 0; i < str.length(); i++) {
        cout << "S";
      }
    }
    cout << "\n";
  }
  return 0;
}

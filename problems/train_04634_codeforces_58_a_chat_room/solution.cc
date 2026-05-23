#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t, i, j, k, n, g, x, y, z, ans, y1, z1;
  ans = 0;
  string s;
  cin >> s;
  bool h = false, e = false, l = false, dl = false, o = false;
  for (long long i = 0; i < s.length(); i++) {
    if (s[i] == 'h') {
      h = true;
    } else if (s[i] == 'e' && h == true) {
      e = true;
    } else if (s[i] == 'l' && l == true) {
      dl = true;
    } else if (s[i] == 'l' && e == true) {
      l = true;
    } else if (s[i] == 'o' && dl == true) {
      o = true;
    }
  }
  if (h && e && l && dl && o) {
    cout << "YES"
         << "\n";
  } else {
    cout << "NO"
         << "\n";
  }
  return 0;
}

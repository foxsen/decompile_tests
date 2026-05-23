#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  bool neg = s[0] == '-';
  if (neg) s = s.substr(1);
  int p;
  string d;
  if ((p = s.find('.')) != -1) {
    d = s.substr(p + 1);
    s = s.substr(0, p);
  }
  if (((int)(d).size()) < 2) d += "000";
  if (neg) cout << '(';
  cout << '$';
  int k = ((int)(s).size()) % 3;
  if (k == 0) k = 3;
  for (int i = 0; i < ((int)(s).size()); i++) {
    if (k == 0) cout << ',', k = 3;
    cout << s[i];
    k--;
  }
  cout << '.';
  cout << d.substr(0, 2);
  if (neg) cout << ')';
  return 0;
}

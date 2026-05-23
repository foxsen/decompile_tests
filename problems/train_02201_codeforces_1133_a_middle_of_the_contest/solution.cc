#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, i, e, f, g, n, m, k, l;
string s, s1;
int main() {
  cin >> s >> s1;
  a += ((int(s[0]) - 48) * 10 + int(s[1]) - 48) * 60 + (int(s[3]) - 48) * 10 +
       int(s[4]) - 48;
  b += ((int(s1[0]) - 48) * 10 + int(s1[1]) - 48) * 60 +
       (int(s1[3]) - 48) * 10 + int(s1[4]) - 48;
  c = (a + b) / 2;
  k = c / 60;
  l = c % 60;
  if (k / 10 == 0)
    cout << "0" << k << ":";
  else
    cout << k << ":";
  if (l / 10 == 0)
    cout << "0" << l;
  else
    cout << l;
}

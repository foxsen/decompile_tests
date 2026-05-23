#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int i, l, z = 0;
  cin >> s;
  l = s.size();
  for (i = 0; i < l; i++)
    if (s[i] == 'A')
      z += 1;
    else if (s[i] == '1')
      z += 10;
    else
      z += s[i] - '0';
  cout << z;
  return 0;
}

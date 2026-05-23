#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int i = 0;
  for (i = 0; i < s.length(); i++) {
    if (s[i] == '0') break;
  }
  if (i < s.length() - 1)
    s = s.substr(0, i) + s.substr(i + 1);
  else
    s = s.substr(0, s.length() - 1);
  cout << s << endl;
  return 0;
}

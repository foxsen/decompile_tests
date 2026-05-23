#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  getline(cin, s);
  for (int i = 0; i < s.size(); i++) {
    if (i == 0 && s[i] == '9') continue;
    if (s[i] - '0' > 4) s[i] = '0' + (9 - (s[i] - '0'));
  }
  printf("%s\n", s.c_str());
  return 0;
}

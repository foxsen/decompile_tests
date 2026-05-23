#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int i = 0;
  while (i <= s.size() - 1) {
    if (s[i] == '1') {
      i++;
      if (s[i] == '4') {
        i++;
        if (s[i] == '4') i++;
      }
    } else
      break;
  }
  if (i == s.size())
    cout << "YES";
  else
    cout << "NO";
}

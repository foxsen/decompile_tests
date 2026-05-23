#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int c = 0, i;
  for (i = 4; i < s.size(); i++) {
    if (s[i - 4] == 'D' && s[i - 3] == 'a' && s[i - 2] == 'n' &&
        s[i - 1] == 'i' && s[i] == 'l')
      c++;
  }
  for (i = 3; i < s.size(); i++) {
    if (s[i - 3] == 'O' && s[i - 2] == 'l' && s[i - 1] == 'y' && s[i] == 'a')
      c++;
  }
  for (i = 4; i < s.size(); i++) {
    if (s[i - 4] == 'S' && s[i - 3] == 'l' && s[i - 2] == 'a' &&
        s[i - 1] == 'v' && s[i] == 'a')
      c++;
  }
  for (i = 2; i < s.size(); i++) {
    if (s[i - 2] == 'A' && s[i - 1] == 'n' && s[i] == 'n') c++;
  }
  for (i = 5; i < s.size(); i++) {
    if (s[i - 5] == 'N' && s[i - 4] == 'i' && s[i - 3] == 'k' &&
        s[i - 2] == 'i' && s[i - 1] == 't' && s[i] == 'a')
      c++;
  }
  if (c == 1)
    cout << "YES";
  else
    cout << "NO";
}

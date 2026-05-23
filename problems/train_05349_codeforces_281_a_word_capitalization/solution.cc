#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int i, n, k = 0;
  cin >> s;
  for (i = 0; i < s.length(); i++)
    if (s[0] == tolower(s[0]))
      s[0] = toupper(s[0]);
    else if (s[0] == tolower(s[0]))
      s[0] = tolower(s[0]);
  cout << s[0];
  for (i = 1; i < s.length(); i++) cout << s[i];
  return 0;
}

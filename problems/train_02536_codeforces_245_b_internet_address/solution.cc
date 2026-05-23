#include <bits/stdc++.h>
using namespace std;
string s;
int i, t;
int main() {
  cin >> s;
  if (s[0] == 'f' && s[1] == 't' && s[2] == 'p')
    cout << "ftp://", t = 3;
  else
    cout << "http://", t = 4;
  for (i = t + 1; i < s.length() - 1; i++)
    if (s[i] == 'r' && s[i + 1] == 'u') break;
  for (int j = t; j < i; j++) cout << s[j];
  cout << ".ru";
  if (i + 2 < s.length()) {
    cout << "/";
    for (int j = i + 2; j < s.length(); j++) cout << s[j];
  }
}

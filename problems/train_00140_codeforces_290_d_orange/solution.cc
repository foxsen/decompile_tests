#include <bits/stdc++.h>
using namespace std;
template <typename T>
int size(T& a) {
  return (int)a.size();
}
template <typename T>
T sqr(T a) {
  return a * a;
}
bool isLowercase(char ch) { return ch >= 'a' && ch <= 'z'; }
bool isUppercase(char ch) { return !isLowercase(ch); }
char toLowercase(char ch) {
  if (isUppercase(ch)) {
    ch = ch - 'A' + 'a';
  }
  return ch;
}
char toUppercase(char ch) {
  if (isLowercase(ch)) {
    ch = ch - 'a' + 'A';
  }
  return ch;
}
int main() {
  string s;
  int n;
  cin >> s >> n;
  for (int i = (0); i < (size(s)); ++i) {
    s[i] = toLowercase(s[i]);
  }
  for (int i = (0); i < (size(s)); ++i) {
    if (int(s[i]) < n + 97) {
      s[i] = toUppercase(s[i]);
    }
  }
  cout << s << endl;
}

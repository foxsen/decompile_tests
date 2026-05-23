#include <bits/stdc++.h>
using namespace std;
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
bool vowel(char c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (vowel(s[i]))
      cout << s[i];
    else if (i < 2)
      cout << s[i];
    else if (vowel(s[i - 1]) || vowel(s[i - 2]))
      cout << s[i];
    else if (s[i] == s[i - 1] && s[i - 2] == s[i - 1])
      cout << s[i];
    else {
      cout << " " << s[i];
      s[i - 1] = 'a';
    }
  }
  return 0;
}

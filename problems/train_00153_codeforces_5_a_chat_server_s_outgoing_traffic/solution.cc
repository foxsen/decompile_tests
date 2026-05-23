#include <bits/stdc++.h>
using namespace std;
int main() {
  int m = 0, a = 0;
  for (int i = 0; i < 100; i++) {
    string s;
    getline(cin, s);
    if (s[0] == '+') {
      m++;
      continue;
    }
    if (s[0] == '-') {
      m--;
      continue;
    }
    int c = 1;
    int t = 0;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == ':' && c == 1) {
        c = 0;
        continue;
      }
      if (c == 0) {
        a += (s.size() - j) * m;
        break;
      }
    }
  }
  cout << a;
  return 0;
}

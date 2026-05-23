#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int a, c = 0, x;
  cin >> s;
  a = s.size();
  x = 0;
  for (int i = 0; i < a; i++) {
    if (s[i] == s[i + 1]) {
      x++;
    } else {
      if (x % 2 == 1) {
        c++;
      }
      x = 0;
    }
  }
  cout << c;
  return 0;
}

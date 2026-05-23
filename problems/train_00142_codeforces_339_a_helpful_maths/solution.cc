#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, x, z;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '+') {
      continue;
    }
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == '+') {
        continue;
      }
      if (s[i] < s[j]) {
        swap(s[j], s[i]);
      }
    }
  }
  for (int i = 0; i < s.size(); i++) {
    cout << s[i];
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  string t;
  cin >> t;
  string s = "";
  int i, j;
  if (t.length() % 2 == 0) {
    j = t.length() - 1;
    i = 0;
    while (i < j) {
      s += t[j];
      s += t[i];
      i++;
      j--;
    }
    reverse(s.begin(), s.end());
  } else {
    j = t.length() - 1;
    i = 0;
    while (i < j) {
      s += t[i];
      s += t[j];
      i++;
      j--;
    }
    s += t[t.length() / 2];
    reverse(s.begin(), s.end());
  }
  cout << s;
  return 0;
}

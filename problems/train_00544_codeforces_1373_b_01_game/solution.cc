#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, zer, jed, x;
  cin >> t;
  string s;
  for (int i = 0; i < t; i++) {
    cin >> s;
    zer = 0;
    jed = 0;
    for (int j = 0; j < s.size(); j++) {
      switch (s[j]) {
        case '0':
          zer++;
          break;
        case '1':
          jed++;
          break;
      }
    }
    if (zer <= jed) {
      x = zer;
    } else {
      x = jed;
    }
    if (x % 2 == 1) {
      cout << "DA" << endl;
    } else {
      cout << "NET" << endl;
    }
  }
}

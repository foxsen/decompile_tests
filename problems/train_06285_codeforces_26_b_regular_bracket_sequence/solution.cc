#include <bits/stdc++.h>
using namespace std;
int main(void) {
  char s[1000005];
  cin >> s;
  int l = strlen(s), a = 0, b = 0, prob = 0;
  for (int i = 0; i < l; i++) {
    if (s[i] == '(') {
      ++a;
    } else {
      ++b;
      while (a > 0 && b > 0) {
        --a;
        --b;
      }
      if (b != 0) {
        prob += b;
        b = 0;
      }
    }
  }
  cout << l - prob - a << endl;
  return 0;
}

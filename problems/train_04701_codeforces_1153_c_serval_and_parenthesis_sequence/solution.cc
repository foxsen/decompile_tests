#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a = 1, b;
  string s, t;
  cin >> n >> s;
  if (s[0] == '?') s[0] = '(';
  if (s[n - 1] == '?') s[n - 1] = ')';
  if (n % 2 != 0 || s[0] != '(' || s[n - 1] != ')') {
    cout << ":(";
    return 0;
  }
  for (int i = 1; i < n; i++) {
    if (s[i] == '(') a++;
  }
  b = n / 2 - a;
  a = 1;
  for (int i = 1; i < n; i++) {
    if (s[i] == '(')
      a++;
    else if (s[i] == ')')
      a--;
    else {
      if (b-- > 0) {
        s[i] = '(';
        a++;
      } else {
        s[i] = ')';
        a--;
      }
    }
    if (a <= 0 && i != n - 1) {
      a = 1;
      break;
    }
  }
  if (a == 0)
    cout << s;
  else
    cout << ":(";
  return 0;
}

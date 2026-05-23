#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  long int n, i, j, k = 0, p = 0, c = 0, f = 0, flag = 0;
  n = s.length();
  for (i = 0; i < n; i++) {
    if (s[i] == '[') {
      for (j = i; j < n; j++) {
        if (s[j] == ':') {
          k = j;
          f = 1;
          break;
        }
      }
      break;
    }
  }
  c = k - 1;
  for (i = n - 1; i > k; i--) {
    if (s[i] == ']') {
      for (j = i; j > k; j--) {
        if (s[j] == ':') {
          p = j;
          flag = 1;
          break;
        }
      }
      break;
    }
  }
  c += n - (p)-2;
  if (flag && f) {
    for (i = k + 1; i < p; i++) {
      if (s[i] == '|')
        ;
      else
        c++;
    }
    cout << n - c;
  } else
    cout << -1;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, i, j, c = 0, d = 0;
  cin >> n;
  char s[n];
  cin >> s;
  for (i = 0; i <= n; i++) {
    if (s[i] == '1') {
      c++;
    } else if (s[i] == '0') {
      d++;
    }
  }
  if (c > 0) {
    cout << "1";
    for (i = 0; i < d; i++) {
      cout << "0";
    }
  } else if (c == 0) {
    cout << "0";
  }
  return 0;
}

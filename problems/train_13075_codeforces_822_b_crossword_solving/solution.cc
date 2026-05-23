#include <bits/stdc++.h>
using namespace std;
int n, m, maxl, step, tmp;
string s, t;
int main() {
  cin >> n >> m;
  cin >> s >> t;
  for (int i = 0; i <= m - n; i++) {
    tmp = 0;
    for (int j = 0; j < n; j++) {
      if (s[j] == t[i + j]) {
        tmp++;
      }
    }
    if (tmp > maxl) {
      maxl = tmp;
      step = i;
    }
  }
  cout << n - maxl << endl;
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i + step]) {
      cout << i + 1 << ' ';
    }
  }
  return 0;
}

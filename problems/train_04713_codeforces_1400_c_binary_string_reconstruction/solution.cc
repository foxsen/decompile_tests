#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int n = s.size();
    int x;
    cin >> x;
    vector<char> ans(n, '1');
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        if (i + x < n) ans[i + x] = '0';
        if (i - x >= 0) ans[i - x] = '0';
      }
    }
    int flag = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        if (i + x < n && i - x >= 0) {
          if (ans[i + x] == '0' && ans[i - x] == '0') {
            flag = 1;
            break;
          }
        } else if (i + x < n) {
          if (ans[i + x] == '0') {
            flag = 1;
            break;
          }
        } else if (i - x >= 0) {
          if (ans[i - x] == '0') {
            flag = 1;
            break;
          }
        } else {
          flag = 1;
          break;
        }
      }
    }
    if (flag)
      cout << "-1\n";
    else {
      for (int i = 0; i < n; i++) cout << ans[i];
      cout << "\n";
    }
  }
  return 0;
}

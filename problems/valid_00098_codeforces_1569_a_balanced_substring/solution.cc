#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool has = false;
    auto is_balance = [&](string s) {
      int cnt0 = 0;
      int cnt1 = 0;
      for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == 'a') {
          cnt0 += 1;
        } else {
          cnt1 += 1;
        }
      }
      return cnt0 == cnt1;
    };
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (is_balance(s.substr(i, j - i + 1))) {
          cout << i + 1 << " " << j + 1 << '\n';
          has = true;
          break;
        }
      }
      if (has) {
        break;
      }
    }
    if (!has) {
      cout << "-1 -1" << '\n';
    }
  }
  return 0;
}

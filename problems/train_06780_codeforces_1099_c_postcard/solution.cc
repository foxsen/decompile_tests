#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 5;
const int mod = 1e9 + 7;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  string s;
  int n, ans1 = 0, ans2 = 0, ans = 0;
  cin >> s >> n;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '*') {
      ans1++;
    } else if (s[i] == '?') {
      ans2++;
    } else {
      ans++;
    }
  }
  if (ans - ans1 - ans2 > n || (ans1 == 0 && ans < n)) {
    cout << "Impossible" << endl;
  } else {
    if (ans >= n) {
      int cnt = ans - n;
      for (int i = 0; i < s.size(); i++) {
        if ((s[i + 1] == '?' || s[i + 1] == '*') && cnt) {
          cnt--;
        } else if (s[i] == '?' || s[i] == '*')
          continue;
        else
          cout << s[i];
      }
    } else {
      int cnt = n - ans;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == '*' && cnt) {
          for (int j = 1; j <= cnt; j++) {
            cout << s[i - 1];
          }
          cnt = 0;
        } else if (s[i] != '*' && s[i] != '?')
          cout << s[i];
      }
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e5 + 5, mod = 31, bit = 60;
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long int pro = 1, temp, t, i, j, l, r, n, m, x, y, z, mid, k, rem,
                carry = 0, ind, ans = 0, mx = -LONG_LONG_MAX,
                mn = LONG_LONG_MAX, cnt = 0, curr = 0, prev, next, sum = 0,
                i1 = -1, i2 = -1;
  bool flag;
  cin >> t;
  while (t--) {
    cin >> n;
    string s[n];
    long long int f[4] = {0};
    for (i = 0; i < n; i++) {
      cin >> s[i];
      l = s[i].length();
      x = (s[i][0] - '0') * 2 + (s[i][l - 1] - '0');
      f[x]++;
    }
    if (f[0] > 0 and f[3] > 0 and max(f[1], f[2]) == 0) {
      cout << -1 << '\n';
      continue;
    }
    ans = abs(f[1] - f[2]) >> 1;
    set<string> ms;
    if (f[1] >= f[2]) {
      for (i = 0; i < n; i++) {
        if (s[i][0] == '0' and s[i][s[i].length() - 1] == '1') {
          ms.insert(s[i]);
        }
      }
      for (i = 0; i < n; i++) {
        if (s[i][0] == '1' and s[i][s[i].length() - 1] == '0') {
          reverse(s[i].begin(), s[i].end());
          if (ms.find(s[i]) != ms.end()) {
            ms.erase(s[i]);
          }
          reverse(s[i].begin(), s[i].end());
        }
      }
      cout << ans << '\n';
      for (i = 0; i < n and ans > 0; i++) {
        if (s[i][0] == '0' and s[i][s[i].length() - 1] == '1') {
          if (ms.find(s[i]) != ms.end()) {
            ans--;
            cout << i + 1 << ' ';
          }
        }
      }
    } else {
      for (i = 0; i < n; i++) {
        if (s[i][0] == '1' and s[i][s[i].length() - 1] == '0') {
          ms.insert(s[i]);
        }
      }
      for (i = 0; i < n; i++) {
        if (s[i][0] == '0' and s[i][s[i].length() - 1] == '1') {
          reverse(s[i].begin(), s[i].end());
          if (ms.find(s[i]) != ms.end()) {
            ms.erase(s[i]);
          }
          reverse(s[i].begin(), s[i].end());
        }
      }
      cout << ans << '\n';
      for (i = 0; i < n and ans > 0; i++) {
        if (s[i][0] == '1' and s[i][s[i].length() - 1] == '0') {
          if (ms.find(s[i]) != ms.end()) {
            ans--;
            cout << i + 1 << ' ';
          }
        }
      }
    }
    cout << '\n';
  }
  return 0;
}

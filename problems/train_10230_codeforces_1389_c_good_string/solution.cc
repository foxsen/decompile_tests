#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long n = s.size();
    long long ans = n;
    for (char c1 = '0'; c1 <= '9'; c1++) {
      long long cnt = 0;
      for (auto c : s) cnt += (c == c1 ? 1 : 0);
      if (cnt % 2 == 0) {
        cnt--;
      }
      ans = min(ans, n - cnt);
      for (char c2 = '0'; c2 <= '9'; c2++) {
        cnt = 0;
        bool flip = false;
        for (auto c : s) {
          if (!flip) {
            if (c == c1) {
              flip = true;
              cnt++;
            }
          } else {
            if (c == c2) {
              flip = false;
              cnt++;
            }
          }
        }
        if (cnt % 2 == 1) {
          cnt--;
        }
        ans = min(ans, n - cnt);
      }
    }
    cout << ans << '\n';
  }
}

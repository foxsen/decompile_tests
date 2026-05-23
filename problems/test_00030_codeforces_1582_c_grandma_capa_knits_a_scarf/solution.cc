#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int n;
string s1, s2;
void solve() {
  int ans = -1;
  for (char c = 'a'; c <= 'z'; ++c) {
    int sum = 0;
    int l = 0, r = 0;
    while (l < n && r < n) {
      while (l < n && r < n && s1[l] != s2[r]) {
        if (s1[l] == c)
          l++;
        else if (s2[r] == c)
          r++;
        else {
          goto it;
        }
      }
      while (l < n && r < n && s1[l] == s2[r]) {
        l++;
        r++;
        sum++;
      }
    }
    ans = max(ans, sum);
  it:;
  }
  printf("%d\n", ans == -1 ? -1 : n - ans);
}
signed main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    cin >> s1;
    s2 = s1;
    reverse(s2.begin(), s2.end());
    solve();
  }
  return 0;
}

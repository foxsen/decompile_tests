#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    long long n, c0, c1, h;
    cin >> n >> c0 >> c1 >> h;
    string s;
    cin >> s;
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      long long base = c0;
      if (s[i] == '1') base = c1;
      ans += min(base, c0 + c1 - base + h);
    }
    cout << ans << '\n';
  }
}

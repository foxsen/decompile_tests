#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
pair<long long int, long long int> s4[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
pair<long long int, long long int> s8[8] = {
    {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
void judge() {}
void solve() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    long long int ans = a;
    int n = s.size();
    int x = -1, y = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        x = i;
        break;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == '1') {
        y = i;
        break;
      }
    }
    if (x == y && x == -1) {
      cout << 0 << '\n';
      continue;
    }
    for (int i = x; i <= y; i++) {
      int zero = 0;
      while (s[i] == '0') {
        zero++;
        i++;
      }
      ans += min(a, b * zero);
    }
    cout << ans << '\n';
  }
}
signed main() {
  judge();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  solve();
}

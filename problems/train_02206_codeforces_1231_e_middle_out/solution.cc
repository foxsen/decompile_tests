#include <bits/stdc++.h>
using namespace std;
bool check(string a, string b) {
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  return a == b;
}
int main() {
  long long int t, i, j, k, l, n, m, a, b, c, x, y;
  cin >> t;
  while (t--) {
    cin >> n;
    string s, p;
    cin >> s >> p;
    if (!check(s, p)) {
      cout << -1 << "\n";
      continue;
    }
    long long int ans = s.size();
    n = s.size();
    for (i = 0; i < n; ++i) {
      j = 0;
      l = i;
      while (j < n) {
        if (s[j] == p[l]) {
          j++;
          l++;
        } else {
          j++;
        }
      }
      ans = min(ans, i + n - l);
    }
    cout << ans << "\n";
  }
  return 0;
}

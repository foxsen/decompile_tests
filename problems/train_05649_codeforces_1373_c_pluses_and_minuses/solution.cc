#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using ll = long long;
void solve() {
  string s;
  cin >> s;
  int m = ((int)(s).size());
  vi a(m);
  a[0] = ((s[0] == '-') ? -1 : 1);
  for (__typeof(m) i = (1) - ((1) > (m)); i != (m) - ((1) > (m));
       i += 1 - 2 * ((1) > (m))) {
    if (s[i] == '-') {
      a[i] = a[i - 1] - 1;
    } else {
      a[i] = a[i - 1] + 1;
    }
  }
  ll res = m;
  int i = 0, t = -1;
  while (i < m) {
    if (a[i] != t) {
      i++;
    } else {
      t--;
      res += (i + 1);
    }
  }
  cout << res << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

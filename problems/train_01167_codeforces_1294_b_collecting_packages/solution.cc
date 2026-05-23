#include <bits/stdc++.h>
using namespace std;
int x, y, z, t, m, n, i, j, k, mn, mx, q, ind, inx;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    pair<int, int> a[n + 5];
    for (i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    sort(a, a + n);
    bool f[1005];
    memset(f, 0, sizeof f);
    string s = "";
    ind = 0;
    inx = 0;
    mx = 0;
    bool fl = 1;
    for (i = 0; i < n; i++) {
      x = a[i].first;
      y = a[i].second;
      if (y < mx) {
        fl = 0;
        break;
      }
      if (i > 0 && a[i].first != a[i - 1].first) {
        for (j = ind; j < mx; j++) s += "U";
        ind = mx;
      }
      if (f[x] == 0) {
        for (j = inx; j < x; j++) s += "R";
        inx = x;
      }
      f[x] = 1;
      mx = max(mx, y);
    }
    for (j = ind; j < mx; j++) s += "U";
    if (fl == 0)
      cout << "NO\n";
    else {
      cout << "YES\n";
      cout << s << "\n";
    }
  }
}

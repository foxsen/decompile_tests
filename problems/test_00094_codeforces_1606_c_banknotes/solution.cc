#include <bits/stdc++.h>
using namespace std;
long long t, i, n, k, l, r, s, a[90], d, p, h, e;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    k++;
    s = 0;
    for (i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (i = 1; i < n; i++) {
      r = 1;
      e = a[i];
      while (e--) {
        r = r * 10;
      }
      d = 1;
      p = a[i + 1] - a[i];
      while (p--) {
        d = d * 10;
      }
      d--;
      s = s + (r * min(k, d));
      k = k - min(k, d);
    }
    if (k <= 9) {
      e = a[n];
      r = 1;
      while (e--) {
        r = r * 10;
      }
      s += r * k;
    } else {
      e = a[n];
      r = 1;
      while (e--) {
        r = r * 10;
      }
      s += r * k;
    }
    cout << s << '\n';
  }
}

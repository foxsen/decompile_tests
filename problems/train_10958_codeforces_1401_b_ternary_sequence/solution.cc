#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a[3] = {0, 0, 0};
  int b[3] = {0, 0, 0};
  cin >> a[0] >> a[1] >> a[2];
  cin >> b[0] >> b[1] >> b[2];
  int ans = 0;
  int t = min(b[2], a[0]);
  a[0] -= t;
  b[2] -= t;
  t = min(a[2], b[1]);
  ans += t * 2;
  a[2] -= t;
  b[1] -= t;
  t = min(a[0], b[1]);
  a[0] -= t;
  b[1] -= t;
  t = min(a[2], b[2]);
  a[2] -= t;
  b[2] -= t;
  if (b[2] > 0) {
    ans -= b[2] * 2;
    b[2] = 0;
    a[1] -= b[2];
  }
  t = min(a[1], b[1]);
  a[1] -= t;
  b[1] -= t;
  cout << ans << "\n";
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}

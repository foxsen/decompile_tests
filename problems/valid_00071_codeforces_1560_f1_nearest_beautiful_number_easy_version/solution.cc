#include <bits/stdc++.h>
using namespace std;
int d(int x) {
  int z = 0, c = x;
  while (c) {
    z |= (1 << (c % 10));
    c /= 10;
  }
  return __builtin_popcount(z);
}
void solve() {
  int n, k;
  cin >> n >> k;
  while (d(n) > k) {
    int r = 1, c = n;
    while (d(c) > k) {
      c /= 10;
      r *= 10;
    }
    r /= 10;
    n = ((n / r) + 1) * r;
  }
  cout << n << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

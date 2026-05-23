#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, x, p, q, y, m, k, ans = 0;
  cin >> n;
  vector<long long> a;
  for (long long i = 0; i < n; i++) cin >> x, a.push_back(x);
  for (long long i = 0; i < n - 1; i++) {
    if (a[i] != 0) ans += a[i];
    long long j = 1;
    while (i + j < n) j = (j << 1);
    j = (j >> 1);
    a[i + j] += a[i];
    cout << ans << endl;
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1, n, x, y, k, e;
  while (t--) solve();
  return 0;
}

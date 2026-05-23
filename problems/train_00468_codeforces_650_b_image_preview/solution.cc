#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k, b, t;
  cin >> n >> k >> b >> t;
  string s;
  cin >> s;
  long long sum = 0;
  long long a[2 * n + (long long)10];
  for (long long i = 0; i < n; i++) {
    a[i] = a[i + n] = ((s[i] == 'w') ? (b + 1) : 1);
    sum += a[i];
  }
  sum -= a[0];
  long long l = 1, r = n;
  long long ans = 0;
  while ((l <= n) && (r < 2 * n)) {
    sum += a[r];
    r++;
    while ((r - l) > n || (sum + (r - l - 1 + min(r - n - 1, n - l)) * k) > t)
      sum -= a[l++];
    ans = max(ans, r - l);
  }
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  t = 1;
  while (t--) {
    solve();
  }
}

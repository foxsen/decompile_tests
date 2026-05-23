#include <bits/stdc++.h>
using namespace std;
const int c = 100005;
void solve() {
  long long n;
  cin >> n;
  string u, v;
  cin >> u >> v;
  vector<long long> a(n);
  for (long long i = 0; i < n; ++i) {
    long long x = (u[i] - '0') + (v[i] - '0');
    a[i] = x;
  }
  long long ans = 0;
  for (long long i = 0; i < n;) {
    if (a[i] == 1) {
      ans += 2;
      i++;
    } else if (i + 1 < n and a[i] + a[i + 1] == 2) {
      ans += 2;
      i += 2;
    } else if (a[i] == 0) {
      ans += 1;
      i++;
    } else
      i++;
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

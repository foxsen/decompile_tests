#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long inf = 1e18;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m, k;
  cin >> n >> m >> k;
  vector<long long> lst(n);
  for (long long& x : lst) cin >> x;
  vector<long long> a;
  for (long long i = 0; i < n - 1; i++) {
    a.push_back(lst[i + 1] - lst[i] - 1);
  }
  sort(a.begin(), a.end());
  long long ans = n;
  for (long long i = 0; i < n - k; i++) ans += a[i];
  cout << ans;
  return 0;
}

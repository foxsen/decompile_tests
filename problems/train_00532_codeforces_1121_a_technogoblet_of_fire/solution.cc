#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5, M = 3e3 + 5;
const long long inf = 1e18 + 100, mod = 1e9 + 7;
const double eps = 1e-9;
long long pos[N];
pair<long long, long long> a[N];
map<long long, long long> b;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m, k;
  cin >> n >> m >> k;
  for (long long i = 1; i <= n; ++i) cin >> a[i].first;
  for (long long i = 1; i <= n; ++i) cin >> a[i].second;
  for (long long i = 1; i <= n; ++i)
    if (a[i].first > b[a[i].second]) b[a[i].second] = a[i].first;
  long long cnt = 0;
  while (k--) {
    long long i;
    cin >> i;
    if (b[a[i].second] != a[i].first) cnt++;
  }
  cout << cnt;
  return 0;
}

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const long long maxn = 300005;
long long a[maxn];
long long cont[1000006];
vector<pair<pair<long long, long long>, long long> > que;
long long anser[2 * maxn];
long long ans = 0;
inline void add(long long x) {
  if (cont[a[x]] == 0) ans++;
  cont[a[x]]++;
}
inline void sub(long long x) {
  if (cont[a[x]] == 1) ans--;
  cont[a[x]]--;
}
int main() {
  ;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(10);
  cin.exceptions(cin.failbit);
  int t = 1;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long low = 200000000000000ll;
    long long ans = -200000000000000ll;
    for (long long i = 0, _n = (n); i < _n; i++) {
      low = 200000000000000ll;
      for (long long j = 0, _n = (m); j < _n; j++) {
        long long x;
        cin >> x;
        low = min(x, low);
      }
      ans = max(ans, low);
    }
    cout << ans;
  };
}

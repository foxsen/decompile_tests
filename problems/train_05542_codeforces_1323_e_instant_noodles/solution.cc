#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n, m;
    cin >> n >> m;
    vector<set<long long>> g(n);
    vector<long long> c(n);
    for (long long i = 0; i < n; ++i) cin >> c[i];
    for (long long i = 0; i < m; ++i) {
      long long u, v;
      cin >> u >> v;
      --u, --v;
      g[v].insert(u);
    }
    map<set<long long>, long long> m1;
    vector<long long> sums;
    for (long long i = 0; i < n; ++i) {
      if (g[i].size()) {
        m1[g[i]] += c[i];
      }
    }
    long long ans = 0;
    for (auto elem : m1) {
      ans = gcd(ans, elem.second);
    }
    cout << ans << endl;
  }
}

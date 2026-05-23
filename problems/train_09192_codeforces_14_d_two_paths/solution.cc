#include <bits/stdc++.h>
using namespace std;
const long long N = 201;
long long n, u, v;
vector<long long> g[N];
vector<pair<long long, long long> > ed;
long long height(long long x, long long p) {
  long long h = 0;
  for (long long y : g[x]) {
    if (y == p) continue;
    h = max(h, 1 + height(y, x));
  }
  return h;
}
long long dia(long long x, long long p) {
  long long h1 = -1;
  long long h2 = -1;
  long long dmax = 0;
  for (long long y : g[x]) {
    if (y == p) continue;
    long long h = height(y, x);
    long long d = dia(y, x);
    dmax = max(dmax, d);
    if (h > h1) {
      h2 = h1;
      h1 = h;
    } else if (h > h2) {
      h2 = h;
    }
  }
  return max(dmax, h1 + h2 + 2);
}
long long solve() {
  cin >> n;
  ed.push_back({0, 0});
  for (__typeof((n - 1)) i = (1); i <= (n - 1); i++) {
    cin >> u >> v;
    ed.push_back({u, v});
  }
  long long ans = 0;
  for (__typeof((n - 1)) i = (1); i <= (n - 1); i++) {
    for (__typeof((n)) j = (1); j <= (n); j++) g[j].clear();
    long long r1, r2;
    for (__typeof((n - 1)) j = (1); j <= (n - 1); j++) {
      if (j == i) {
        r1 = ed[j].first;
        r2 = ed[j].second;
        continue;
      }
      u = ed[j].first;
      v = ed[j].second;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    ans = max(ans, dia(r1, r1) * dia(r2, r2));
  }
  cout << ans << '\n';
  return 0;
}
signed main() {
  long long t;
  ios_base::sync_with_stdio(false);
  t = 1;
  while (t--) solve();
  return 0;
}

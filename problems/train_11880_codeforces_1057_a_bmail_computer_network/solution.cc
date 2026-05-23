#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("Ofast")
using namespace std;
const long double pi = acos(-1);
const long long int M = 1e9 + 7, N = 1e7 + 5, INF = 1e18;
long long int n, t;
vector<long long int> p, r;
void solve() {
  cin >> n;
  p.resize(n + 1, 0);
  for (long long int i = 2; i <= n; i++) {
    cin >> p[i];
  }
  r.push_back(n);
  while (r.back() != 1) {
    r.push_back(p[r.back()]);
  }
  reverse(r.begin(), r.end());
  for (auto it : r) cout << it << " ";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}

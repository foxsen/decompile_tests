#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v);
template <typename A, typename B>
ostream &operator<<(ostream &cout, pair<A, B> const &p) {
  return cout << "(" << p.first << ", " << p.second << ")";
}
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    if (i) cout << ", ";
    cout << v[i];
  }
  return cout << "]";
}
template <typename A, typename B>
istream &operator>>(istream &cin, pair<A, B> &p) {
  cin >> p.first;
  return cin >> p.second;
}
const long long MAXN = 1e5 + 7;
void check() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long a[MAXN], mn = 1e10;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    if (i & 1) mn = min(a[i], mn);
  }
  if (!(n & 1)) {
    cout << 0;
    return;
  }
  cout << min(mn, (m / (n / 2 + 1)) * k);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  for (int i = 1; i <= t; i++) {
    check();
  }
  return 0;
}

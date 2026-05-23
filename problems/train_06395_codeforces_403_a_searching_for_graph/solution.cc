#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
long long n, p;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long te;
  cin >> te;
  while (te--) {
    cin >> n >> p;
    vector<pair<long long, long long> > ans;
    for (long long i = 1; i <= n; i++) {
      for (long long j = i + 1; j <= n; j++) {
        ans.push_back({i, j});
      }
    }
    for (long long i = 0; i < 2 * n + p; i++)
      cout << ans[i].first << " " << ans[i].second << "\n";
  }
  return 0;
}

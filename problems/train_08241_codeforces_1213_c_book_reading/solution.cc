#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll solve(ll N, ll M) {
  auto k = N / M;
  if (k == 0) return 0;
  ll p = 0, len = 0;
  set<ll> rs;
  for (ll i = 1; i <= k; ++i) {
    auto r = (i * M) % 10;
    if (rs.count(r) == 1) break;
    rs.insert(r);
    ++p;
    len += r;
  }
  auto ans = (k / p) * len;
  auto left = (k % p);
  for (ll i = 1; i <= left; ++i) {
    auto r = (i * M) % 10;
    ans += r;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  int Q;
  cin >> Q;
  while (Q--) {
    ll N, M;
    cin >> N >> M;
    auto ans = solve(N, M);
    cout << ans << '\n';
  }
  return 0;
}

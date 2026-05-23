#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<pll> xs, ys;
  for (int i = 0; i < n; ++i) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    xs.emplace_back(a + c, i);
    ys.emplace_back(b + d, i);
  }
  sort((xs).begin(), (xs).end());
  sort((ys).begin(), (ys).end());
  long long ans = -1;
  for (int a = 0; a <= k; ++a) {
    for (int b = 0; b <= k; ++b) {
      for (int c = 0; c <= k; ++c) {
        for (int d = 0; d <= k; ++d) {
          set<int> rem;
          for (int i = 0; i < a; ++i) rem.insert(xs[i].second);
          for (int i = 0; i < b; ++i) rem.insert(xs[n - 1 - i].second);
          for (int i = 0; i < c; ++i) rem.insert(ys[i].second);
          for (int i = 0; i < d; ++i) rem.insert(ys[n - 1 - i].second);
          if ((int)rem.size() > k) continue;
          ll w = (xs[n - 1 - b].first - xs[a].first + 1LL) / 2LL;
          ll h = (ys[n - 1 - d].first - ys[c].first + 1LL) / 2LL;
          ans = min(ans, max(1ll, w) * max(1ll, h));
          if (ans == -1) ans = max(1ll, w) * max(1ll, h);
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}

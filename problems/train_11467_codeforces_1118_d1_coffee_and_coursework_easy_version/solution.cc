#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (ll i = 0; i < (ll)n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  ll sum = 0;
  for (ll i = 0; i < (ll)n; i++) sum += a[i];
  if (sum < m) {
    cout << -1 << endl;
    return 0;
  }
  ll l = 0, r = n;
  while (r - l > 1) {
    ll mid = (l + r) / 2;
    ll power = 0;
    ll cnt = 0, cost = 0;
    for (ll i = 0; i < (ll)n; i++) {
      if (a[i] < cost) break;
      power += a[i] - cost;
      cnt++;
      if (cnt == mid) {
        cnt = 0;
        cost++;
      }
    }
    if (power >= m)
      r = mid;
    else
      l = mid;
  }
  cout << r << endl;
  return 0;
}

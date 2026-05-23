#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll get(ll n) {
  if (n % 4 == 0)
    return n;
  else if (n % 4 == 1)
    return 1;
  else if (n % 4 == 2)
    return n + 1;
  else
    return 0;
}
ll get(ll l, ll r) { return (get(r) ^ get(l - 1)); }
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  ll x = 0;
  for (ll i = 0; i < n; i++) {
    ll l, len;
    cin >> l >> len;
    ll r = l + len - 1;
    x ^= get(l, r);
  }
  if (x == 0)
    cout << 'b';
  else
    cout << 't';
  cout << "olik";
  return 0;
}

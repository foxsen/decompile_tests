#include <bits/stdc++.h>
using namespace std;
using ul = unsigned long long;
using ll = long long;
using ld = long double;
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
ll powmod(ll a, ll b) {
  a %= 998244353LL;
  ll res = 1;
  while (b) {
    if (b % 2 == 0) {
      a *= a;
      a %= 998244353LL;
      b /= 2;
    } else {
      res *= a;
      res %= 998244353LL;
      b--;
    }
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll T;
  T = 1;
  for (ll ic = 1; ic <= T; ic++) {
    ll n, m, l, r;
    cin >> n >> m >> l >> r;
    ll tot = r - l + 1;
    ll hmm = n * m;
    ll ans = 0;
    ll tot1 = powmod(tot, hmm);
    if (hmm % 2) {
      ans = 0;
    } else {
      ans = powmod(tot, hmm);
      if (tot % 2) {
        ans--;
        ans += 998244353LL;
        ans %= 998244353LL;
      }
      ans *= powmod(2, 998244353LL - 2);
      ans %= 998244353LL;
    }
    ans = tot1 - ans;
    ans += 2 * 998244353LL;
    ans %= 998244353LL;
    cout << ans << "\n";
  }
}

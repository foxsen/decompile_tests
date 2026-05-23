#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll n;
  ll mod = 998244353;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  ll asum = 0ll;
  ll total = 0ll;
  vector<ll> two_powers(n + 2);
  two_powers[0] = 1ll;
  for (int i = 1; i <= n + 1; ++i) {
    two_powers[i] = (two_powers[i - 1] * 2) % mod;
  }
  for (int i = 0; i < n; ++i) {
    ll fact = (two_powers[n - i - 1] +
               (n - i - 2 >= 0 ? two_powers[n - i - 2] : 0) * (n - i - 1)) %
              mod;
    total += (a[i] * fact) % mod;
    total %= mod;
  }
  cout << total << "\n";
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using llu = unsigned long long;
ll mod = 1e9 + 7;
ll mode = 998244353;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t, n, m, i, j, k;
  cin >> t;
  while (t--) {
    cin >> n;
    ll a[n];
    map<ll, ll> z;
    for (i = 0; i < n; i++) cin >> a[i], z[a[i]]++;
    vector<ll> v;
    for (i = 0; i < n; i++) {
      if (z[a[i]]) {
        v.push_back(z[a[i]]);
        z[a[i]] = 0;
      }
    }
    sort(v.begin(), v.end(), greater<ll>());
    ll ans = 0;
    k = INT_MAX;
    for (auto y : v) {
      k = min(y, k);
      ans += k;
      k--;
      if (k <= 0) break;
    }
    cout << ans << "\n";
  }
}

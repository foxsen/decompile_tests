#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool can(vector<ll> p, ll x, int a, ll y, int b, ll k, int n) {
  vector<int> cnt(n);
  for (int i = a - 1; i < n; i += a) cnt[i] += x;
  for (int i = b - 1; i < n; i += b) cnt[i] += y;
  sort(cnt.begin(), cnt.end(), [](int xx, int yy) { return xx > yy; });
  ll tot = 0;
  sort(p.begin(), p.end(), [](ll xx, ll yy) { return xx > yy; });
  for (int i = 0; i < n; i++) {
    tot += p[i] * cnt[i];
  }
  return tot >= k;
}
int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<ll> p(n);
    for (ll &i : p) cin >> i;
    for (ll &i : p) i /= 100;
    ll x, y;
    int a, b;
    cin >> x >> a;
    cin >> y >> b;
    ll k;
    cin >> k;
    {
      int opt = -1;
      int lo = 1, hi = n, mid;
      while (lo <= hi) {
        mid = lo + hi >> 1;
        if (can(p, x, a, y, b, k, mid)) {
          opt = mid;
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      }
      cout << opt << '\n';
    }
  }
  return 0;
}

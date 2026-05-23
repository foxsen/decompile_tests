#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getrnd(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }
template <typename T1, typename T2>
inline bool relax(T1& a, const T2& b) {
  return a > b ? a = b, true : false;
}
template <typename T1, typename T2>
inline bool strain(T1& a, const T2& b) {
  return a < b ? a = b, true : false;
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int ans = 0;
  for (int tt = 0; tt < 2; ++tt) {
    for (int i = 0; i + 2 < n; ++i) {
      int j = i + 2;
      ll s = a[i + 1];
      while (j < n && s < 2 * a[i]) {
        if (s == (a[i] ^ a[j]) && a[i] > a[j]) ++ans;
        s += a[j];
        ++j;
      }
    }
    reverse(a.begin(), a.end());
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  srand(time(0));
  int t = 1;
  while (t--) solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pll>;
struct d_ {
  template <typename T>
  d_& operator,(const T& x) {
    cerr << ' ' << x;
    return *this;
  }
  template <typename T>
  d_& operator,(const vector<T>& x) {
    for (auto x : x) cerr << ' ' << x;
    return *this;
  }
} d_t;
using ptt = double;
using pt = complex<ptt>;
pt I(0, 1);
pt projp(pt p, pt a, pt b) {
  return a + (conj(p - a) * (b - a)).real() / conj(b - a);
}
pt reflep(pt p, pt a, pt b) { return a + conj((p - a) / (b - a)) * (b - a); }
pt rotp(pt a, pt p, ptt ang) { return (a - p) * polar(1.0, ang) + p; }
ll n;
vector<pt> V;
bool ok(double d) {
  for (ll i(0); i < n; i++) {
    ll u = (i - 1 + n) % n, v = (i + 1) % n;
    pt p = V[i];
    pt xx = projp(V[i], V[u], V[v]);
    if (abs(p - xx) - (1e-10) <= 2 * d) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (ll i(0); i < n; i++) {
    ll a, b;
    cin >> a >> b;
    V.push_back(pt(a, b));
  }
  double l = 0, r = 1e9;
  while (fabs(l - r) + (1e-10) > 1e-6) {
    double m = (l + r) / 2;
    if (ok(m))
      l = m;
    else
      r = m;
  }
  cout << fixed << setprecision(8) << r << endl;
  return 0;
}

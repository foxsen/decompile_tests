#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
using namespace std;
using ll = int64_t;
struct Matrix {
  ll v[2][2];
  Matrix() { memset(v, 0, sizeof(v)); }
};
ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a % b)); }
pair<ll, ll> solve_dumb(ll moves) {
  ll good = 0, every = 0;
  for (int mask = 0; mask < (1 << moves); mask++) {
    array<int, 3> is = {false, true, false};
    for (int i = 0; i < moves; i++) {
      if ((mask >> i) & 1) {
        swap(is[0], is[1]);
      } else {
        swap(is[1], is[2]);
      }
    }
    if (is[1]) ++good;
    ++every;
  }
  ll g = gcd(good, every);
  good /= g;
  every /= g;
  cerr << "dumb: " << good << " " << every << endl;
  return {good, every};
}
constexpr ll MOD = (1000000000 + 7);
Matrix mult(Matrix a, Matrix b) {
  Matrix c;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        c.v[i][j] += a.v[i][k] * b.v[k][j];
      }
      c.v[i][j] %= (2 * MOD);
    }
  }
  return c;
}
Matrix pow(Matrix x, ll n) {
  assert(n >= 1);
  if (n == 1) {
    return x;
  } else if (n % 2 == 0) {
    Matrix y = pow(x, n / 2);
    return mult(y, y);
  } else {
    Matrix y = pow(x, n - 1);
    return mult(y, x);
  }
}
ll bpow(ll x, ll n) {
  ll y = 1;
  while (n) {
    if (n & 1) y = (y * x) % (2 * MOD);
    x = (x * x) % (2 * MOD);
    n /= 2;
  }
  return y;
}
pair<ll, ll> solve_smart(const vector<ll>& moves) {
  Matrix base;
  base.v[0][0] = 0;
  base.v[0][1] = 1;
  base.v[1][0] = 2;
  base.v[1][1] = 1;
  for (ll move : moves) {
    base = pow(base, move);
  }
  ll top_res = base.v[0][0];
  assert(top_res % 2 == 0);
  top_res /= 2;
  top_res %= MOD;
  ll bottom_res = 2;
  for (ll move : moves) {
    bottom_res = bpow(bottom_res, move);
  }
  assert(bottom_res % 2 == 0);
  bottom_res /= 2;
  bottom_res %= MOD;
  return {top_res, bottom_res};
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<ll> moves(n);
  ll m = 1;
  for (int i = 0; i < n; i++) {
    cin >> moves[i];
    m *= moves[i];
  }
  auto res = solve_smart(moves);
  cout << res.first << "/" << res.second << endl;
  return 0;
}

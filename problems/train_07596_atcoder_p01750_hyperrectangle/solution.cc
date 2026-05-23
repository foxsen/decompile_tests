#include <bits/stdc++.h>
using namespace std;

template <class T, class F = multiplies<T>>
T power(T a, long long n, F op = multiplies<T>(), T e = {1}) {
  assert(n >= 0);
  while (n) {
    if (n & 1) e = op(e, a);
    if (n >>= 1) a = op(a, a);
  }
  return e;
}

template <unsigned M> struct modular {
  using m = modular;
  unsigned v;
  modular(long long a = 0) : v((a %= M) < 0 ? a + M : a) {}
  m operator-() const { return m() -= *this; }
  m& operator+=(m r) { if ((v += r.v) >= M) v -= M; return *this; }
  m& operator-=(m r) { if (v < r.v) v += M; v -= r.v; return *this; }
  m& operator*=(m r) { v = (uint64_t)v * r.v % M; return *this; }
  m& operator/=(m r) { return *this *= power(r, M - 2); }
  friend m operator+(m l, m r) { return l += r; }
  friend m operator-(m l, m r) { return l -= r; }
  friend m operator*(m l, m r) { return l *= r; }
  friend m operator/(m l, m r) { return l /= r; }
  friend bool operator==(m l, m r) { return l.v == r.v; }
};

constexpr long long mod = 1e9 + 7;
using mint = modular<mod>;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int d;
  cin >> d;
  vector<int> l(d);
  for (auto&& e : l) {
    cin >> e;
  }
  int s;
  cin >> s;
  vector<vector<mint>> dp(2, vector<mint>(s));
  if (s) {
    dp[0][0] = 1;
  }
  for (auto e : l) {
    auto ndp = dp;
    for (int p : {0, 1}) {
      for (int x = 0; x + e < s; ++x) {
        ndp[p ^ 1][x + e] += dp[p][x];
      }
    }
    swap(dp, ndp);
  }
  mint res;
  for (int p : {0, 1}) {
    for (int x = 0; x < s; ++x) {
      res += power(-1, p) * dp[p][x] * power(mint(s - x), d);
    }
  }
  cout << res.v << '\n';
}


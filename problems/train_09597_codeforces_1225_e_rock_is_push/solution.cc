#include <bits/stdc++.h>
using namespace std;
struct fast_ios {
  fast_ios() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  };
} fast_ios_;
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &x : v) is >> x;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i];
    if (i != v.size() - 1) cout << endl;
  };
  return os;
}
template <typename T>
void Out(T x) {
  cout << x << endl;
}
template <typename T1, typename T2>
void Ans(bool first, T1 y, T2 n) {
  if (first)
    Out(y);
  else
    Out(n);
}
using vec = vector<int>;
using mat = vector<vec>;
using Pii = pair<int, int>;
using PiP = pair<int, Pii>;
using PPi = pair<Pii, int>;
using bools = vector<bool>;
using pairs = vector<Pii>;
const int mod = 1000000007;
template <long long MOD>
struct ModInt {
  using ll = long long;
  ll val;
  void setval(ll v) { val = v % MOD; };
  ModInt() : val(0) {}
  ModInt(ll v) { setval(v); };
  ModInt operator+(const ModInt &x) const { return ModInt(val + x.val); }
  ModInt operator-(const ModInt &x) const { return ModInt(val - x.val + MOD); }
  ModInt operator*(const ModInt &x) const { return ModInt(val * x.val); }
  ModInt operator/(const ModInt &x) const { return *this * x.inv(); }
  ModInt operator-() const { return ModInt(MOD - val); }
  ModInt operator+=(const ModInt &x) { return *this = *this + x; }
  ModInt operator-=(const ModInt &x) { return *this = *this - x; }
  ModInt operator*=(const ModInt &x) { return *this = *this * x; }
  ModInt operator/=(const ModInt &x) { return *this = *this / x; }
  friend ostream &operator<<(ostream &os, const ModInt &x) {
    os << x.val;
    return os;
  }
  friend istream &operator>>(istream &is, ModInt &x) {
    is >> x.val;
    x.val = (x.val % MOD + MOD) % MOD;
    return is;
  }
  ModInt pow(ll n) const {
    ModInt a = 1;
    if (n == 0) return a;
    int i0 = 64 - __builtin_clzll(n);
    for (int i = i0 - 1; i >= 0; i--) {
      a = a * a;
      if ((n >> i) & 1) a *= (*this);
    }
    return a;
  }
  ModInt inv() const { return this->pow(MOD - 2); }
};
using mint = ModInt<mod>;
mint pow(mint x, long long n) { return x.pow(n); }
using mvec = vector<mint>;
using mmat = vector<mvec>;
struct Combination {
  vector<mint> fact, invfact;
  Combination(int N) {
    fact = vector<mint>({mint(1)});
    invfact = vector<mint>({mint(1)});
    fact_initialize(N);
  }
  void fact_initialize(int N) {
    int i0 = fact.size();
    if (i0 >= N + 1) return;
    fact.resize(N + 1);
    invfact.resize(N + 1);
    for (int i = i0; i <= N; i++) fact[i] = fact[i - 1] * i;
    invfact[N] = (mint)1 / fact[N];
    for (int i = N - 1; i >= i0; i--) invfact[i] = invfact[i + 1] * (i + 1);
  }
  mint nCr(int n, int r) {
    if (n < 0 || r < 0 || r > n) return mint(0);
    if (fact.size() < n + 1) fact_initialize(n);
    return fact[n] * invfact[r] * invfact[n - r];
  }
  mint nPr(int n, int r) {
    if (n < 0 || r < 0 || r > n) return mint(0);
    if (fact.size() < n + 1) fact_initialize(n);
    return fact[n] * invfact[n - r];
  }
};
signed main() {
  int n, m;
  cin >> n >> m;
  vector<string> second(n);
  cin >> second;
  if (second[0][0] == 'R' || second[n - 1][m - 1] == 'R') {
    Out(0);
    return 0;
  }
  if (n == 1 && m == 1) {
    Out(1);
    return 0;
  }
  mat cnt1(n, vec(m + 1, 0)), cnt2(n + 1, vec(m, 0));
  mat ls1(n, vec(m + 1, 0)), ls2(m, vec(n + 1, 0));
  for (int i = (0); i < (n); i++) {
    for (int j = (m)-1; j >= (0); j--) {
      cnt1[i][j] = cnt1[i][j + 1];
      if (second[i][j] == 'R') {
        cnt1[i][j]++;
        ls1[i][cnt1[i][j]] = j;
      }
    }
  }
  for (int j = (0); j < (m); j++) {
    for (int i = (n)-1; i >= (0); i--) {
      cnt2[i][j] = cnt2[i + 1][j];
      if (second[i][j] == 'R') {
        cnt2[i][j]++;
        ls2[j][cnt2[i][j]] = i;
      }
    }
  }
  mmat dp1(n, mvec(m, 0)), dp2(n, mvec(m, 0));
  mmat S1(n, mvec(m + 1, 0)), S2(n + 1, mvec(m, 0));
  dp1[0][0] = 1;
  dp2[0][0] = 1;
  S1[0][1] = 1;
  S2[1][0] = 1;
  for (int i = (0); i < (n); i++)
    for (int j = (0); j < (m); j++)
      if (i > 0 || j > 0) {
        if (j > 0) {
          int M = m - 1 - j;
          int j0 = ls1[i][M + 1];
          dp2[i][j] = S1[i][j] - S1[i][j0];
        }
        if (i > 0) {
          int M = n - 1 - i;
          int i0 = ls2[j][M + 1];
          dp1[i][j] = S2[i][j] - S2[i0][j];
        }
        S1[i][j + 1] = S1[i][j] + dp1[i][j];
        S2[i + 1][j] = S2[i][j] + dp2[i][j];
      }
  mint ans = dp1[n - 1][m - 1] + dp2[n - 1][m - 1];
  Out(ans);
  return 0;
}

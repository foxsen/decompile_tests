#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
inline bool chmax(T1 &a, T2 b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T1, class T2>
inline bool chmin(T1 &a, T2 b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
const double EPS = 1e-12, PI = acos(-1);
const double pi = 3.141592653589793238462643383279;
long long GCD(long long a, long long b) { return (b == 0) ? a : GCD(b, a % b); }
long long LCM(long long a, long long b) { return a / GCD(a, b) * b; }
template <int mod>
struct ModInt {
  int x;
  ModInt() : x(0) {}
  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
  ModInt &operator+=(const ModInt &p) {
    if ((x += p.x) >= mod) x -= mod;
    return *this;
  }
  ModInt &operator-=(const ModInt &p) {
    if ((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }
  ModInt &operator*=(const ModInt &p) {
    x = (int)(1LL * x * p.x % mod);
    return *this;
  }
  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }
  ModInt operator-() const { return ModInt(-x); }
  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
  bool operator==(const ModInt &p) const { return x == p.x; }
  bool operator!=(const ModInt &p) const { return x != p.x; }
  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }
  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
  friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x; }
  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt<mod>(t);
    return (is);
  }
  static int get_mod() { return mod; }
};
using modint = ModInt<998244353>;
template <typename T>
struct Combination {
  vector<T> _fact, _rfact, _inv;
  Combination(int sz) : _fact(sz + 1), _rfact(sz + 1), _inv(sz + 1) {
    _fact[0] = _rfact[sz] = _inv[0] = 1;
    for (int i = 1; i <= sz; i++) _fact[i] = _fact[i - 1] * i;
    _rfact[sz] /= _fact[sz];
    for (int i = sz - 1; i >= 0; i--) _rfact[i] = _rfact[i + 1] * (i + 1);
    for (int i = 1; i <= sz; i++) _inv[i] = _rfact[i] * _fact[i - 1];
  }
  inline T fact(int k) const { return _fact[k]; }
  inline T rfact(int k) const { return _rfact[k]; }
  inline T inv(int k) const { return _inv[k]; }
  T P(int n, int r) const {
    if (r < 0 || n < r) return 0;
    return fact(n) * rfact(n - r);
  }
  T C(int p, int q) const {
    if (q < 0 || p < q) return 0;
    return fact(p) * rfact(q) * rfact(p - q);
  }
  T H(int n, int r) const {
    if (n < 0 || r < 0) return (0);
    return r == 0 ? 1 : C(n + r - 1, r);
  }
};
long long modpow(long long x, long long n, long long mod) {
  long long res = 1;
  while (n) {
    if (n & 1) res = (res * x) % mod;
    x = (x * x) % mod;
    n >>= 1;
  }
  return res;
}
int he[101010];
int ta[101010];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);
  string s, t;
  cin >> s >> t;
  int ans = t.size();
  int tl = -1, tr = -1;
  int idx = 0;
  for (int i = 0; i < s.size(); i++) {
    if (idx < t.size() && s[i] == t[idx]) {
      int l = idx + 1, r = t.size() - 1;
      if (ans > r - l + 1) {
        ans = r - l + 1;
        tl = l;
        tr = r;
      }
      idx++;
    }
    he[i + 1] = idx;
  }
  if (idx == t.size()) {
    cout << t << endl;
    return 0;
  }
  ta[s.size()] = t.size();
  int idx2 = t.size() - 1;
  for (int i = s.size() - 1; i >= 0; i--) {
    if (idx2 >= 0 && s[i] == t[idx2]) {
      int l = 0, r = idx2 - 1;
      if (ans > r - l + 1) {
        ans = r - l + 1;
        tl = l;
        tr = r;
      }
      idx2--;
    }
    ta[i] = idx2;
  }
  for (int i = 0; i < s.size(); i++) {
    int tmp = he[i] + t.size() - 1 - ta[i];
    int deleted = t.size() - tmp;
    if (ans > deleted) {
      ans = deleted;
      int l = he[i];
      int r = ta[i];
      tl = min(l, r);
      tr = max(l, r);
    }
  }
  if (ans == t.size())
    cout << "-" << endl;
  else {
    for (int i = 0; i < tl; i++) {
      cout << t[i];
    }
    for (int i = tr + 1; i < t.size(); i++) {
      cout << t[i];
    }
    cout << endl;
  }
  return 0;
}

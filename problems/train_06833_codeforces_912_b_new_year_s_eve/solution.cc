#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using llu = long long unsigned;
using ld = long double;
using pii = pair<lli, lli>;
using vi = vector<lli>;
using vii = vector<pii>;
using vvi = vector<vi>;
using vvii = vector<vii>;
template <typename T>
istream& read_collection(istream& in, T& a);
template <typename A, typename B>
istream& operator<<(istream& in, pair<A, B>& p);
template <class T>
ostream& print_collection(ostream& out, T const& a);
template <class A, class B>
ostream& operator<<(ostream& out, pair<A, B> const& p);
template <typename T>
istream& operator>>(istream& in, vector<T>& v) {
  return read_collection(in, v);
}
template <class T>
ostream& operator<<(ostream& out, vector<T> v) {
  return print_collection(out, v);
}
template <class T>
ostream& operator<<(ostream& out, set<T> s) {
  return print_collection(out, s);
}
template <class T>
ostream& operator<<(ostream& out, multiset<T> s) {
  return print_collection(out, s);
}
template <class T, class U>
ostream& operator<<(ostream& out, map<T, U> m) {
  return print_collection(out, m);
}
template <typename T>
istream& read_collection(istream& in, T& a) {
  for (auto& aa : a) {
    in >> aa;
  }
  return in;
}
template <class T>
ostream& print_collection(ostream& out, T const& a) {
  out << '[';
  for (auto it = begin(a); it != end(a); ++it) {
    out << *it;
    if (it != prev(end(a))) out << ", ";
  }
  return out << "]\n";
}
template <typename A, typename B>
istream& operator>>(istream& in, pair<A, B>& p) {
  return in >> p.first >> p.second;
}
template <class A, class B>
ostream& operator<<(ostream& out, pair<A, B> const& p) {
  return out << '(' << p.first << ", " << p.second << ')';
}
const int INF = (1 << 31) - 1;
const lli LINF = (1ll << 63) - 1;
const llu UINF = (1ull << 64) - 1;
const ld PI = acosl(-1.0);
const ld EPS = 1e-9;
template <class T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <class A, class B>
lli b_s(vector<A>& a, B smth) {
  lli l = -1, r = a.size(), mid = 0;
  while (l < r - 1) {
    mid = (l + r) / 2;
    if (a[mid] < smth)
      l = mid;
    else
      r = mid;
  }
  if (r != a.size()) return r;
  return -1;
}
template <class A, class B>
lli b_se(vector<A>& a, B smth) {
  lli l = -1, r = a.size(), mid = 0;
  while (l < r - 1) {
    mid = (l + r) / 2;
    if (a[mid] <= smth)
      l = mid;
    else
      r = mid;
  }
  if (l != -1) return l;
  return -1;
}
lli mod = 1000000009;
template <class T>
lli powmod(T a, T b) {
  lli res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
template <class T>
vector<T> fast_factorization(T x) {
  vector<T> primes;
  int a[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
  for (int j = 0; j < 3; ++j)
    if (x % a[j] == 0) {
      primes.push_back(a[j]);
      while (x % a[j] == 0) x /= a[j];
    }
  T i = 0, maxi = sqrt(x) + 1;
  for (;; i += 30)
    for (int j = 3; j < 11; ++j) {
      T cur = i + a[j];
      if (cur > maxi) return primes;
      if (x % cur == 0) {
        primes.push_back(cur);
        while (x % cur == 0) x /= cur;
      }
      if (x == 1) return primes;
    }
  return primes;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  lli n = 0, k = 0;
  cin >> n >> k;
  if (k == 1) {
    cout << n;
    return 0;
  }
  lli i = 1;
  while (i <= n) {
    i *= 2;
  }
  cout << i - 1;
  return 0;
}

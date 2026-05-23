#include <bits/stdc++.h>
using namespace std;
static inline void canhazfast() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
template <typename T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <typename T>
T extgcd(T a, T b, T &x, T &y) {
  T x0 = 1, y0 = 0, x1 = 0, y1 = 1;
  while (b) {
    T q = a / b;
    a %= b;
    swap(a, b);
    x0 -= q * x1;
    swap(x0, x1);
    y0 -= q * y1;
    swap(y0, y1);
  }
  x = x0;
  y = y0;
  return a;
}
static inline int ctz(unsigned x) { return __builtin_ctz(x); }
static inline int ctzll(unsigned long long x) { return __builtin_ctzll(x); }
static inline int clz(unsigned x) { return __builtin_clz(x); }
static inline int clzll(unsigned long long x) { return __builtin_clzll(x); }
static inline int popcnt(unsigned x) { return __builtin_popcount(x); }
static inline int popcntll(unsigned long long x) {
  return __builtin_popcountll(x);
}
static inline int bsr(unsigned x) { return 31 ^ clz(x); }
static inline int bsrll(unsigned long long x) { return 63 ^ clzll(x); }
int main() {
  canhazfast();
  int n, m;
  int p1, p2, d1, d2;
  long long t1, t2, len = 0;
  auto step = [&](long long &t, int &p, int &d) -> void {
    if (p < m)
      p = p + d < n ? p + d : p + d - n;
    else
      p = p < d ? p + n - d : p - d;
    --t;
    d = d ? d - 1 : n - 1;
  };
  cin >> n >> m >> p1 >> t1;
  --p1;
  p2 = p1;
  t2 = t1;
  d1 = d2 = t1 % n;
  for (;;) {
    step(t1, p1, d1);
    step(t2, p2, d2);
    if (!t2) return cout << p2 + 1, 0;
    step(t2, p2, d2);
    if (!t2) return cout << p2 + 1, 0;
    if (p1 == p2 && d1 == d2) {
      len = t1 - t2;
      break;
    }
  }
  t2 %= len;
  while (t2) step(t2, p2, d2);
  cout << p2 + 1;
  return 0;
}

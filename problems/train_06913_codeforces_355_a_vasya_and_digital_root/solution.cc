#include <bits/stdc++.h>
using namespace std;
int ts, kk = 1;
template <class T>
inline T _sq(T a) {
  return a * a;
}
template <class T, class X>
inline T _pow(T a, X y) {
  T z = 1;
  for (int i = 1; i <= y; i++) {
    z *= a;
  }
  return z;
}
template <class T>
inline T _gcd(T a, T b) {
  a = _abs(a);
  b = _abs(b);
  if (!b) return a;
  return _gcd(b, a % b);
}
template <class T>
inline T _lcm(T a, T b) {
  a = _abs(a);
  b = _abs(b);
  return (a / _gcd(a, b)) * b;
}
template <class T>
inline T _extended(T a, T b, T &x, T &y) {
  a = _abs(a);
  b = _abs(b);
  T g, x1, y1;
  if (!b) {
    x = 1;
    y = 0;
    g = a;
    return g;
  }
  g = _extended(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return g;
}
template <class T, class X>
inline bool getbit(T a, X i) {
  T t = 1;
  return ((a & (t << i)) > 0);
}
template <class T, class X>
inline T setbit(T a, X i) {
  T t = 1;
  return (a | (t << i));
}
template <class T, class X>
inline T resetbit(T a, X i) {
  T t = 1;
  return (a & (~(t << i)));
}
template <class T, class X>
inline T togglebit(T a, X i) {
  T t = 1;
  return (a ^ (t << i));
}
template <class T, class X, class Y>
inline T _bigmod(T n, X m, Y mod) {
  unsigned long long ret = 1, a = n % mod;
  while (m) {
    if (m & 1) ret = (ret * a) % mod;
    m >>= 1;
    a = (a * a) % mod;
  }
  ret %= mod;
  return (T)ret;
}
template <class T, class Y>
inline T _modinv(T n, Y mod) {
  return _bigmod(n, mod - 2, mod);
}
int main() {
  int n, k, d;
  cin >> k >> d;
  if (d == 0) {
    if (k == 1)
      cout << 0 << endl;
    else
      cout << "No solution" << endl;
    return 0;
  }
  cout << d;
  for (int i = 1; i <= k - 1; i++) {
    cout << 0;
  }
  cout << endl;
  return 0;
}

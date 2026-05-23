#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
template <class T>
inline T rd() {
  T x = 0;
  long long f = 1;
  char c = getchar();
  while (c > '9' || c < '0') f = c == '-' ? -1 : 1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
  return x * f;
}
template <class T>
inline void write(T x) {
  if (x < 0) {
    putchar('-'), write(-x);
    return;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + 48);
}
template <class T>
inline void write_(T x) {
  if (x < 0) {
    putchar('-'), write(-x);
    putchar(' ');
    return;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + 48);
  putchar(' ');
}
template <class T>
inline void writeln(T x) {
  if (x < 0) {
    putchar('-'), write(-x);
    putchar('\n');
    return;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + 48);
  putchar('\n');
}
template <class T>
inline T min(T a, T b, T c) {
  return min(min(a, b), c);
}
template <class T>
inline T max(T a, T b, T c) {
  return max(max(a, b), c);
}
template <class T>
inline T min(T a, T b, T c, T d) {
  return min(min(a, b), min(c, d));
}
template <class T>
inline T max(T a, T b, T c, T d) {
  return max(max(a, b), max(c, d));
}
template <class T, class U>
inline void amin(T &x, U y) {
  if (x > y) x = y;
}
template <class T, class U>
inline void amax(T &x, U y) {
  if (x < y) x = y;
}
template <class T>
inline T fpow(T a, T b, T c) {
  T ans = 1;
  while (b) {
    if (b & 1) ans = 1ll * ans * a % c;
    a = 1ll * a * a % c;
    b >>= 1;
  }
  return ans;
}
template <class T>
inline T fpow(T a, T b) {
  T ans = 1;
  while (b) {
    if (b & 1) ans = 1ll * ans * a;
    a = 1ll * a * a;
    b >>= 1;
  }
  return ans;
}
template <class T>
inline T mul(T a, T b, T p) {
  long long re = 0;
  for (; b; b >>= 1, a = (a + a) % p)
    if (b & 1) re = (re + a) % p;
  return re;
}
template <class T>
inline T inv(T a, T b) {
  return fpow(a, b - 2, b);
}
template <class T>
inline T gcd(T a, T b) {
  if (!b) return a;
  return gcd(b, a % b);
}
template <class T>
inline T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <class T>
inline void Exgcd(T a, T b, T &x, T &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return;
  }
  Exgcd(b, a % b, x, y);
  T tp = x;
  x = y;
  y = tp - a / b * y;
}
const int mod = 998244353;
namespace FWT {
void FWTor(long long *a, int lim, int type) {
  for (int i = 1; i < lim; i <<= 1)
    for (int p = i << 1, j = 0; j < lim; j += p)
      for (int k = 0; k < i; k++)
        a[j + k + i] += type * a[j + k], a[j + k + i] %= mod;
}
void FWTand(long long *a, int lim, int type) {
  for (int i = 1; i < lim; i <<= 1)
    for (int p = i << 1, j = 0; j < lim; j += p)
      for (int k = 0; k < i; k++) {
        a[j + k] += type * a[j + k + i], a[j + k] %= mod;
      }
}
void FWTxor(long long *a, int lim, int type) {
  int inv2 = 499122177;
  for (int i = 1; i < lim; i <<= 1)
    for (int p = i << 1, j = 0; j < lim; j += p)
      for (int k = 0; k < i; k++) {
        long long x = a[j + k], y = a[j + k + i];
        if (type == 1) {
          a[j + k] = 1ll * (x + y) % mod;
          a[j + k + i] = 1ll * (x + mod - y) % mod;
        } else if (type == -1) {
          a[j + k] = 1ll * (x + y) * inv2 % mod;
          a[j + k + i] = 1ll * (x - y + mod) * inv2 % mod;
        }
      }
}
}  // namespace FWT
using namespace FWT;
using namespace std;
struct point {
  int x, y;
  point(double x = 0, double y = 0) : x(x), y(y) {}
  point operator-(const point p) { return point((x - p.x), (y - p.y)); }
  point operator*(const int t) { return point((x * t), (y * t)); }
} p[100005];
point m;
point t1;
int n;
long long jj;
int main() {
  cin >> n >> jj;
  cin >> m.x >> m.y;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    p[i].x = x, p[i].y = y;
  }
  jj %= (n << 1);
  for (int i = 1; i <= jj; i++) {
    t1 = (p[(i - 1) % n] * 2 - m);
    m = t1;
  }
  cout << m.x << " " << m.y << '\n';
}

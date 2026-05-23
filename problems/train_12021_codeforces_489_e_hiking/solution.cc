#include <bits/stdc++.h>
using namespace std;
namespace IO {
template <class T>
inline void readin(T& x) {
  char c;
  bool f = 0;
  while ((c = getchar()) < '0' || '9' < c) f |= (c == '-');
  for (x = (c ^ 48); '0' <= (c = getchar()) && c <= '9';
       x = (x << 1) + (x << 3) + (c ^ 48))
    ;
  if (f) x = -x;
}
template <class T>
inline T readin(T x) {
  x = 0;
  char c;
  bool f = 0;
  while ((c = getchar()) < '0' || '9' < c) f |= (c == '-');
  for (x = (c ^ 48); '0' <= (c = getchar()) && c <= '9';
       x = (x << 1) + (x << 3) + (c ^ 48))
    ;
  return f ? -x : x;
}
template <class T>
void fwrit(const T x) {
  if (x < 0) return (void)(putchar('-'), fwrit(-x));
  if (x > 9) fwrit(x / 10);
  putchar(x % 10 ^ 48);
}
template <class T>
inline T Max(const T x, const T y) {
  return x < y ? y : x;
}
template <class T>
inline T Min(const T x, const T y) {
  return x < y ? x : y;
}
template <class T>
inline T fab(const T x) {
  return x > 0 ? x : -x;
}
inline int gcd(const int a, const int b) { return b ? gcd(b, a % b) : a; }
inline void getInv(int inv[], const int lim, const int MOD) {
  inv[0] = inv[1] = 1;
  for (int i = 2; i <= lim; ++i)
    inv[i] = 1ll * inv[MOD % i] * (MOD - MOD / i) % MOD;
}
inline long long mulMod(const long long a, const long long b,
                        const long long mod) {
  return ((a * b - (long long)((long double)a / mod * b + 1e-8) * mod) % mod +
          mod) %
         mod;
}
}  // namespace IO
using namespace IO;
const int inf = 0x3f3f3f3f;
const int maxn = 1000;
const double eps = 1e-8;
int x[maxn + 5], b[maxn + 5], n, l;
inline void Init() {
  scanf("%d%d", &n, &l);
  for (signed i = (1), i_end_ = (n); i <= i_end_; ++i)
    scanf("%d%d", &x[i], &b[i]);
}
double dp[maxn + 5];
int pre[maxn + 5];
inline int f(const double k) {
  for (signed i = (0), i_end_ = (n); i <= i_end_; ++i) dp[i] = inf, pre[i] = 0;
  dp[0] = 0;
  for (signed i = (1), i_end_ = (n); i <= i_end_; ++i)
    for (signed j = (0), j_end_ = (i - 1); j <= j_end_; ++j) {
      if (dp[j] + sqrt(fab(x[i] - x[j] - l)) - k * b[i] < dp[i]) {
        dp[i] = dp[j] + sqrt(fab(x[i] - x[j] - l)) - k * b[i];
        pre[i] = j;
      }
    }
  if (dp[n] > 0) return 1;
  return 0;
}
void findpath(const int n) {
  if (!pre[n]) {
    fwrit(n), putchar(' ');
    return;
  }
  findpath(pre[n]);
  fwrit(n), putchar(' ');
}
inline void Bisearch() {
  double l = 0, r = inf, mid;
  while (l + eps < r) {
    mid = (l + r) / 2;
    if (f(mid) == 0)
      r = mid;
    else
      l = mid;
  }
  findpath(n);
}
signed main() {
  Init();
  Bisearch();
  return 0;
}

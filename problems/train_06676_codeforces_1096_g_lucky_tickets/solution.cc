#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T lowbit(T x) {
  return x & (-x);
}
template <class T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int N = 2e6 + 10;
const long long Z = 998244353;
long long Pow(long long a, long long b, long long p) {
  if (a == 0) return 0;
  long long ret = 1;
  for (; b; b >>= 1, a = a * a % p)
    if (b & 1) (ret *= a) %= p;
  return ret;
}
long long w[N], w_rev[N];
void init_w(int n) {
  long long x = Pow(3, (Z - 1) / n, Z), y = Pow(x, Z - 2, Z);
  w[0] = w_rev[0] = 1;
  for (int i = (1); i <= (n); i++)
    (w[i] = w[i - 1] * x) %= Z, (w_rev[i] = w_rev[i - 1] * y) %= Z;
}
void bit_rev(int n, long long *x) {
  static long long tmp[N];
  for (int i = 0, j = 0; i < n; i++) {
    tmp[j] = x[i];
    for (int l = n >> 1; (j ^= l) < l; l >>= 1)
      ;
  }
  for (int i = (0); i <= (n - 1); i++) x[i] = tmp[i];
}
void ntt(int n, long long *buf, long long *w) {
  bit_rev(n, buf);
  for (int i = 2; i <= n; i <<= 1) {
    int m = i >> 1;
    for (int j = 0; j < n; j += i)
      for (int k = (0); k <= (m - 1); k++) {
        long long tmp = w[n / i * k] * buf[j + m + k] % Z;
        (buf[j + m + k] = (buf[j + k] - tmp) % Z + Z) %= Z;
        (buf[j + k] += tmp) %= Z;
      }
  }
}
int n, m;
long long f[N];
int main() {
  n = read();
  m = read();
  for (int i = (1); i <= (m); i++) f[read()] = 1;
  int tot = 1 << (long long)ceil(log2(5 * n));
  init_w(tot);
  ntt(tot, f, w);
  for (int i = (0); i <= (tot); i++) f[i] = Pow(f[i], n / 2, Z);
  ntt(tot, f, w_rev);
  long long x = Pow(tot, Z - 2, Z);
  for (int i = (0); i <= (tot); i++) (f[i] *= x) %= Z;
  long long ans = 0;
  for (int i = (0); i <= (tot); i++) (ans += (f[i]) * (f[i]) % Z) %= Z;
  printf("%lld", ans);
}

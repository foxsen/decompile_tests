#include <bits/stdc++.h>
using namespace std;
const int maxn = 7e4 + 100;
long long n, k;
const int mod = 1e9 + 7;
namespace MTT {
const int M = 32768;
int len, t1[maxn], t2[maxn], t3[maxn];
struct Complex {
  long double x, y;
  Complex(long double _x = 0, long double _y = 0) { x = _x, y = _y; }
  Complex operator+(const Complex &r) const {
    return Complex(x + r.x, y + r.y);
  }
  Complex operator-(const Complex &r) const {
    return Complex(x - r.x, y - r.y);
  }
  Complex operator*(const Complex &r) const {
    return Complex(x * r.x - y * r.y, x * r.y + y * r.x);
  }
  int operator=(const int a) {
    *this = Complex(a, 0);
    return a;
  }
};
const double pi = acos(-1.0);
void FFT(Complex P[], int n, int oper) {
  for (int i = 1, j = 0; i < n - 1; i++) {
    for (int s = n; j ^= s >>= 1, ~j & s;)
      ;
    if (i < j) {
      swap(P[i], P[j]);
    }
  }
  for (int d = 0; (1 << d) < n; d++) {
    int m = 1 << d, m2 = m * 2;
    long double p0 = pi / m * oper;
    Complex unit_p0(cos(p0), sin(p0));
    for (int i = 0; i < n; i += m2) {
      Complex unit(1, 0);
      for (int j = 0; j < m; j++) {
        Complex &P1 = P[i + j + m], &P2 = P[i + j];
        Complex t = unit * P1;
        P1 = P2 - t;
        P2 = P2 + t;
        unit = unit * unit_p0;
      }
    }
  }
}
Complex a1[maxn], a2[maxn], b1[maxn], b2[maxn], c1[maxn], c2[maxn], c3[maxn];
void convolution(int *a, int *b, int *res) {
  for (int i = 0; i < len; ++i) {
    a1[i] = a[i] % M;
    a2[i] = a[i] / M;
    b1[i] = b[i] % M;
    b2[i] = b[i] / M;
  }
  FFT(a1, len, 1);
  FFT(a2, len, 1);
  FFT(b1, len, 1);
  FFT(b2, len, 1);
  for (int i = 0; i < len; ++i) {
    c1[i] = a1[i] * b1[i];
    c3[i] = a2[i] * b2[i];
    c2[i] = (a1[i] + a2[i]) * (b1[i] + b2[i]) - c1[i] - c3[i];
  }
  FFT(c1, len, -1);
  FFT(c2, len, -1);
  FFT(c3, len, -1);
  for (int i = 0; i <= k; ++i) {
    int x = (long long)(c1[i].x / len + 0.5) % mod;
    int y = (long long)(c2[i].x / len + 0.5) % mod;
    int z = (long long)(c3[i].x / len + 0.5) % mod;
    res[i] = ((long long)z * M * M + (long long)y * M + x) % mod;
  }
}
void cal(int *res, int *a, int *b, int n, int m) {
  int two = 1;
  for (int i = 0; i < m; ++i) {
    two <<= 1, two %= mod;
  }
  int fac = 1;
  for (int i = 0; i < len; ++i) {
    t3[i] = (long long)a[i] * fac % mod;
    fac = (long long)fac * two % mod;
  }
  convolution(t3, b, res);
}
}  // namespace MTT
int frac[maxn], tmp[maxn];
void go(int n, int *ans) {
  if (n == 1)
    memcpy(ans, tmp, sizeof(int) * MTT::len);
  else {
    go(n / 2, MTT::t1);
    MTT::cal(MTT::t2, MTT::t1, MTT::t1, n / 2, n / 2);
    if (n & 1)
      MTT::cal(ans, MTT::t2, tmp, n - 1, 1);
    else
      memcpy(ans, MTT::t2, sizeof(int) * MTT::len);
  }
}
int ans[maxn];
int main() {
  frac[0] = 1;
  for (int i = (1), iend = (maxn - 1); i <= iend; i++)
    frac[i] = 1ll * frac[i - 1] * i % mod;
  cin >> n >> k;
  if (n > k) {
    cout << "0";
    return 0;
  }
  tmp[0] = tmp[1] = 1;
  MTT::len = 1;
  while (MTT::len < 2 * k + 10) MTT::len <<= 1;
  for (int i = (2), iend = (k); i <= iend; i++)
    tmp[i] = 1ll * (-mod / i + mod) * tmp[mod % i] % mod;
  for (int i = (2), iend = (k); i <= iend; i++)
    tmp[i] = 1ll * tmp[i - 1] * tmp[i] % mod;
  tmp[0] = 0;
  go(n, ans);
  tmp[0] = 1;
  long long out = 0;
  for (int i = (1), iend = (k); i <= iend; i++)
    out = (out + 1ll * ans[i] * frac[k] % mod * tmp[k - i]) % mod;
  cout << out;
  return 0;
}

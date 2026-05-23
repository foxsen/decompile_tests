#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1E-8;
const int FFTSZ = 1 << 20;
const double pi = acos(-1.);
struct cp {
  double real, img;
  cp(double _r = 0.0, double _i = 0.0) : real(_r), img(_i) {}
  cp operator+(const cp &c) const { return cp(real + c.real, img + c.img); }
  cp operator-(const cp &c) const { return cp(real - c.real, img - c.img); }
  cp operator*(const cp &c) const {
    return cp(real * c.real - img * c.img, real * c.img + img * c.real);
  }
};
void fft(cp x[], int n, int op) {
  for (int i = 1, j = 0; i < n; i++) {
    for (int l = n >> 1; (j ^= l) < l; l >>= 1)
      ;
    if (i < j) swap(x[i], x[j]);
  }
  for (int h = 2; h <= n; h <<= 1) {
    cp wn(cos(-op * 2 * pi / h), sin(-op * 2 * pi / h));
    for (int j = 0; j < n; j += h) {
      cp w(1, 0);
      for (int k = j; k < j + h / 2; k++) {
        cp u = x[k], v = w * x[k + h / 2];
        x[k] = u + v, x[k + h / 2] = u - v;
        w = w * wn;
      }
    }
  }
  if (op == -1)
    for (int i = 0; i < n; i++) x[i].real /= n, x[i].img /= n;
}
cp x[FFTSZ], y[FFTSZ];
int convolution(int a[], int lena, int b[], int lenb, int c[]) {
  int len = 1;
  while (len < lena + lenb - 1) len <<= 1;
  for (int i = 0; i < len; i++) {
    if (i < lena)
      x[i] = cp(a[i] * 1.0, 0.0);
    else
      x[i] = cp(0.0, 0.0);
  }
  for (int i = 0; i < len; i++) {
    if (i < lenb)
      y[i] = cp(b[i] * 1.0, 0.0);
    else
      y[i] = cp(0.0, 0.0);
  }
  fft(x, len, 1), fft(y, len, 1);
  for (int i = 0; i < len; i++) x[i] = x[i] * y[i];
  fft(x, len, -1);
  c[len] = 0;
  for (int i = 0; i < len; i++) c[i] = int(x[i].real + 0.5);
  return lena + lenb - 1;
}
const int N = (1 << 20) + 1;
int a[N], p[N];
int n, k;
int main() {
  while (~scanf("%d%d", &n, &k)) {
    (memset(a, 0, sizeof(a))), (memset(p, 0, sizeof(p)));
    a[0] = 1;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
      int v;
      scanf("%d", &v);
      p[v] = 1;
      mx = max(mx, v);
    }
    mx++;
    while (k) {
      if (k & 1) convolution(a, mx, p, mx, a);
      mx = convolution(p, mx, p, mx, p);
      k >>= 1;
      for (int i = 0; i < mx; i++) {
        a[i] = !!a[i];
        p[i] = !!p[i];
      }
    }
    for (int i = 0; i < mx; i++)
      if (a[i] != 0) printf("%d ", i);
    puts("");
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
void change(complex<double> y[], int n) {
  for (int i = 1, j = n >> 1; i < n - 1; i++) {
    if (i < j) swap(y[i], y[j]);
    int k = n / 2;
    while (j >= k) {
      j -= k;
      k >>= 1;
    }
    if (j < k) j += k;
  }
}
void fft(complex<double> y[], int n, int sgn = 1) {
  change(y, n);
  for (int h = 2; h <= n; h <<= 1) {
    complex<double> wn(cos(-sgn * 2 * PI / h), sin(-sgn * 2 * PI / h));
    for (int j = 0; j < n; j += h) {
      complex<double> w(1, 0);
      for (int k = j; k < j + h / 2; k++) {
        complex<double> u = y[k];
        complex<double> t = w * y[k + h / 2];
        y[k] = u + t;
        y[k + h / 2] = u - t;
        w = w * wn;
      }
    }
  }
  if (sgn == -1)
    for (int i = 0; i < n; i++) y[i].real(y[i].real() / n);
}
const int maxn = 1 << 21;
const double eps = 0.5;
int n;
char s[500005];
complex<double> a[maxn], b[maxn];
bool bad[maxn];
int main() {
  int t, cas = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%s", &n, s);
    int len = 1;
    while (len < (n * 2)) len <<= 1;
    memset(a, 0, sizeof(complex<double>) * (len + 1));
    memset(b, 0, sizeof(complex<double>) * (len + 1));
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'V') a[n - i - 1] = complex<double>(1, 0);
      if (s[i] == 'K') b[i] = complex<double>(1, 0);
    }
    fft(a, len);
    fft(b, len);
    for (int i = 0; i < len; ++i) {
      a[i] *= b[i];
    }
    fft(a, len, -1);
    memset(bad, false, sizeof(bool) * (n + 1));
    for (int i = 0; i < len; ++i) {
      if (a[i].real() >= eps) {
        bad[abs(i - n + 1)] = true;
      }
    }
    for (int i = 1; i < n; i++)
      if (!bad[i])
        for (int j = i << 1; j < n; j += i)
          if (bad[j]) {
            bad[i] = true;
            break;
          }
    int res = 0;
    for (int i = 1; i <= n; i++)
      if (!bad[i]) res++;
    printf("%d\n", res);
    for (int i = 1; i <= n; i++) {
      if (!bad[i]) printf("%d ", i);
    }
    putchar('\n');
  }
  return 0;
}

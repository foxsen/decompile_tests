#include <bits/stdc++.h>
using namespace std;
complex<double> ca[2100100], ya[2100100], y2[2100100];
double PI = acos(-1.0);
int invert(int v, int t) {
  int r = 0;
  while (t) {
    r = (r << 1) | (1 & v);
    v >>= 1;
    --t;
  }
  return r;
}
void fft(complex<double> *y, int t, int inv) {
  int lg = 0, k, v, t2;
  while ((1 << lg) < t) lg++;
  for (int i = 1; i < t - 1; i++) {
    for (k = 0, v = i, t2 = lg; t2--; k = (k << 1) | (1 & v), v >>= 1)
      ;
    if (i < k) swap(y[i], y[k]);
  }
  for (int k = 0; k < lg; k++) {
    complex<double> w = exp(complex<double>(0.0, inv * 2.0 * PI / (2 << k))),
                    ww = complex<double>(1.0, 0.0);
    for (int j = 0; j < 1 << k; j++, ww *= w) {
      for (int i = j; i < t; i += (2 << k)) {
        y[i] = y[i] + ww * y[i + (1 << k)];
        y[i + (1 << k)] = y[i] - ww * 2.0 * y[i + (1 << k)];
      }
    }
  }
}
double va[2100100], vc[2100100];
void mult(double *a, int ta, double *c) {
  int t = 1;
  while (t < ta + ta) t <<= 1;
  for (int i = 0; i < t; i++) ca[i] = complex<double>(i < ta ? a[i] : 0.0, 0.0);
  fft(ca, t, 1);
  for (int i = 0; i < t; i++) ca[i] *= ca[i];
  fft(ca, t, -1);
  for (int i = 0; i < t; i++) c[i] = ca[i].real() / t;
}
int r[2100100];
bool mk[2100100];
int main() {
  int n, w, v;
  scanf("%d %d", &n, &w);
  for (int i = 0; i < n; i++) scanf("%d", &v), va[v] = 1.0, mk[v] = true;
  mult(va, w + 1, vc);
  int pnt = 0;
  bool rsp = true;
  for (int i = 0; i < w + 1; i++) {
    if (vc[i] > 1e-3) {
      if (!mk[i]) {
        rsp = false;
        break;
      }
    } else if (mk[i])
      r[pnt++] = i;
  }
  if (rsp) {
    printf("YES\n%d\n", pnt);
    for (int i = 0; i < pnt; i++) {
      if (i) printf(" ");
      printf("%d", r[i]);
    }
    printf("\n");
  } else
    printf("NO\n");
  return 0;
}

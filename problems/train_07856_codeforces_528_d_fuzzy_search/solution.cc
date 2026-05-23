#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const int N = 800050;
void fft(complex<double> a[], int n, bool inv) {
  for (int i = 1, j = 0; i < n; i++) {
    int k = n;
    do j ^= k >>= 1;
    while (~j & k);
    if (j > i) swap(a[i], a[j]);
  }
  for (int j = 2; j <= n; j <<= 1) {
    double ang = PI * 2 / j * (inv ? -1 : 1);
    complex<double> mul(cos(ang), sin(ang));
    int block = n / j;
    for (int i = 0; i < block; i++) {
      complex<double> cur(1, 0);
      for (int k = i * j; k < i * j + j / 2; k++) {
        complex<double> tmp = cur * a[k + j / 2];
        a[k + j / 2] = a[k] - tmp;
        a[k] += tmp;
        cur = cur * mul;
      }
    }
  }
  if (inv)
    for (int i = 0; i < n; i++) a[i] /= n;
}
char s[N], t[N];
int n, m, k;
int a[N], b[N], ans[N], sum[N];
complex<double> A[N], B[N];
void Build(char ch) {
  for (int i = 0; i < n; i++) a[i] = s[i] == ch, sum[i] = a[i];
  for (int i = 1; i < n; i++) sum[i] += sum[i - 1];
  for (int i = 0; i < n; i++)
    a[i] = sum[min(n - 1, i + k)] - (i - k - 1 < 0 ? 0 : sum[i - k - 1]),
    a[i] = min(a[i], 1);
  for (int i = 0; i < m; i++) b[m - i - 1] = t[i] == ch;
}
void Solve() {
  int sz = 1;
  while (sz < n) sz <<= 1;
  sz <<= 1;
  for (int i = n; i < sz; i++) a[i] = 0;
  for (int i = m; i < sz; i++) b[i] = 0;
  for (int i = 0; i < sz; i++)
    A[i] = complex<double>(a[i], 0), B[i] = complex<double>(b[i], 0);
  fft(A, sz, 0);
  fft(B, sz, 0);
  for (int i = 0; i < sz; i++) A[i] = A[i] * B[i];
  fft(A, sz, 1);
  for (int i = m - 1; i < m - 1 + n; i++) ans[i - m + 1] += round(A[i].real());
}
int main() {
  scanf("%i %i %i %s %s", &n, &m, &k, s, t);
  Build('A');
  Solve();
  Build('G');
  Solve();
  Build('T');
  Solve();
  Build('C');
  Solve();
  int sol = 0;
  for (int i = 0; i < n; i++) sol += ans[i] == m;
  printf("%i\n", sol);
  return 0;
}

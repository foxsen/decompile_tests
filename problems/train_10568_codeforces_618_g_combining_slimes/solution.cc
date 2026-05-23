#include <bits/stdc++.h>
using namespace std;
const int N = 50;
int n;
double p, a[55][55], b[55][55], A[55][55], B[55][55], f[55][55], ans;
struct Mat {
  double s[55][55];
  Mat() { memset(s, 0, sizeof s); }
  double* operator[](int i) { return s[i]; }
  Mat operator*(const Mat& B) const {
    Mat ret;
    for (int k = 0; k <= N; k++)
      for (int i = 0; i <= N; i++)
        if (s[i][k])
          for (int j = 0; j <= N; j++) ret.s[i][j] += s[i][k] * B.s[k][j];
    return ret;
  }
} F, G;
int main() {
  scanf("%d%lf", &n, &p), p /= 1e9;
  a[1][1] = p, a[1][2] = b[1][2] = 1 - p;
  for (int i = 2; i <= N; i++) {
    a[i][1] = p, a[i][2] = 1 - p + p * p, b[i][2] = 1 - p;
    for (int j = 3; j <= i + 1; j++)
      a[i][j] = a[i][j - 1] * a[i - 1][j - 1],
      b[i][j] = b[i][j - 1] * a[i - 1][j - 1];
  }
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= i + 1; j++)
      A[i][j] = a[i][j] * (1 - a[i - 1][j]),
      B[i][j] = b[i][j] * (1 - a[i - 1][j]);
  for (int i = 1; i <= N; i++) f[1][i] = i;
  for (int i = 2; i <= N; i++) {
    double s = 0;
    for (int j = 2; j <= N; j++)
      f[i][1] += f[i - 1][j] * B[i - 1][j], s += B[i - 1][j];
    f[i][1] = f[i][1] / s + 1;
    double x = 0, y = 0;
    for (int j = 2; j <= N; j++)
      x += f[i - 1][j - 1] * A[i - 1][j - 1], y += A[i - 1][j - 1],
          f[i][j] = j + x / y;
  }
  if (n <= N) {
    for (int j = 1; j <= N; j++) ans += A[n][j] * f[n][j];
    return printf("%.8f\n", ans), 0;
  }
  F[0][0] = G[0][0] = 1;
  for (int i = 1; i <= N; i++) G[0][i] = i, F[0][i] = f[N][i];
  double s = 0;
  for (int i = 2; i <= N; i++) s += B[N][i];
  for (int k = 2; k <= N; k++) G[k][1] = B[N][k] / s;
  s = 0;
  for (int j = 2; j <= N; j++) {
    s += A[N][j - 1];
    for (int k = 1; k < j; k++) G[k][j] = A[N][k] / s;
  }
  n -= N;
  for (; n; n >>= 1, G = G * G)
    if (n & 1) F = F * G;
  for (int j = 1; j <= N; j++) ans += A[N][j] * F[0][j];
  printf("%.8f\n", ans);
}

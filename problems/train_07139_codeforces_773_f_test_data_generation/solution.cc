#include <bits/stdc++.h>
const int N = 70000;
const long double pi = atan(1.0) * 4;
struct comake_pair {
  long double r, i;
  comake_pair() {}
  comake_pair(long double r_, long double i_) : r(r_), i(i_) {}
  comake_pair operator+(const comake_pair &B) {
    return comake_pair(r + B.r, i + B.i);
  }
  comake_pair operator-(const comake_pair &B) {
    return comake_pair(r - B.r, i - B.i);
  }
  comake_pair operator*(const comake_pair &B) {
    return comake_pair(r * B.r - i * B.i, r * B.i + i * B.r);
  }
} w[2][N];
int rev[N], F[2][N], A[N], B[N], res[2][N];
int m, n, p, ans, c;
void Prepare(int n) {
  for (int i = 0; i < n; i++) {
    w[0][i] = w[1][i] = comake_pair(cos(2 * pi * i / n), sin(2 * pi * i / n));
    w[1][i].i *= -1;
    rev[i] = 0;
    for (int x = i, &y = rev[i], k = 1; k < n; k <<= 1, x >>= 1)
      y = (y << 1) | (x & 1);
  }
}
void FFT(comake_pair *A, int n, int f) {
  comake_pair x, y;
  for (int i = 0; i < n; i++)
    if (i < rev[i]) std::swap(A[i], A[rev[i]]);
  for (int i = 1; i < n; i *= 2)
    for (int j = 0, t = n / (2 * i); j < n; j += (2 * i))
      for (int k = j, l = 0; k < j + i; k++, l += t) {
        x = A[k];
        y = w[f][l] * A[k + i];
        A[k] = x + y;
        A[k + i] = x - y;
      }
  if (f) {
    for (int i = 0; i < n; i++) A[i].r /= n;
  }
}
void Mul(int *A, int *B, int *C, int n, int m) {
  static comake_pair F[N], G[N];
  for (c = 1; c < n + m; c <<= 1)
    ;
  for (int i = 0; i < n; i++) F[i] = comake_pair(A[i], 0);
  for (int i = n; i < c; i++) F[i] = comake_pair(0, 0);
  for (int i = 0; i < m; i++) G[i] = comake_pair(B[i], 0);
  for (int i = m; i < c; i++) G[i] = comake_pair(0, 0);
  Prepare(c);
  FFT(F, c, 0);
  FFT(G, c, 0);
  for (int i = 0; i < c; i++) F[i] = F[i] * G[i];
  FFT(F, c, 1);
  for (int i = 0; i < c; i++) {
    C[i] = (C[i] + (long long)(F[i].r + 0.5)) % p;
  }
}
void Upd(int &x, int y) { x = (x + y) % p; }
void work(int n) {
  if (n == 1) {
    F[0][1] = 1;
    if (n != ::n) {
      for (int i = 1; i < m + 1; i++)
        if (i % 2 != 0) Upd(ans, F[0][i]);
    }
    return;
  }
  work(n / 2);
  memset(res, 0, sizeof(res));
  for (int i = 1; i < m + 1; i++) A[i] = (F[0][i] + F[1][i]) % p;
  for (int t = 0; t < 2; t++) {
    Mul(A, F[t], res[t ^ ((n / 2) & 1)], m + 1, m + 1);
    for (int i = 1; i < m + 1; i++) {
      Upd(res[t][i], F[t][i]);
      Upd(res[t ^ ((n / 2) & 1)][i], F[t][i]);
    }
  }
  memcpy(F, res, sizeof(res));
  if (n % 2 != 0) {
    for (int i = m; i; i--) {
      Upd(F[0][i], (F[0][i - 1] + F[1][i - 1]) % p);
    }
    Upd(F[0][1], 1);
  }
  if (n != ::n) {
    for (int i = 1; i < m + 1; i++)
      if (i & 1) Upd(ans, F[0][i]);
  }
}
int main() {
  std::cin >> m >> n >> p;
  work(n);
  std::cout << ans << '\n';
}

#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const long long ooo = 9223372036854775807ll;
const int _cnt = 1000 * 1000 + 7;
const int _p = 1000 * 1000 * 1000 + 7;
const int N = 1500105;
const double PI = acos(-1.0);
const double eps = 1e-9;
int o(int x) { return x % _p; }
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
void file_put() {
  freopen("filename.in", "r", stdin);
  freopen("filename.out", "w", stdout);
}
long long p, g;
long long mul(long long a, long long b) {
  return a * b - (long long)((long double)a * b / p) * p;
}
long long Pow(long long a, long long b) {
  long long res = 1;
  for (; b; b >>= 1, a = mul(a, a))
    if (b & 1) res = mul(res, a);
  return res;
}
struct FT {
  int rev[N], len;
  long long w[2][N], W[2][N], F[N], G[N];
  void Init(int n) {
    for (len = 1; len < 2 * n; len <<= 1)
      ;
    len <<= 1;
    long long lcm = 1ll * n * len / gcd(n, len);
    p = lcm + 1;
    while (p < 100000) p += lcm;
    for (;; p += lcm) {
      int chk = 1;
      for (int j = 2; (long long)j * j <= p && chk; j++)
        if (p % j == 0) chk = 0;
      if (chk) break;
    }
    for (g = 2;; g++) {
      int chk = 1;
      for (int j = 2; 1ll * j * j <= p - 1 && chk; j++)
        if ((p - 1) % j == 0) {
          if (Pow(g, j) == 1)
            chk = 0;
          else if (Pow(g, (p - 1) / j) == 1)
            chk = 0;
        }
      if (chk) break;
    }
  }
  void preFFT(int n) {
    long long w0 = Pow(g, (p - 1) / n);
    int m;
    w[0][0] = w[1][0] = 1;
    for (int i = (1); i <= (n - 1); ++i) w[0][i] = mul(w[0][i - 1], w0);
    for (int i = (1); i <= (n - 1); ++i) w[1][i] = w[0][n - i];
    for (m = 0; (1 << m) != n; m++)
      ;
    rev[0] = 0;
    for (int i = (1); i <= (n - 1); ++i)
      rev[i] = (rev[i >> 1] >> 1) | (i & 1) << m - 1;
  }
  void FFT(long long *A, int n, int op) {
    for (int i = (0); i <= (n - 1); ++i)
      if (i < rev[i]) swap(A[i], A[rev[i]]);
    for (int i = 1; i < n; i <<= 1)
      for (int j = 0, t = n / (i << 1); j < n; j += i << 1)
        for (int k = j, l = 0; k < j + i; k++, l += t) {
          long long x = A[k], y = mul(w[op][l], A[k + i]);
          A[k] = (x + y >= p ? x + y - p : x + y);
          A[k + i] = (x - y + p >= p ? x - y : x - y + p);
        }
    if (op) {
      long long tmp = Pow(n, p - 2);
      for (int i = (0); i <= (n - 1); ++i) A[i] = mul(A[i], tmp);
    }
  }
  void preDFT(int n, int op) {
    long long w0 = Pow(g, (p - 1) / n);
    W[0][0] = W[1][0] = 1;
    for (int i = (1); i <= (n - 1); ++i) W[0][i] = mul(W[0][i - 1], w0);
    for (int i = (1); i <= (n - 1); ++i) W[1][i] = W[0][n - i];
    for (int i = (0); i <= (2 * n - 1); ++i)
      G[2 * n - 1 - i] = W[op][1ll * i * (i - 1) / 2 % n];
    for (int i = (2 * n); i <= (len - 1); ++i) G[i] = 0;
    for (len = 1; len < 2 * n; len <<= 1)
      ;
    len <<= 1;
    preFFT(len);
    FFT(G, len, 0);
  }
  void DFT(long long *A, int n, int op) {
    for (int i = (0); i <= (n - 1); ++i)
      F[i] = mul(A[i], W[op][(n - 1ll * i * (i - 1) / 2 % n) % n]);
    for (int i = (n); i <= (len - 1); ++i) F[i] = 0;
    FFT(F, len, 0);
    for (int i = (0); i <= (len - 1); ++i) F[i] = mul(F[i], G[i]);
    FFT(F, len, 1);
    for (int i = (0); i <= (n - 1); ++i)
      A[i] = mul(F[2 * n - 1 - i], W[op][(n - 1ll * i * (i - 1) / 2 % n) % n]);
    if (op) {
      long long tmp = Pow(n, p - 2);
      for (int i = (0); i <= (n - 1); ++i) A[i] = mul(A[i], tmp);
    }
  }
  void solve(long long a[], long long b[], long long c[], int n, int op) {
    preDFT(n, 0), DFT(a, n, 0), DFT(b, n, 0);
    for (int i = (0); i <= (n - 1); ++i)
      c[i] = op ? mul(a[i], Pow(b[i], p - 2)) : mul(a[i], b[i]);
    preDFT(n, 1), DFT(c, n, 1);
  }
};
int n;
long long sum = 0, a, b, c, v, A[N], B[N], C[N], A2[N], B2[N], C2[N], s, ans;
set<long long> S;
FT T;
int main() {
  scanf("%d", &n);
  for (int i = (0); i <= (n - 1); ++i) scanf("%I64d", &B[i]);
  for (int i = (0); i <= (n - 1); ++i) scanf("%I64d", &C[i]);
  T.Init(n);
  for (int i = (0); i <= (n - 1); ++i)
    B2[i] = B[i], C2[i] = mul(C[(i + 1) % n] - C[i] + p, Pow(p - 2, p - 2));
  reverse(B2 + 1, B2 + n);
  T.solve(C2, B2, A2, n, 1);
  for (int i = (0); i <= (n - 1); ++i) {
    v = (2 * A2[i] < p) ? A2[i] : A2[i] - p;
    if (abs(v) > 50000) return 0 * printf("0\n");
    A[i] = v;
  }
  a = n, c = -C[0];
  for (int i = (0); i <= (n - 1); ++i)
    b += 2 * (sum - B[i]), c += ((sum - B[i]) * (sum - B[i])), sum += A[i];
  if (sum != 0) return 0 * printf("0\n");
  if (b * b - 4 * a * c >= 0) {
    s = floor(sqrt(b * b - 4 * a * c));
    if (s * s != b * b - 4 * a * c) return 0 * printf("0\n");
    for (int i = (-1); i <= (1); ++i)
      if (i && (-b + i * s) % (2 * a) == 0) S.insert((-b + i * s) / (2 * a));
  }
  printf("%d\n", S.size());
  for (__typeof((S).begin()) it = (S).begin(); it != (S).end(); it++) {
    ans = *it;
    for (int i = (0); i <= (n - 1); ++i) printf("%I64d ", ans), ans += A[i];
    printf("\n");
  }
  return 0;
}

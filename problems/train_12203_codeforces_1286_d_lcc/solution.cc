#include <bits/stdc++.h>
using namespace std;
int read() {
  int X = 0, w = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') w = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') X = X * 10 + c - '0', c = getchar();
  return X * w;
}
const int N = 100000 + 10;
const int mod = 998244353;
int qpow(int a, int b) {
  int c = 1;
  for (; b; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) c = 1ll * c * a % mod;
  return c;
}
int n, x[N], v[N], p[2][N], cnt = 0;
struct node {
  int p, x, v, fl, fr;
} a[N << 1];
bool operator<(node a, node b) { return 1ll * a.x * b.v < 1ll * b.x * a.v; }
struct Matrix {
  int s[2][2];
  Matrix() { memset(s, 0, sizeof(s)); }
  int* operator[](int i) { return s[i]; }
};
Matrix operator*(Matrix a, Matrix b) {
  Matrix c;
  for (int k = 0; k < 2; ++k)
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j)
        c[i][j] = (c[i][j] + 1ll * a[i][k] * b[k][j]) % mod;
  return c;
}
Matrix mulv[N << 2];
void pushup(int o) { mulv[o] = mulv[(o << 1)] * mulv[(o << 1 | 1)]; }
void build(int o, int l, int r) {
  if (l == r) {
    mulv[o][0][0] = mulv[o][1][0] = p[0][l];
    mulv[o][0][1] = mulv[o][1][1] = p[1][l];
    return;
  }
  int mid = (l + r) >> 1;
  build((o << 1), l, mid), build((o << 1 | 1), mid + 1, r);
  pushup(o);
}
void modify(int o, int l, int r, int p, int fl, int fr) {
  if (l == r) {
    mulv[o][fl][fr] = 0;
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid)
    modify((o << 1), l, mid, p, fl, fr);
  else
    modify((o << 1 | 1), mid + 1, r, p, fl, fr);
  pushup(o);
}
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) {
    x[i] = read(), v[i] = read();
    p[1][i] = 1ll * read() * qpow(100, mod - 2) % mod;
    p[0][i] = (1 - p[1][i] + mod) % mod;
  }
  for (int i = 1; i < n; ++i) {
    a[++cnt] = (node){i + 1, x[i + 1] - x[i], v[i] + v[i + 1], 1, 0};
    if (v[i] < v[i + 1])
      a[++cnt] = (node){i + 1, x[i + 1] - x[i], v[i + 1] - v[i], 0, 0};
    if (v[i] > v[i + 1])
      a[++cnt] = (node){i + 1, x[i + 1] - x[i], v[i] - v[i + 1], 1, 1};
  }
  sort(a + 1, a + cnt + 1);
  build(1, 1, n);
  int ans = 0;
  for (int i = 1; i <= cnt; ++i) {
    int P = (mulv[1][0][0] + mulv[1][0][1]) % mod;
    modify(1, 1, n, a[i].p, a[i].fl, a[i].fr);
    int Q = (mulv[1][0][0] + mulv[1][0][1]) % mod;
    ans = (ans + 1ll * a[i].x * qpow(a[i].v, mod - 2) % mod * (P - Q + mod)) %
          mod;
  }
  printf("%d\n", ans);
  return 0;
}

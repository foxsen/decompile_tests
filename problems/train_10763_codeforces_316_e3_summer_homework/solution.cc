#include <bits/stdc++.h>
using namespace std;
const long long maxn = 200005;
const long long mod = 1000000000;
struct matrix {
  long long r, c, m[2][2];
  long long *operator[](long long b) { return m[b]; }
  matrix operator*(matrix b) {
    matrix ret;
    ret.r = r, ret.c = b.c;
    memset(ret.m, 0, sizeof ret.m);
    for (long long i = 0; i < r; ++i)
      for (long long j = 0; j < c; ++j)
        for (long long k = 0; k < b.c; ++k)
          (ret[i][k] += m[i][j] * b[j][k]) %= mod;
    return ret;
  }
  void unit() { m[0][0] = m[1][1] = 1, m[0][1] = m[1][0] = 0; }
};
long long fib[maxn], pfib[maxn], flag[maxn << 2], sum0[maxn << 2],
    sum1[maxn << 2], n, m, a[maxn];
matrix mat[maxn];
bool vis[maxn];
pair<long long, long long> Fib(long long f0, long long f1, long long n) {
  if (!n) return make_pair(f0, f1);
  if (n == 1) return make_pair(f1, (f0 + f1) % mod);
  matrix A, B;
  B.r = 2, B.c = 1;
  B[0][0] = f0;
  B[1][0] = f1;
  if (!vis[n]) {
    long long m = n;
    mat[m].r = mat[m].c = 2;
    mat[m].unit();
    A.r = A.c = 2;
    vis[n] = true;
    A[0][1] = A[1][0] = A[1][1] = 1;
    A[0][0] = 0;
    for (--n; n; n >>= 1) {
      if (n & 1) B = A * B, mat[m] = A * mat[m];
      A = A * A;
    }
  } else
    B = mat[n] * B;
  return make_pair(B[1][0], (B[0][0] + B[1][0]) % mod);
}
void add_value(long long o, long long l, long long r, long long v) {
  (flag[o] += v) %= mod;
  (sum0[o] += (v * pfib[r - l - 1] % mod)) %= mod;
  (sum1[o] += (v * pfib[r - l])) %= mod;
}
void pushdown(long long o, long long l, long long r) {
  if (flag[o]) {
    add_value((o << 1), l, ((l + r) >> 1), flag[o]);
    add_value((o << 1 | 1), ((l + r) >> 1) + 1, r, flag[o]);
    flag[o] = 0;
  }
}
void maintain(long long o, long long l, long long r) {
  pair<long long, long long> newv =
      Fib(sum0[(o << 1 | 1)], sum1[(o << 1 | 1)], ((l + r) >> 1) - l + 1);
  sum0[o] = (sum0[(o << 1)] + newv.first) % mod;
  sum1[o] = (sum1[(o << 1)] + newv.second) % mod;
}
void update(long long o, long long l, long long r, long long p, long long v) {
  if (l == r)
    sum0[o] = 0, sum1[o] = v;
  else {
    pushdown(o, l, r);
    if (p <= ((l + r) >> 1))
      update((o << 1), l, ((l + r) >> 1), p, v);
    else
      update((o << 1 | 1), ((l + r) >> 1) + 1, r, p, v);
    maintain(o, l, r);
  }
}
void update(long long o, long long l, long long r, long long ql, long long qr,
            long long addv) {
  if (ql <= l && r <= qr)
    add_value(o, l, r, addv);
  else {
    pushdown(o, l, r);
    if (ql <= ((l + r) >> 1)) update((o << 1), l, ((l + r) >> 1), ql, qr, addv);
    if (((l + r) >> 1) < qr)
      update((o << 1 | 1), ((l + r) >> 1) + 1, r, ql, qr, addv);
    maintain(o, l, r);
  }
}
pair<long long, long long> query(long long o, long long l, long long r,
                                 long long ql, long long qr) {
  if (ql <= l && r <= qr)
    return make_pair(sum0[o], sum1[o]);
  else {
    pushdown(o, l, r);
    pair<long long, long long> L(0, 0), R(0, 0);
    if (ql <= ((l + r) >> 1)) L = query((o << 1), l, ((l + r) >> 1), ql, qr);
    if (((l + r) >> 1) < qr)
      R = query((o << 1 | 1), ((l + r) >> 1) + 1, r, ql, qr);
    long long llen = max(((l + r) >> 1) - max(ql, l) + 1, 0ll);
    pair<long long, long long> newv = Fib(R.first, R.second, llen);
    return make_pair((L.first + newv.first) % mod,
                     (L.second + newv.second) % mod);
  }
}
void build(long long o, long long l, long long r) {
  if (l == r)
    sum0[o] = 0, sum1[o] = a[l];
  else {
    build((o << 1), l, ((l + r) >> 1));
    build((o << 1 | 1), ((l + r) >> 1) + 1, r);
    maintain(o, l, r);
  }
}
long long read() {
  long long ret = 0, ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    ;
  for (; isdigit(ch); (ret *= 10) += ch - '0', ch = getchar())
    ;
  return ret;
}
int main() {
  fib[0] = pfib[0] = fib[1] = 1, pfib[1] = 2, vis[0] = vis[1] = false;
  for (long long i = 2; i < maxn; ++i)
    fib[i] = (fib[i - 1] + fib[i - 2]) % mod,
    pfib[i] = (pfib[i - 1] + fib[i]) % mod, vis[i] = false;
  n = read(), m = read();
  for (long long i = 1; i <= n; ++i) a[i] = read();
  build(1, 1, n);
  while (m--) {
    long long t, x, y;
    t = read(), x = read(), y = read();
    if (t == 1)
      update(1, 1, n, x, y);
    else if (t == 2)
      printf("%I64d\n", query(1, 1, n, x, y).second);
    else
      update(1, 1, n, x, y, read());
  }
  return 0;
}

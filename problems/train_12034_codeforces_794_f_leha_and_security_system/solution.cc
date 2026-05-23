#include <bits/stdc++.h>
using namespace std;
const long long N = (long long)1e5 + 6, M = 10, mod = (long long)0;
long long a[N], n, seg[N << 2][M], ch[N << 2][M];
void pull(long long v) {
  long long l = v << 1, r = l | 1;
  for (long long j = 0; j < 10; ++j) seg[v][j] = seg[l][j] + seg[r][j];
}
void build(long long v = 1, long long b = 0, long long e = n) {
  if (b + 1 == e) {
    long long x = a[b], z = 1;
    while (x != 0) {
      seg[v][x % 10] += z;
      x /= 10;
      z *= 10;
    }
    return;
  }
  long long m = b + e >> 1, l = v << 1, r = l | 1;
  build(l, b, m);
  build(r, m, e);
  pull(v);
}
long long old[M];
void apply(long long v, long long c[M]) {
  memcpy(old, seg[v], sizeof old);
  for (long long j = 0; j < 10; ++j) {
    long long cur = c[ch[v][j]];
    ch[v][j] = cur;
  }
  memset(seg[v], 0, sizeof seg[v]);
  for (long long j = 0; j < 10; ++j) {
    seg[v][c[j]] += old[j];
  }
}
void push(long long v) {
  long long l = v << 1, r = l | 1;
  apply(l, ch[v]);
  apply(r, ch[v]);
  for (long long j = 0; j < 10; ++j) ch[v][j] = j;
}
long long res[M];
void query(long long i, long long j, long long v = 1, long long b = 0,
           long long e = n) {
  if (i >= e || b >= j) return;
  if (i <= b && e <= j) {
    for (long long k = 0; k < 10; ++k) res[k] += seg[v][k];
    return;
  }
  long long m = b + e >> 1, l = v << 1, r = l | 1;
  push(v);
  query(i, j, l, b, m);
  query(i, j, r, m, e);
}
long long to[M];
void update(long long i, long long j, long long x, long long y, long long v = 1,
            long long b = 0, long long e = n) {
  if (i >= e || b >= j) return;
  if (i <= b && e <= j) {
    for (long long k = 0; k < 10; ++k) to[k] = k;
    to[x] = y;
    apply(v, to);
    return;
  }
  long long m = b + e >> 1, l = v << 1, r = l | 1;
  push(v);
  update(i, j, x, y, l, b, m);
  update(i, j, x, y, r, m, e);
  pull(v);
}
int32_t main() {
  for (long long j = 0; j < (N << 2); ++j)
    for (long long k = 0; k < 10; ++k) ch[j][k] = k;
  long long q;
  cin >> n >> q;
  for (long long j = 0; j < n; ++j) cin >> a[j];
  build();
  while (q--) {
    long long c;
    cin >> c;
    if (c == 1) {
      long long l, r, x, y;
      cin >> l >> r >> x >> y;
      --l;
      update(l, r, x, y);
    } else {
      memset(res, 0, sizeof res);
      long long l, r;
      cin >> l >> r;
      --l;
      query(l, r);
      long long g = 0;
      for (long long j = 0; j < 10; ++j) {
        g += res[j] * j;
      }
      cout << g << '\n';
    }
  }
}

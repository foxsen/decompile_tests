#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &t) {
  t = 0;
  char ch = getchar();
  int f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  do {
    (t *= 10) += ch - '0';
    ch = getchar();
  } while ('0' <= ch && ch <= '9');
  t *= f;
}
template <typename T>
void write(T t) {
  if (t < 0) {
    putchar('-');
    write(-t);
    return;
  }
  if (t > 9) write(t / 10);
  putchar('0' + t % 10);
}
template <typename T>
void writeln(T t) {
  write(t);
  puts("");
}
const int maxn = 50005, mod = 1000000007, inv2 = (mod + 1) / 2;
template <typename _Tp1, typename _Tp2>
inline void add(_Tp1 &a, _Tp2 b) {
  a = a + b >= mod ? a + b - mod : a + b;
}
template <typename _Tp1, typename _Tp2>
inline void sub(_Tp1 &a, _Tp2 b) {
  a = a - b < 0 ? a - b + mod : a - b;
}
long long ksm(long long a, long long b = mod - 2) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod, b >>= 1;
  }
  return res;
}
int n, q;
struct num {
  int a, b;
  inline num operator+=(const num &o) {
    add(a, o.a), add(b, o.b);
    return *this;
  }
  inline num operator+(const num &o) const {
    num x(*this);
    return x += o;
  }
  inline num operator-=(const num &o) {
    sub(a, o.a), sub(b, o.b);
    return *this;
  }
  inline num operator-(const num &o) const {
    num x(*this);
    return x -= o;
  }
  inline num operator*(const num &o) const {
    return {(int)((1LL * a * o.a + 5LL * b * o.b) % mod),
            (int)((1LL * b * o.a + 1LL * a * o.b) % mod)};
  }
  inline num operator*(const int &o) const {
    return {(int)(1LL * o * a % mod), (int)(1LL * o * b % mod)};
  }
  inline num inv() const {
    long long tmp = ksm((1LL * a * a + 1LL * (mod - 5) * b % mod * b) % mod);
    return (num){a, mod - b} * tmp;
  }
  inline num operator/(const num &o) const { return *this * (o.inv()); }
} w1, w2, w1_inv, w2_inv, m1[40], m2[40], m1_inv[40], m2_inv[40];
void Solve(num &A, num *mi, long long x) {
  for (int i = 0; i <= 35; i++)
    if (x >> i & 1) A = A * mi[i];
}
struct fib {
  num A, B;
  void solve(long long x) {
    if (!x) return;
    if (x >= 0) {
      Solve(A, m1, x), Solve(B, m2, x);
    } else
      Solve(A, m1_inv, -x), Solve(B, m2_inv, -x);
  }
  void init(long long x) {
    A = {1, 0}, B = {1, 0};
    solve(x);
  }
  friend fib operator+(fib t1, fib t2) {
    return (fib){t1.A + t2.A, t1.B + t2.B};
  }
  friend fib operator*(fib t1, fib t2) {
    return (fib){t1.A * t2.A, t1.B * t2.B};
  }
} res;
int a[2][maxn];
struct node {
  long long mx[2], mn[2];
  fib f;
  long long lazy[2];
  void puttag(long long a[2]) {
    if (!a[0] && !a[1]) return;
    for (int i = 0; i < 2; i++) lazy[i] += a[i], mx[i] += a[i], mn[i] += a[i];
    f.solve(a[0] + a[1]);
  }
} tr[maxn * 4];
void pushup(int root) {
  for (int i = 0; i < 2; i++) {
    tr[root].mx[i] = max(tr[root << 1].mx[i], tr[root << 1 | 1].mx[i]),
    tr[root].mn[i] = min(tr[root << 1].mn[i], tr[root << 1 | 1].mn[i]);
  }
  tr[root].f = tr[root << 1].f + tr[root << 1 | 1].f;
}
void pushdown(int root) {
  tr[root << 1].puttag(tr[root].lazy);
  tr[root << 1 | 1].puttag(tr[root].lazy);
  tr[root].lazy[0] = tr[root].lazy[1] = 0;
}
void build(int l, int r, int root) {
  if (l == r) {
    for (int i = 0; i < 2; i++) tr[root].mx[i] = tr[root].mn[i] = a[i][l];
    tr[root].f.init(a[0][l] + a[1][l]);
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, root << 1), build(mid + 1, r, root << 1 | 1);
  pushup(root);
}
void chkmin(int L, int R, int l, int r, int root, int k, long long delta) {
  if (tr[root].mx[k] <= delta) return;
  if (L <= l && r <= R && tr[root].mx[k] == tr[root].mn[k]) {
    long long a[2];
    a[k] = delta - tr[root].mx[k];
    a[1 - k] = 0;
    tr[root].puttag(a);
    return;
  }
  pushdown(root);
  int mid = (l + r) >> 1;
  if (L <= mid) chkmin(L, R, l, mid, root << 1, k, delta);
  if (mid < R) chkmin(L, R, mid + 1, r, root << 1 | 1, k, delta);
  pushup(root);
}
void chkmax(int L, int R, int l, int r, int root, int k, long long delta) {
  if (tr[root].mn[k] >= delta) return;
  if (L <= l && r <= R && tr[root].mx[k] == tr[root].mn[k]) {
    long long a[2];
    a[k] = delta - tr[root].mx[k];
    a[1 - k] = 0;
    tr[root].puttag(a);
    return;
  }
  pushdown(root);
  int mid = (l + r) >> 1;
  if (L <= mid) chkmax(L, R, l, mid, root << 1, k, delta);
  if (mid < R) chkmax(L, R, mid + 1, r, root << 1 | 1, k, delta);
  pushup(root);
}
void add(int L, int R, int l, int r, int root, int k, long long delta) {
  if (L <= l && r <= R) {
    long long a[2];
    a[k] = delta;
    a[1 - k] = 0;
    tr[root].puttag(a);
    return;
  }
  pushdown(root);
  int mid = (l + r) >> 1;
  if (L <= mid) add(L, R, l, mid, root << 1, k, delta);
  if (mid < R) add(L, R, mid + 1, r, root << 1 | 1, k, delta);
  pushup(root);
}
void query(int L, int R, int l, int r, int root) {
  if (L <= l && r <= R) {
    res = res + tr[root].f;
    return;
  }
  pushdown(root);
  int mid = (l + r) >> 1;
  if (L <= mid) query(L, R, l, mid, root << 1);
  if (mid < R) query(L, R, mid + 1, r, root << 1 | 1);
}
int main() {
  w1 = {inv2, inv2}, w2 = {inv2, mod - inv2};
  w1_inv = w1.inv(), w2_inv = w2.inv();
  m1[0] = w1, m2[0] = w2, m1_inv[0] = w1_inv, m2_inv[0] = w2_inv;
  for (int i = 1; i <= 39; i++)
    m1[i] = m1[i - 1] * m1[i - 1], m2[i] = m2[i - 1] * m2[i - 1],
    m1_inv[i] = m1_inv[i - 1] * m1_inv[i - 1],
    m2_inv[i] = m2_inv[i - 1] * m2_inv[i - 1];
  read(n), read(q);
  for (int i = 0; i < 2; i++)
    for (int j = 1; j <= n; j++) read(a[i][j]);
  build(1, n, 1);
  int op, l, r, k;
  long long delta;
  while (q--) {
    read(op);
    if (op == 4) {
      read(l), read(r);
      res = (fib){(num){0, 0}, (num){0, 0}};
      query(l, r, 1, n, 1);
      num tmp = res.A - res.B;
      printf("%d\n", tmp.b % mod);
    } else {
      read(k), k--, read(l), read(r);
      read(delta);
      if (op == 1)
        chkmin(l, r, 1, n, 1, k, delta);
      else if (op == 2)
        chkmax(l, r, 1, n, 1, k, delta);
      else
        add(l, r, 1, n, 1, k, delta);
    }
  }
  return 0;
}

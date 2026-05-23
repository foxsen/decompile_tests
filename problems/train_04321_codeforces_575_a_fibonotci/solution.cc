#include <bits/stdc++.h>
using namespace std;
template <typename type>
type beMin(type &a, type b) {
  return a = (a < b ? a : b);
}
template <typename type>
type beMax(type &a, type b) {
  return a = (a > b ? a : b);
}
long long read() {
  long long a = 0, c = getchar(), s = 0;
  while (!isdigit(c)) s |= c == '-', c = getchar();
  while (isdigit(c)) a = a * 10 + c - 48, c = getchar();
  return s ? -a : a;
}
const int N = 110005;
struct Matrix {
  int a, b, c, d;
  void echo() { printf("[%d %d]\n[%d %d]\n", a, b, c, d); }
};
const Matrix base = (Matrix){1, 0, 0, 1};
struct SegTree {
  Matrix tree[N << 2];
  void build(int l, int r, int t);
  Matrix query(int x, int y, int l, int r, int t);
};
struct Extra {
  long long pos, val;
};
long long k;
int n, m, p;
int s[N];
Matrix trans[N], totTrans;
SegTree tree;
Extra ext[N];
inline int _ad(int &a, int &b);
inline int _mu(int &a, int &b);
Matrix operator*(const Matrix &a, const Matrix &b);
Matrix operator*(const Matrix &t, const long long &k);
Matrix operator^(Matrix x, long long y);
Matrix getLine(long long l, long long r);
Matrix mkTran(int s1, int s2);
int main() {
  k = read(), p = read(), n = read();
  for (int i = 0; i < n; ++i) s[i] = read();
  m = read();
  s[n] = s[0];
  for (int i = 1; i <= m; ++i) {
    ext[i] = (Extra){read(), read()};
  }
  totTrans = base;
  for (int i = 1; i <= n; ++i) {
    trans[i] = mkTran(s[i], s[i - 1]);
    totTrans = totTrans * trans[i];
  }
  tree.build(1, n, 1);
  sort(ext + 1, ext + m + 1, [=](Extra a, Extra b) { return a.pos < b.pos; });
  Matrix res = (Matrix){0, 1, 0, 0};
  long long lastp = 0;
  for (int i = 1; i <= m; ++i) {
    if (ext[i].pos > k) break;
    if (lastp < ext[i].pos) {
      if (lastp < ext[i].pos - 1) res = res * getLine(lastp, ext[i].pos - 1);
      if (ext[i - 1].pos == ext[i].pos - 1)
        res = res * mkTran(ext[i].val, ext[i - 1].val);
      else
        res = res * mkTran(ext[i].val, s[(ext[i].pos - 1) % n]);
    }
    if (ext[i].pos < k) {
      if (ext[i].pos + 1 == ext[i + 1].pos)
        res = res * mkTran(ext[i + 1].val, ext[i].val);
      else
        res = res * mkTran(s[(ext[i].pos + 1) % n], ext[i].val);
    }
    lastp = ext[i].pos + 1;
  }
  printf("%d\n", (res * getLine(lastp, k)).a);
  return 0;
}
inline int _ad(int a, int b) { return a + b >= p ? a + b - p : a + b; }
inline int _mu(int a, int b) { return (1ll * a * b) % p; }
Matrix operator*(const Matrix &x, const Matrix &y) {
  return (Matrix){
      _ad(_mu(x.a, y.a), _mu(x.b, y.c)), _ad(_mu(x.a, y.b), _mu(x.b, y.d)),
      _ad(_mu(x.c, y.a), _mu(x.d, y.c)), _ad(_mu(x.c, y.b), _mu(x.d, y.d))};
}
Matrix operator*(const Matrix &t, const long long &k) {
  return (Matrix){_mu(t.a, k), _mu(t.b, k), _mu(t.c, k), _mu(t.d, k)};
}
Matrix operator^(Matrix x, long long y) {
  Matrix res = base;
  while (y) {
    if (y & 1) res = res * x;
    x = x * x;
    y >>= 1;
  }
  return res;
}
void SegTree::build(int l, int r, int t) {
  int mid = (l + r) >> 1;
  if (l == r) {
    tree[t] = trans[mid];
    return;
  }
  build(l, mid, t << 1), build(mid + 1, r, t << 1 | 1);
  tree[t] = tree[t << 1] * tree[t << 1 | 1];
}
Matrix SegTree::query(int x, int y, int l, int r, int t) {
  if (x > y || x > r || y < l) return base;
  if (x <= l && r <= y) return tree[t];
  int mid = (l + r) >> 1;
  return query(x, y, l, mid, t << 1) * query(x, y, mid + 1, r, t << 1 | 1);
}
Matrix getLine(long long l, long long r) {
  if (l > r) return base;
  long long lin = l / n, rin = r / n;
  if (lin == rin) return tree.query(l % n + 1, r % n, 1, n, 1);
  return tree.query(l % n + 1, n, 1, n, 1) * (totTrans ^ (rin - lin - 1)) *
         tree.query(1, r % n, 1, n, 1);
}
Matrix mkTran(int s1, int s2) { return (Matrix){0, s2, 1, s1}; }

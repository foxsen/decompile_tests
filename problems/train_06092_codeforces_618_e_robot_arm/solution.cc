#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
using namespace std;
const double PI = acos(-1.);
namespace SegmentTree {
int n;
const int _ = 2e6 + 100;
double squ(double x) { return x * x; }
struct Vector {
  double x, y;
  Vector() {}
  Vector(double a, double b) {
    x = a;
    y = b;
  }
  double Length() { return sqrt(squ(x) + squ(y)); }
  void pull(double len) {
    double tmp = this->Length();
    x *= (len + tmp) / tmp;
    y *= (len + tmp) / tmp;
  }
};
Vector operator+(const Vector& A, const Vector& B) {
  return Vector(A.x + B.x, A.y + B.y);
}
struct Matrix {
  double a, b, c, d;
  Matrix() {
    a = d = 1;
    c = b = 0;
  }
  Matrix(double $1, double $2, double $3, double $4) {
    a = $1;
    b = $2;
    c = $3;
    d = $4;
  }
  Matrix(double alpha) {
    double $1 = cos(alpha), $2 = sin(alpha);
    a = $1;
    b = -$2;
    c = $2;
    d = $1;
  }
};
inline int sign(double x) { return x < -(1e-9) ? -1 : (x > (1e-9)); }
inline int cmp(double x, double y) { return sign(x - y); }
inline bool operator==(const Matrix& A, const Matrix& B) {
  return cmp(A.a, B.a) == 0 && cmp(A.b, B.b) == 0 && cmp(A.c, B.c) == 0 &&
         cmp(A.d, B.d) == 0;
}
Matrix operator*(const Matrix& A, const Matrix& B) {
  Matrix ret;
  ret.a = A.a * B.a + A.b * B.c;
  ret.b = A.a * B.b + A.b * B.d;
  ret.c = A.c * B.a + A.d * B.c;
  ret.d = A.c * B.b + A.d * B.d;
  return ret;
}
Vector operator*(const Matrix& A, const Vector& B) {
  return Vector(A.a * B.x + A.b * B.y, A.c * B.x + A.d * B.y);
}
Vector v[_];
Matrix tag[_];
void tar(int o, Matrix V) {
  tag[o] = V * tag[o];
  v[o] = V * v[o];
}
void push(int o) {
  if (tag[o] == tag[0]) return;
  tar((o << 1), tag[o]);
  tar(((o << 1) | 1), tag[o]);
  tag[o] = tag[0];
}
void build(int o, int L, int R) {
  if (L == R) return v[o] = Vector(1, 0), void();
  int mid = (L + R) >> 1;
  build((o << 1), L, mid);
  build(((o << 1) | 1), mid + 1, R);
  (v[o] = v[(o << 1)] + v[((o << 1) | 1)]);
}
void build(int __) {
  n = __;
  return build(1, 1, n);
}
void update_pull(int o, int nowl, int nowr, int p, double L) {
  if (nowl == nowr) return v[o].pull(L), void();
  int mid = (nowl + nowr) >> 1;
  push(o);
  if (p <= mid) update_pull((o << 1), nowl, mid, p, L);
  if (p > mid) update_pull(((o << 1) | 1), mid + 1, nowr, p, L);
  (v[o] = v[(o << 1)] + v[((o << 1) | 1)]);
}
void update_pull(int p, double L) { return update_pull(1, 1, n, p, L); }
void update_rotate(int o, int nowl, int nowr, int L, int R, Matrix x) {
  if (L <= nowl && nowr <= R) return tar(o, x);
  int mid = (nowl + nowr) >> 1;
  push(o);
  if (L <= mid) update_rotate((o << 1), nowl, mid, L, R, x);
  if (R > mid) update_rotate(((o << 1) | 1), mid + 1, nowr, L, R, x);
  (v[o] = v[(o << 1)] + v[((o << 1) | 1)]);
}
void update_rotate(int p, double alpha) {
  alpha = 360 - alpha;
  alpha = (alpha / 180.) * PI;
  update_rotate(1, 1, n, p, n, Matrix(alpha));
}
Vector query() {
  push(1);
  return v[1];
}
}  // namespace SegmentTree
using SegmentTree::build;
using SegmentTree::query;
using SegmentTree::update_pull;
using SegmentTree::update_rotate;
using SegmentTree::Vector;
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  build(n);
  while (m--) {
    int opt, x;
    scanf("%d%d", &opt, &x);
    if (opt == 1) {
      double L;
      scanf("%lf", &L);
      update_pull(x, L);
    } else {
      double alpha;
      scanf("%lf", &alpha);
      update_rotate(x, alpha);
    }
    Vector ret = query();
    printf("%.5lf %.5lf\n", ret.x, ret.y);
  }
  return 0;
}

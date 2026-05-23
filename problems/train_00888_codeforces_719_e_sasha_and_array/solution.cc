#include <bits/stdc++.h>
using namespace std;
inline int readInt() {
  static int n, ch;
  n = 0, ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) n = n * 10 + ch - '0', ch = getchar();
  return n;
}
const int MOD = 1000000007;
int t[2][2];
struct Matrix {
  int a[2][2];
  Matrix() { memset(a, 0, sizeof a); }
  int *operator[](int i) { return *(a + i); }
  const int *operator[](int i) const { return *(a + i); }
  inline void operator*=(const Matrix &m1) {
    memset(t, 0, sizeof t);
    for (int i = 0; i < 2; ++i)
      for (int k = 0; k < 2; ++k)
        for (int j = 0; j < 2; ++j)
          (t[i][j] += (long long)a[i][k] * m1.a[k][j] % MOD) %= MOD;
    memcpy(a, t, sizeof t);
  }
} I;
const int MAX_S = 64;
Matrix mem[MAX_S];
inline Matrix f(long long n) {
  Matrix A;
  A[0][0] = A[1][1] = 1;
  for (int i = 0; i < MAX_S; ++i)
    if ((n >> i) & 1) A *= mem[i];
  return A;
}
void init() {
  mem[0][0][0] = mem[0][0][1] = mem[0][1][0] = 1;
  for (int i = 1; i < MAX_S; ++i) {
    mem[i] = mem[i - 1];
    mem[i] *= mem[i - 1];
  }
}
const int MAX_N = 100000 + 3;
int n, m, a[MAX_N];
struct SegmentTree {
  static const int MAX_NODE = (1 << 17) * 2 + 1;
  struct Node {
    Matrix matrix, tagMul;
  } nodes[MAX_NODE];
  inline void multiply(int o, Matrix c) {
    Node &v = nodes[o];
    v.tagMul *= c;
    v.matrix *= c;
  }
  inline void pushDown(int o) {
    multiply(((o)*2 + 1), nodes[o].tagMul);
    multiply(((o)*2 + 2), nodes[o].tagMul);
    nodes[o].tagMul = I;
  }
  inline Matrix merge(const Matrix &a, const Matrix &b) {
    Matrix c;
    c[0][0] = (a[0][0] + b[0][0]) % MOD;
    c[0][1] = (a[0][1] + b[0][1]) % MOD;
    c[1][0] = (a[1][0] + b[1][0]) % MOD;
    c[1][1] = (a[1][1] + b[1][1]) % MOD;
    return c;
  }
  void build(int o, int l, int r, int a[]) {
    Node &v = nodes[o];
    v.tagMul = I;
    if (r - l == 1)
      v.matrix = f(a[l]);
    else {
      build(((o)*2 + 1), l, (((l) + (r)) >> 1), a),
          build(((o)*2 + 2), (((l) + (r)) >> 1), r, a);
      v.matrix = merge(nodes[((o)*2 + 1)].matrix, nodes[((o)*2 + 2)].matrix);
    }
  }
  void init(int n, int a[]) { build(0, 0, n, a); }
  Matrix query(int o, int l, int r, int a, int b) {
    if (l >= a && r <= b)
      return nodes[o].matrix;
    else {
      pushDown(o);
      Matrix res;
      if ((((l) + (r)) >> 1) > a)
        res = merge(res, query(((o)*2 + 1), l, (((l) + (r)) >> 1), a, b));
      if ((((l) + (r)) >> 1) < b)
        res = merge(res, query(((o)*2 + 2), (((l) + (r)) >> 1), r, a, b));
      return res;
    }
  }
  void modify(int o, int l, int r, int a, int b, Matrix x) {
    if (r <= a || l >= b) return;
    if (l >= a && r <= b)
      multiply(o, x);
    else {
      pushDown(o);
      if ((((l) + (r)) >> 1) > a)
        modify(((o)*2 + 1), l, (((l) + (r)) >> 1), a, b, x);
      if ((((l) + (r)) >> 1) < b)
        modify(((o)*2 + 2), (((l) + (r)) >> 1), r, a, b, x);
      nodes[o].matrix =
          merge(nodes[((o)*2 + 1)].matrix, nodes[((o)*2 + 2)].matrix);
    }
  }
  inline int query(int l, int r) { return query(0, 0, n, l, r)[1][0]; }
  inline void modify(int l, int r, int c) { modify(0, 0, n, l, r, f(c)); }
} segmentTree;
int main() {
  init();
  n = readInt(), m = readInt();
  for (int i = 0; i < n; ++i) a[i] = readInt();
  I[0][0] = 1, I[1][1] = 1;
  segmentTree.init(n, a);
  while (m--) {
    int type = readInt(), l = readInt() - 1, r = readInt();
    if (type == 1)
      segmentTree.modify(l, r, readInt());
    else if (type == 2)
      printf("%d\n", segmentTree.query(l, r));
    else
      assert(false);
  }
  return 0;
}

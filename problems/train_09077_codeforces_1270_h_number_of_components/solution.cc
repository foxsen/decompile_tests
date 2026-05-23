#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e6 + 10;
int n, q, m;
int a[SIZE], xi[SIZE];
int ql, qr, qv, qt;
class SegmentTree {
 public:
  int size;
  int lazyTag[SIZE << 2];
  struct Node {
    int v, c;
    friend Node operator+(Node A, Node B) {
      Node C;
      C.v = min(A.v, B.v), C.c = 0;
      if (A.v == C.v) C.c += A.c;
      if (B.v == C.v) C.c += B.c;
      return C;
    }
  } node[SIZE << 2];
  void add(int c, int t) {
    lazyTag[c] += t;
    node[c].v += t;
  }
  void updateDown(int c) {
    if (lazyTag[c]) {
      add(c * 2, lazyTag[c]);
      add(c * 2 + 1, lazyTag[c]);
      lazyTag[c] = 0;
    }
  }
  void updateUp(int c) { node[c] = node[c * 2] + node[c * 2 + 1]; }
  void get(int c, int l) {
    if (xi[l])
      node[c] = (Node){lazyTag[c], 1};
    else
      node[c] = (Node){1000000000, 0};
  }
  void update1(int l, int r, int c) {
    if (ql <= l && qr >= r) return add(c, qt);
    int mid = (l + r) / 2;
    updateDown(c);
    if (ql <= mid) update1(l, mid, c * 2);
    if (qr > mid) update1(mid + 1, r, c * 2 + 1);
    updateUp(c);
  }
  void build(int l, int r, int c) {
    if (l == r) return get(c, l);
    int mid = (l + r) / 2;
    updateDown(c);
    build(l, mid, c * 2), build(mid + 1, r, c * 2 + 1);
    updateUp(c);
  }
  void update2(int l, int r, int c) {
    if (l == r) return get(c, l);
    int mid = (l + r) / 2;
    updateDown(c);
    if (qv <= mid)
      update2(l, mid, c * 2);
    else
      update2(mid + 1, r, c * 2 + 1);
    updateUp(c);
  }

 public:
  void insert(int x, int t) {
    int l = min(a[x], a[x + 1]), r = max(a[x], a[x + 1]);
    ql = l, qr = r - 1, qt = t;
    update1(0, size, 1);
  }
  void update2(int c) { update2(0, size, c); }
  void build(int c) { build(0, size, c); }
  void setSize(int Size) { size = Size; }
} T;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> q;
  m = 1e6 + 1;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    xi[a[i]] = 1;
  }
  a[0] = m, a[n + 1] = 0;
  T.setSize(m);
  for (int i = 0; i <= n; ++i) T.insert(i, 1);
  T.build(1);
  while (q--) {
    int x, v;
    cin >> x >> v;
    T.insert(x - 1, -1);
    T.insert(x, -1);
    xi[a[x]] = 0;
    qv = a[x];
    T.update2(1);
    a[x] = v;
    T.insert(x - 1, 1);
    T.insert(x, 1);
    xi[a[x]] = 1;
    qv = a[x];
    T.update2(1);
    cout << (T.node[1].v == 1 ? T.node[1].c : 1) << endl;
  }
  return 0;
}

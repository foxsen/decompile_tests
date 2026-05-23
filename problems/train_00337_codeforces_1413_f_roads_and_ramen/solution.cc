#include <bits/stdc++.h>
using namespace std;
int n, m, nex[2000000], hea[2000000], wen[2000000], val[2000000], aid[2000000],
    root2, root1, len, maxx;
struct segment_tree {
  int a[2000000][2], lazy[2000000], fa[1000000], dep[1000000], in[1000000],
      out[1000000], m;
  void pushdown(int k) {
    if (!lazy[k]) return;
    swap(a[k << 1][0], a[k << 1][1]);
    swap(a[(k << 1) | 1][0], a[(k << 1) | 1][1]);
    lazy[k << 1] ^= 1;
    lazy[(k << 1) | 1] ^= 1;
    lazy[k] = 0;
  }
  void update1(int l, int r, int k, int x, int y, int z) {
    if (l == r) {
      a[k][z] = y;
      return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) update1(l, mid, k << 1, x, y, z);
    if (x > mid) update1(mid + 1, r, (k << 1) | 1, x, y, z);
    a[k][0] = max(a[k << 1][0], a[(k << 1) | 1][0]);
    a[k][1] = max(a[k << 1][1], a[(k << 1) | 1][1]);
  }
  void update2(int l, int r, int k, int x, int y) {
    if (l >= x && r <= y) {
      lazy[k] ^= 1;
      swap(a[k][0], a[k][1]);
      return;
    }
    pushdown(k);
    int mid = (l + r) >> 1;
    if (x <= mid) update2(l, mid, k << 1, x, y);
    if (y > mid) update2(mid + 1, r, (k << 1) | 1, x, y);
    a[k][0] = max(a[k << 1][0], a[(k << 1) | 1][0]);
    a[k][1] = max(a[k << 1][1], a[(k << 1) | 1][1]);
  }
  void build(int x, int y, int z) {
    int a = 0;
    in[x] = ++m;
    dep[x] = dep[y] + 1;
    for (int i = hea[x]; i; i = nex[i])
      if (wen[i] != y) {
        ++a;
        fa[aid[i]] = wen[i];
        build(wen[i], x, z ^ val[i]);
      }
    update1(1, n, 1, in[x], dep[x], z);
    out[x] = m;
  }
  void revers(int x) { update2(1, n, 1, in[fa[x]], out[fa[x]]); }
} st1, st2;
void add(int x, int y, int z, int p) {
  ++len;
  nex[len] = hea[x];
  wen[len] = y;
  val[len] = z;
  aid[len] = p;
  hea[x] = len;
}
void dfs(int x, int y, int z) {
  if (z >= maxx) maxx = z, root1 = x;
  for (int i = hea[x]; i; i = nex[i])
    if (wen[i] != y) dfs(wen[i], x, z + 1);
}
void dfs1(int x, int y, int z) {
  if (z >= maxx) maxx = z, root2 = x;
  for (int i = hea[x]; i; i = nex[i])
    if (wen[i] != y) dfs1(wen[i], x, z + 1);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    add(x, y, z, i);
    add(y, x, z, i);
  }
  dfs(1, 0, 0);
  dfs1(root1, 0, 0);
  st1.build(root1, 0, 0);
  st2.build(root2, 0, 0);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int x;
    scanf("%d", &x);
    st1.revers(x);
    st2.revers(x);
    printf(" %d\n", max(st1.a[1][0], st2.a[1][0]) - 1);
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, m, a[maxn], p[20][maxn * 3], sign[20][maxn * 3];
void pushup(int pos, int rt) {
  p[pos][rt] = p[pos][rt << 1] + p[pos][rt << 1 | 1];
}
void pushdown(int pos, int rt, int l, int r) {
  if (sign[pos][rt]) {
    int mid = (l + r) / 2;
    sign[pos][rt << 1] = 1 - sign[pos][rt << 1];
    sign[pos][rt << 1 | 1] = 1 - sign[pos][rt << 1 | 1];
    sign[pos][rt] = 0;
    p[pos][rt << 1] = (mid - l + 1) - p[pos][rt << 1];
    p[pos][rt << 1 | 1] = (r - mid) - p[pos][rt << 1 | 1];
  }
}
void build(int pos, int rt, int l, int r) {
  if (l == r) {
    p[pos][rt] = (a[l] >> pos) & 1;
    return;
  }
  int mid = (l + r) / 2;
  build(pos, rt << 1, l, mid);
  build(pos, rt << 1 | 1, mid + 1, r);
  pushup(pos, rt);
}
void update(int pos, int rt, int l, int r, int L, int R) {
  if (L <= l && r <= R) {
    sign[pos][rt] = 1 - sign[pos][rt];
    p[pos][rt] = r - l + 1 - p[pos][rt];
    return;
  }
  pushdown(pos, rt, l, r);
  int mid = (l + r) / 2;
  if (L <= mid) update(pos, rt << 1, l, mid, L, R);
  if (R >= mid + 1) update(pos, rt << 1 | 1, mid + 1, r, L, R);
  pushup(pos, rt);
}
int query(int pos, int rt, int l, int r, int L, int R) {
  if (L <= l && r <= R) {
    return p[pos][rt];
  }
  pushdown(pos, rt, l, r);
  int mid = (l + r) / 2;
  int ret = 0;
  if (L <= mid) ret += query(pos, rt << 1, l, mid, L, R);
  if (R >= mid + 1) ret += query(pos, rt << 1 | 1, mid + 1, r, L, R);
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < 20; i++) {
    build(i, 1, 1, n);
  }
  scanf("%d", &m);
  while (m--) {
    int opt;
    scanf("%d", &opt);
    if (opt == 1) {
      int l, r;
      long long sum = 0;
      scanf("%d%d", &l, &r);
      for (int i = 0; i < 20; i++) {
        sum += (long long)(1 << i) * query(i, 1, 1, n, l, r);
      }
      printf("%I64d\n", sum);
    } else {
      int l, r, x;
      scanf("%d%d%d", &l, &r, &x);
      for (int i = 0; i < 20; i++) {
        if ((x >> i) & 1) update(i, 1, 1, n, l, r);
      }
    }
  }
  return 0;
}

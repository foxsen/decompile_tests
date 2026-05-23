#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y;
  friend bool operator<(const node &a, const node &b) { return a.y > b.y; }
} a[100010];
int lc[100010], rc[100010];
int lx[100010], rx[100010];
int x[100010], xn, fr[100010];
int tree[100010 << 2];
int n, m;
int cmp(int x, int y) { return a[x].y > a[y].y ? x : y; }
void init_tree(int p, int tl, int tr) {
  if (tl == tr) {
    tree[p] = fr[tl];
    return;
  }
  int m = (tl + tr) >> 1;
  init_tree(p << 1, tl, m);
  init_tree((p << 1) + 1, m + 1, tr);
  tree[p] = cmp(tree[p << 1], tree[(p << 1) + 1]);
}
int Find(int p, int tl, int tr, int l, int r) {
  if (tl == l && tr == r) return tree[p];
  int m = (tl + tr) >> 1;
  if (l <= m) {
    if (r > m) {
      return cmp(Find(p << 1, tl, m, l, m),
                 Find((p << 1) + 1, m + 1, tr, m + 1, r));
    } else
      return Find(p << 1, tl, m, l, r);
  } else
    return Find((p << 1) + 1, m + 1, tr, l, r);
}
void init() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) scanf("%d%d", &a[i].x, &a[i].y);
  long long A, B, C, D;
  int ta, tb, tc, td;
  scanf("%d%d%d%d", &ta, &tb, &tc, &td);
  A = ta, B = tb, C = tc, D = td;
  for (int i = m; i < n; i++) {
    long long tx = (A * a[i - 1].x + B) % 1000000009;
    long long ty = (C * a[i - 1].y + D) % 1000000009;
    a[i].x = (int)tx;
    a[i].y = (int)ty;
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) x[i] = a[i].x;
  sort(x, x + n);
  xn = n;
  for (int i = 0; i < n; i++) {
    int k = lower_bound(x, x + n, a[i].x) - x;
    fr[k] = i;
  }
  init_tree(1, 0, n - 1);
}
pair<int, int> q[100010];
int num[100010];
void build() {
  int qn = 1;
  q[0] = make_pair(0, xn - 1);
  num[0] = tree[1];
  for (int p = 0; p < qn; p++) {
    int L = q[p].first, R = q[p].second;
    int d = num[p];
    int k = lower_bound(x, x + n, a[d].x) - x;
    lx[d] = x[L];
    rx[d] = x[R];
    if (k == L)
      lc[d] = -1;
    else {
      lc[d] = Find(1, 0, xn - 1, L, k - 1);
      num[qn] = lc[d];
      q[qn++] = make_pair(L, k - 1);
    }
    if (k == R)
      rc[d] = -1;
    else {
      rc[d] = Find(1, 0, xn - 1, k + 1, R);
      num[qn] = rc[d];
      q[qn++] = make_pair(k + 1, R);
    }
  }
}
struct Tnode {
  int f, g;
  friend Tnode operator+(const Tnode &a, const Tnode &b) {
    Tnode ret;
    ret.g = 0;
    if (a.f > -1) ret.g += a.f;
    if (b.f > -1) ret.g += b.f;
    ret.f = ret.g;
    if (a.f > -1)
      if (b.f > -1)
        ret.f = max(ret.f, a.g + 1 + b.f);
      else
        ret.f = max(ret.f, a.g + 1);
    if (b.f > -1)
      if (a.f > -1)
        ret.f = max(ret.f, b.g + 1 + a.f);
      else
        ret.f = max(ret.f, b.g + 1);
    return ret;
  }
} zero, f[100010];
int root;
void dp(int x) {
  if (lc[x] == -1 && rc[x] == -1) {
    f[x].f = f[x].g = 0;
    return;
  }
  if (lc[x] > -1) dp(lc[x]);
  if (rc[x] > -1) dp(rc[x]);
  Tnode lt = (lc[x] == -1 ? zero : f[lc[x]]);
  Tnode rt = (rc[x] == -1 ? zero : f[rc[x]]);
  f[x] = lt + rt;
}
Tnode get(int p, int L, int R) {
  if (p == -1) return zero;
  if (lx[p] >= L && rx[p] <= R) return f[p];
  if (lx[p] > R || rx[p] < L) return zero;
  int dx = a[p].x;
  if (dx < L) return get(rc[p], L, R);
  if (dx > R) return get(lc[p], L, R);
  Tnode ret = get(lc[p], L, R) + get(rc[p], L, R);
  return ret;
}
void work() {
  int qn;
  for (scanf("%d", &qn); qn; qn--) {
    int L, R;
    scanf("%d%d", &L, &R);
    Tnode ans = get(root, L, R);
    printf("%d\n", max(0, ans.f));
  }
}
int main() {
  init();
  build();
  zero.f = zero.g = -1;
  root = tree[1];
  dp(root);
  work();
  return 0;
}

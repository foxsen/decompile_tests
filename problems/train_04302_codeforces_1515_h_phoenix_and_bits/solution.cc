#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 5, K = 20, W = 1 << K;

int n, q, tot;
int ls[N], rs[N], sum[N], or0[N], or1[N], tag[N], dep[N];

void pushup(int p) {
  sum[p] = sum[ls[p]] + sum[rs[p]];
  or0[p] = or0[ls[p]] | or0[rs[p]];
  or1[p] = or1[ls[p]] | or1[rs[p]];
}

void Tag(int p, int k) {
//  printf("Tag(%d, %d)\n", p, k);
  if (!p) return ;
  tag[p] ^= k;
  if (dep[p] != -1 && k >> dep[p] & 1) swap(ls[p], rs[p]);
  int tmp0 = (or0[p] & (~k)) | (or1[p] & k);
  int tmp1 = (or1[p] & (~k)) | (or0[p] & k);
  or0[p] = tmp0, or1[p] = tmp1;
//  printf("or0[%d] = %d, or1[%d] = %d\n", p, or0[p], p, or1[p]);
}

void pushdown(int p) {
  if (!tag[p]) return ;
  Tag(ls[p], tag[p]), Tag(rs[p], tag[p]);
  tag[p] = 0;
}

void insert(int &p, int k, int d) {
  if (!p) p = ++tot;
  dep[p] = d;
  if (d == -1) {
    or1[p] = k, or0[p] = k ^ (W - 1), sum[p] = 1;
    return ;
  }
  insert((k >> d & 1) ? rs[p] : ls[p], k, d - 1);
  pushup(p);
}

void split(int &p, int &q, int l, int r, int x, int y) {
  if (!p || y < l || x > r) return q = 0, void();
  if (x <= l && r <= y) {
    q = p, p = 0;
    return ;
  }
  int mid = (l + r) >> 1;
  pushdown(p), q = ++tot;
  dep[q] = dep[p];
  split(ls[p], ls[q], l, mid, x, y);
  split(rs[p], rs[q], mid + 1, r, x, y);
  pushup(p), pushup(q);
}

void merge(int &p, int q) {
  if (!p || !q) return p = p + q, void();
  pushdown(p), pushdown(q);
  merge(ls[p], ls[q]);
  merge(rs[p], rs[q]);
  if (dep[p] != -1) pushup(p);
}

void modify(int p, int k) {
//  printf("modify(%d, %d)\n", p, k);
  if (!p) return ;
  if ((k & or0[p] & or1[p]) == 0) {
    return Tag(p, k & or0[p]), void();
  }
  pushdown(p);
  if (dep[p] != -1 && k >> dep[p] & 1) {
    Tag(ls[p], 1 << dep[p]);
    merge(rs[p], ls[p]), ls[p] = 0;
  }
  modify(ls[p], k), modify(rs[p], k);
  pushup(p);
}

int main() {
  scanf("%d%d", &n, &q);
  int x = 0;
  for (int i = 1; i <= n; i++) {
    int v; scanf("%d", &v);
    insert(x, v, K - 1);
  }
//  for (int i = 1; i <= tot; i++) {
//    printf("%d : ls = %d, rs = %d, or0 = %d, or1 = %d, tag = %d, sum = %d\n", i, ls[i], rs[i], or0[i], or1[i], tag[i], sum[i]);
//  }
  while (q--) {
    int t, l, r, y, k;
    scanf("%d%d%d", &t, &l, &r);
    split(x, y, 0, W - 1, l, r);
    if (t == 1) {
      scanf("%d", &k);
      Tag(y, W - 1);
      modify(y, k ^ (W - 1));
      Tag(y, W - 1);
    } else if (t == 2) {
      scanf("%d", &k);
      modify(y, k);
    } else if (t == 3) {
      scanf("%d", &k);
      Tag(y, k);
    } else {
      printf("%d\n", sum[y]);
    }
    merge(x, y);
//    for (int i = 1; i <= tot; i++) {
//    printf("%d : ls = %d, rs = %d, or0 = %d, or1 = %d, tag = %d, sum = %d\n", i, ls[i], rs[i], or0[i], or1[i], tag[i], sum[i]);
//  }
  }
  return 0;
} 
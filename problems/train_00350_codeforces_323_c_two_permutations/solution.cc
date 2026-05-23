#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
struct tnode {
  int sum;
  tnode *lson, *rson;
  tnode(int x = 0) {
    sum = x;
    lson = rson = NULL;
  }
};
void pushup(tnode* cur) {
  cur->sum = (cur->lson == NULL ? 0 : cur->lson->sum) +
             (cur->rson == NULL ? 0 : cur->rson->sum);
}
tnode* modify(tnode* cur, int id, int val, int cl = 0, int cr = 1048575) {
  if (cl == cr) return new tnode(val);
  int mid = (cl + cr) >> 1;
  tnode* ret = new tnode();
  tnode *ls = cur == NULL ? NULL : cur->lson,
        *rs = cur == NULL ? NULL : cur->rson;
  ret->lson = id <= mid ? modify(ls, id, val, cl, mid) : ls;
  ret->rson = id > mid ? modify(rs, id, val, mid + 1, cr) : rs;
  pushup(ret);
  return ret;
}
int query(tnode* cur, int l, int r, int cl = 0, int cr = 1048575) {
  if (cur == NULL) return 0;
  if (l == cl && r == cr) return cur->sum;
  int mid = (cl + cr) >> 1;
  if (r <= mid)
    return query(cur->lson, l, r, cl, mid);
  else if (l > mid)
    return query(cur->rson, l, r, mid + 1, cr);
  else
    return query(cur->lson, l, mid, cl, mid) +
           query(cur->rson, mid + 1, r, mid + 1, cr);
}
int n, q, p0[1000005], occ[1000005], p1[1000005];
tnode* tre[1000005];
int x;
int f(int z) { return (z - 1 + x) % n + 1; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= (int)(n); i++) {
    scanf("%d", &p0[i]);
    occ[p0[i]] = i;
  }
  for (int i = 1; i <= (int)(n); i++) scanf("%d", &p1[i]);
  for (int i = 1; i <= (int)(n); i++)
    tre[i] = modify(tre[i - 1], occ[p1[i]], 1);
  scanf("%d", &q);
  x = 0;
  for (int i = 0; i < (int)(q); i++) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    a = f(a);
    b = f(b);
    c = f(c);
    d = f(d);
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
    x = query(tre[d], a, b) - query(tre[c - 1], a, b) + 1;
    printf("%d\n", x - 1);
  }
  return 0;
}

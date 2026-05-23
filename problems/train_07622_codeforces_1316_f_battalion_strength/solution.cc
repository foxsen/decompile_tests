#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
long long p2[300005];
long long f_pow(long long a, long long b) {
  long long res = 1, temp = a;
  while (b) {
    if (b & 1) res = res * temp % mod;
    temp = temp * temp % mod;
    b >>= 1;
  }
  return res;
}
struct treap {
  treap *l, *r;
  int Size;
  long long val;
  long long val2;
  long long k;
  treap(int _k) : k(_k), l(NULL), r(NULL), Size(1), val(_k), val2(_k) {}
} * root;
long long val(treap *t) { return t ? t->val : 0; }
long long val2(treap *t) { return t ? t->val2 : 0; }
int Size(treap *t) { return t ? t->Size : 0; }
void pull(treap *t) {
  t->val = val(t->r) * p2[Size(t->l) + 1] + t->k * p2[Size(t->l)] + val(t->l);
  t->val %= mod;
  t->val2 =
      val2(t->l) * p2[Size(t->r) + 1] + t->k * p2[Size(t->r)] + val2(t->r);
  t->val2 %= mod;
  t->Size = Size(t->l) + 1 + Size(t->r);
}
treap *merge(treap *l, treap *r) {
  if (!l || !r) return l ? l : r;
  if (rand() % (Size(l) + Size(r)) < Size(l)) {
    l->r = merge(l->r, r);
    pull(l);
    return l;
  } else {
    r->l = merge(l, r->l);
    pull(r);
    return r;
  }
}
void split(treap *t, int k, treap *&l, treap *&r) {
  if (!t)
    l = r = NULL;
  else if (t->k < k) {
    l = t;
    split(t->r, k, l->r, r);
    pull(l);
  } else {
    r = t;
    split(t->l, k, l, r->l);
    pull(r);
  }
}
void split2(treap *t, int k, treap *&l, treap *&r) {
  if (!t)
    l = r = NULL;
  else if (Size(t->l) < k) {
    l = t;
    split2(t->r, k - Size(t->l) - 1, l->r, r);
    pull(l);
  } else {
    r = t;
    split2(t->l, k, l, r->l);
    pull(r);
  }
}
long long ans = 0;
void msplit(treap *t, int k, treap *&l, treap *&r, int tag = 0) {
  if (tag) {
    split2(t, k, l, r);
  } else
    split(t, k, l, r);
  ans -= val2(l) * val(r) % mod * p2[1] % mod;
  ans = (ans % mod + mod) % mod;
}
treap *mmerge(treap *l, treap *r) {
  ans += val2(l) * val(r) % mod * p2[1] % mod;
  ans %= mod;
  return merge(l, r);
}
int a[300005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 300005; i++) {
    p2[i] = f_pow(f_pow(2, i), mod - 2);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    treap *t = new treap(a[i]);
    treap *l, *r;
    msplit(root, a[i], l, r);
    root = mmerge(mmerge(l, t), r);
    ans = (ans % mod + mod) % mod;
  }
  printf("%lld\n", ans * p2[1] % mod);
  int q;
  scanf("%d", &q);
  while (q--) {
    int i, first;
    scanf("%d %d", &i, &first);
    treap *l, *mid, *r;
    msplit(root, a[i], l, mid);
    msplit(mid, 1, mid, r, 1);
    a[i] = first;
    mid = new treap(first);
    root = mmerge(l, r);
    msplit(root, a[i], l, r);
    root = mmerge(mmerge(l, mid), r);
    printf("%lld\n", ans * p2[1] % mod);
  }
}

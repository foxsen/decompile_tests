#include <bits/stdc++.h>
namespace treap {
struct Treap {
  Treap *l, *r;
  int pri, size, data;
  Treap(int d) : l(), r(), pri(std::rand()), size(1), data(d) {}
};
int size(Treap* t) { return t ? t->size : 0; }
void pull(Treap* t) { t->size = size(t->l) + size(t->r) + 1; }
Treap* merge(Treap* a, Treap* b) {
  if (!a) return b;
  if (!b) return a;
  if (a->pri > b->pri) {
    a->r = merge(a->r, b);
    pull(a);
    return a;
  } else {
    b->l = merge(a, b->l);
    pull(b);
    return b;
  }
}
void split(Treap* t, int k, Treap*& a, Treap*& b) {
  if (!t)
    a = b = 0;
  else if (size(t->l) <= k) {
    a = t;
    split(t->r, k - size(t->l) - 1, a->r, b);
    pull(a);
  } else {
    b = t;
    split(t->l, k, a, b->l);
    pull(b);
  }
}
Treap* remove(Treap* t, int k) {
  Treap *a, *b, *c, *d;
  split(t, k - 1, a, b);
  split(b, k - size(a), c, d);
  return merge(a, d);
}
Treap* kth(Treap* t, int k) {
  if (k < size(t->l))
    return kth(t->l, k);
  else if (k == size(t->l))
    return t;
  else
    return kth(t->r, k - size(t->l) - 1);
}
}  // namespace treap
const int maxn = 1000000;
int val[maxn];
bool used[maxn];
using namespace treap;
int main() {
  std::srand(std::time(0));
  int n, m;
  std::scanf("%d%d", &n, &m);
  Treap* treap = new Treap(0);
  for (int i = 1; i < n; i++) treap = merge(treap, new Treap(i));
  std::fill_n(val, n, -1);
  for (int i = 0; i < m; i++) {
    int x, y;
    std::scanf("%d%d", &x, &y);
    x--;
    y--;
    int opos = kth(treap, y)->data;
    int fndval = val[opos];
    if (fndval != -1 && fndval != x) {
      std::puts("-1");
      return 0;
    }
    if (fndval == -1) {
      if (used[x]) {
        std::puts("-1");
        return 0;
      } else {
        used[x] = true;
        val[opos] = x;
      }
    }
    treap = remove(treap, y);
    treap = merge(new Treap(opos), treap);
  }
  for (int i = 0, j = 0; i < n; i++) {
    int fnd = val[i];
    if (fnd == -1) {
      while (used[j]) j++;
      used[j] = true;
      fnd = j;
    }
    std::printf("%d%c", fnd + 1, i == n - 1 ? '\n' : ' ');
  }
}

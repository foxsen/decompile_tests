#include <bits/stdc++.h>
using namespace std;
int intcmp(const void *v1, const void *v2) { return *(int *)v1 - *(int *)v2; }
int q;
map<int, int> fa, faxor;
int find_fa(int v) {
  if (v != fa[v]) {
    int newfa = find_fa(fa[v]);
    faxor[v] ^= faxor[fa[v]];
    fa[v] = newfa;
  }
  return fa[v];
}
int main() {
  scanf("%d", &q);
  int last = 0;
  while (q--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int l, r, x;
      scanf("%d %d %d", &l, &r, &x);
      l ^= last;
      r ^= last;
      x ^= last;
      if (l > r) swap(l, r);
      r++;
      if (fa.count(l) == 0) fa[l] = l, faxor[l] = 0;
      if (fa.count(r) == 0) fa[r] = r, faxor[r] = 0;
      int lroot = find_fa(l);
      int rroot = find_fa(r);
      if (lroot != rroot) {
        fa[lroot] = rroot;
        faxor[lroot] = faxor[l] ^ faxor[r] ^ x;
      }
    } else if (t == 2) {
      int l, r;
      scanf("%d %d", &l, &r);
      l ^= last;
      r ^= last;
      if (l > r) swap(l, r);
      r++;
      if (fa.count(l) == 0 || fa.count(r) == 0) {
        printf("-1\n");
        last = 1;
        continue;
      }
      int lroot = find_fa(l);
      int rroot = find_fa(r);
      if (lroot != rroot) {
        printf("-1\n");
        last = 1;
        continue;
      } else {
        last = faxor[l] ^ faxor[r];
        printf("%d\n", last);
      }
    }
  }
  return 0;
}

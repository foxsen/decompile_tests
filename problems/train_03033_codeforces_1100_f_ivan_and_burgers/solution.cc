#include <bits/stdc++.h>
using namespace std;
int b[500005], ans[500005];
struct Base {
  int a[23], pos[23];
  Base() {
    for (int i = 0; i < 23; i++) a[i] = 0;
  }
  void up(int &a, int b) {
    if (b > a) a = b;
  }
  void ins(int x, int r) {
    for (int i = 22; ~i; i--)
      if (x >> i & 1) {
        if (a[i]) {
          if (pos[i] < r) {
            swap(pos[i], r);
            swap(a[i], x);
          }
          x ^= a[i];
        } else {
          a[i] = x;
          pos[i] = r;
          break;
        }
      }
  }
  int ask(int r) {
    int t = 0;
    for (int i = 22; ~i; i--)
      if (pos[i] >= r) up(t, t ^ a[i]);
    return t;
  }
} f;
struct node {
  int l, r, idx;
  bool operator<(const node &a) const {
    if (r == a.r) return l < a.l;
    return r < a.r;
  }
} e[500005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &e[i].l, &e[i].r);
    e[i].idx = i;
  }
  sort(e + 1, e + 1 + q);
  int r = 0;
  for (int i = 1; i <= q; i++) {
    while (r < n && r < e[i].r) {
      r++;
      f.ins(b[r], r);
    }
    ans[e[i].idx] = f.ask(e[i].l);
  }
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
  return 0;
}

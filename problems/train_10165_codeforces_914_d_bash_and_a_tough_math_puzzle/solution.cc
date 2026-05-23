#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int a[maxn], t[maxn << 2], ans = 0;
int gcd(int a, int b) {
  if (b > a) swap(a, b);
  if (b)
    return gcd(b, a % b);
  else
    return a;
}
void pushup(int rt) { t[rt] = gcd(t[rt << 1], t[rt << 1 | 1]); }
void build(int rt, int l, int r) {
  if (l == r) {
    t[rt] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(rt << 1, l, mid);
  build(rt << 1 | 1, mid + 1, r);
  pushup(rt);
  return;
}
void update(int rt, int l, int r, int x, int y) {
  if (l == r) {
    t[rt] = y;
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    update(rt << 1, l, mid, x, y);
  else
    update(rt << 1 | 1, mid + 1, r, x, y);
  pushup(rt);
  return;
}
void query(int rt, int l, int r, int ql, int qr, int v) {
  if (ans > 1) return;
  if (l == r) {
    ans++;
    return;
  }
  int mid = (l + r) >> 1;
  if (ql <= mid && t[rt << 1] % v) query(rt << 1, l, mid, ql, qr, v);
  if (qr > mid && t[rt << 1 | 1] % v) query(rt << 1 | 1, mid + 1, r, ql, qr, v);
  return;
}
int main() {
  int n, q;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  build(1, 1, n);
  scanf("%d", &q);
  int now;
  int x, y, z;
  while (q--) {
    scanf("%d", &now);
    if (now == 1) {
      scanf("%d%d%d", &x, &y, &z);
      ans = 0;
      query(1, 1, n, x, y, z);
      if (ans > 1)
        printf("NO\n");
      else
        printf("YES\n");
    } else if (now == 2) {
      scanf("%d%d", &x, &y);
      update(1, 1, n, x, y);
    }
  }
  return 0;
}

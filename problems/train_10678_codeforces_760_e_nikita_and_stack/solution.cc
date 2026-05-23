#include <bits/stdc++.h>
using namespace std;
int getint() {
  int f = 1, x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return f * x;
}
struct node {
  long long x, y;
  int l, r;
} tr[212345 << 2];
void pushup(int i) {
  int lx = tr[(i << 1)].x, ly = tr[(i << 1)].y, rx = tr[(i << 1 | 1)].x,
      ry = tr[(i << 1 | 1)].y;
  int t = min(ly, rx);
  int x = lx + rx - t;
  int y = ry + ly - t;
  tr[i].x = x;
  tr[i].y = y;
  return;
}
void build(int i, int l, int r) {
  tr[i].l = l;
  tr[i].r = r;
  tr[i].x = tr[i].y = 0;
  if (l == r) {
    return;
  }
  int mid = (l + r) >> 1;
  build((i << 1), l, (mid));
  build((i << 1 | 1), (mid + 1), r);
  return;
}
int op[212345];
int w[212345];
void modify(int i, int id) {
  int l = tr[i].l, r = tr[i].r;
  if (l == r) {
    if (op[id])
      tr[i].y = 1;
    else
      tr[i].x = 1;
    return;
  }
  int mid = (l + r) >> 1;
  if (id <= (mid))
    modify((i << 1), id);
  else
    modify((i << 1 | 1), id);
  pushup(i);
  return;
}
int query(int i, int x) {
  int l = tr[i].l, r = tr[i].r;
  if (tr[i].y <= x) return 0;
  if (l == r) return l;
  if (tr[(i << 1 | 1)].y && tr[(i << 1 | 1)].y > x)
    return query((i << 1 | 1), x);
  else
    return query((i << 1), x - tr[(i << 1 | 1)].y + tr[(i << 1 | 1)].x);
}
int main() {
  int n = getint();
  build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    int id = getint();
    op[id] = getint();
    if (op[id]) w[id] = getint();
    modify(1, id);
    id = query(1, 0);
    if (op[id] == 0)
      printf("-1\n");
    else
      printf("%d\n", w[id]);
  }
  return 0;
}

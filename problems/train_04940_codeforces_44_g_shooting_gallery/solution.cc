#include <bits/stdc++.h>
using namespace std;
struct node {
  int l, r, u, d, z, id;
} a[3001000];
int tr[3001000][2], cnt, pri[3001000], minn[3001000], x[3001000], y[3001000],
    root[3001000], ex[3001000], excnt, size, i, n, m, ans[3001000],
    anss[3001000];
pair<int, int> v[3001000];
bool cmp(node x, node y) { return x.z < y.z; }
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x;
}
void init() {
  sort(ex + 1, ex + 1 + excnt);
  size = unique(ex + 1, ex + 1 + excnt) - ex - 1;
  for (i = 1; i <= n; i++) x[i] = lower_bound(ex + 1, ex + 1 + size, x[i]) - ex;
  for (i = 1; i <= m; i++) {
    a[i].l = lower_bound(ex + 1, ex + 1 + size, a[i].l) - ex;
    a[i].r = lower_bound(ex + 1, ex + 1 + size, a[i].r) - ex;
  }
}
int point(int a, int b) {
  int o = ++cnt;
  pri[o] = rand();
  v[o] = make_pair(a, b);
  minn[o] = b;
  return o;
}
void pushup(int rt) {
  minn[rt] = min(min(tr[rt][0] ? minn[tr[rt][0]] : 100000000,
                     tr[rt][1] ? minn[tr[rt][1]] : 100000000),
                 v[rt].second);
}
void split(int rt, pair<int, int> k, int &x, int &y) {
  if (rt == 0) {
    x = 0, y = 0;
    return;
  }
  if (v[rt] <= k)
    x = rt, split(tr[rt][1], k, tr[x][1], y);
  else
    y = rt, split(tr[rt][0], k, x, tr[y][0]);
  pushup(rt);
}
int merge(int x, int y) {
  if (x == 0 || y == 0) return x + y;
  if (pri[x] < pri[y]) {
    tr[x][1] = merge(tr[x][1], y);
    pushup(x);
    return x;
  } else {
    tr[y][0] = merge(x, tr[y][0]);
    pushup(y);
    return y;
  }
}
void add(int rt, int id) {
  int a, c, b = point(y[id], id);
  split(root[rt], make_pair(y[id], id - 1), a, c);
  root[rt] = merge(merge(a, b), c);
}
void del(int rt, int id) {
  int a, b, c;
  split(root[rt], make_pair(y[id], id - 1), a, c);
  split(c, make_pair(y[id], id), b, c);
  root[rt] = merge(a, c);
}
int calc(int rt, int l, int r) {
  int a, b, c;
  split(root[rt], make_pair(l - 1, 100000000), a, c);
  split(c, make_pair(r, 100000000), b, c);
  int ret = (b == 0) ? 100000000 : minn[b];
  root[rt] = merge(merge(a, b), c);
  return ret;
}
void modify(int rt, int l, int r, int x, int id, int f) {
  if (f == 1)
    add(rt, id);
  else
    del(rt, id);
  if (l == r) return;
  if (x <= ((l + r) / 2))
    modify((rt << 1), l, ((l + r) / 2), x, id, f);
  else
    modify((rt << 1 | 1), ((l + r) / 2) + 1, r, x, id, f);
}
void query(int rt, int l, int r, int x, int y, int id) {
  if (x <= l && r <= y) {
    int tmp = calc(rt, a[id].d, a[id].u);
    ans[a[id].id] = min(ans[a[id].id], tmp);
    return;
  }
  if (x <= ((l + r) / 2)) query((rt << 1), l, ((l + r) / 2), x, y, id);
  if (y >= ((l + r) / 2) + 1)
    query((rt << 1 | 1), ((l + r) / 2) + 1, r, x, y, id);
}
int main() {
  srand(20010425);
  scanf("%d", &m);
  for (i = 1; i <= m; i++) {
    a[i].l = read();
    a[i].r = read(), a[i].d = read(), a[i].u = read(), a[i].z = read();
    a[i].id = i;
    ex[++excnt] = a[i].l, ex[++excnt] = a[i].r;
    ans[i] = 100000000;
  }
  sort(a + 1, a + 1 + m, cmp);
  scanf("%d", &n);
  for (i = 1; i <= n; i++) x[i] = read(), y[i] = read(), ex[++excnt] = x[i];
  init();
  for (i = 1; i <= n; i++) modify(1, 1, size, x[i], i, 1);
  for (i = 1; i <= m; i++) {
    query(1, 1, size, a[i].l, a[i].r, i);
    if (ans[a[i].id] == 100000000) continue;
    modify(1, 1, size, x[ans[a[i].id]], ans[a[i].id], -1);
  }
  for (i = 1; i <= m; i++)
    if (ans[i] != 100000000) anss[ans[i]] = i;
  for (i = 1; i <= n; i++) printf("%d\n", anss[i]);
}

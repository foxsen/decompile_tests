#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int dfn[200010], low[200010], total;
int size[200010], son[200010], top[200010], dep[200010], fa[200010],
    tag[200010], oppo[200010], quantity;
int w[200010 << 1];
stack<int> s;
int amount;
multiset<int> val[200010];
struct data {
  int next, to;
  data(int next = 0, int to = 0) : next(next), to(to) {}
};
struct segment {
  int l, r, val;
} t[200010 << 2];
struct graph {
  int head[200010], cnt;
  data link[200010 << 2];
  void connect(int u, int v) {
    link[++cnt] = data(head[u], v);
    head[u] = cnt;
  }
} origin, circle;
int read() {
  char c = getchar();
  int x = 0;
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - '0';
    c = getchar();
  }
  return x;
}
void tarjan(int u) {
  dfn[u] = low[u] = ++total;
  s.push(u);
  for (int i = origin.head[u]; i; i = origin.link[i].next) {
    int v = origin.link[i].to;
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
      if (low[v] >= dfn[u]) {
        ++amount;
        int k;
        circle.connect(amount, u);
        circle.connect(u, amount);
        do {
          k = s.top();
          s.pop();
          circle.connect(k, amount);
          circle.connect(amount, k);
        } while (k != v);
      }
    } else
      low[u] = min(low[u], dfn[v]);
  }
}
void DFS1(int u, int pre) {
  dep[u] = dep[pre] + 1;
  size[u] = 1;
  fa[u] = pre;
  for (int i = circle.head[u]; i; i = circle.link[i].next) {
    int v = circle.link[i].to;
    if (v == pre) continue;
    DFS1(v, u);
    size[u] += size[v];
    if (size[v] > size[son[u]]) son[u] = v;
  }
}
void DFS2(int u, int pre) {
  tag[u] = ++quantity;
  oppo[quantity] = u;
  top[u] = pre;
  if (!son[u]) return;
  DFS2(son[u], pre);
  for (int i = circle.head[u]; i; i = circle.link[i].next) {
    int v = circle.link[i].to;
    if (v == fa[u] || v == son[u]) continue;
    DFS2(v, v);
  }
}
void pushup(int x) { t[x].val = min(t[x << 1].val, t[x << 1 | 1].val); }
void build(int l, int r, int x = 1) {
  t[x].l = l;
  t[x].r = r;
  if (l == r) {
    t[x].val = w[oppo[l]];
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, x << 1);
  build(mid + 1, r, x << 1 | 1);
  pushup(x);
}
int query(int l, int r, int x = 1) {
  if (l <= t[x].l && t[x].r <= r) return t[x].val;
  int mid = (t[x].l + t[x].r) >> 1, res = 0x3f3f3f3f;
  if (l <= mid) res = min(res, query(l, r, x << 1));
  if (r > mid) res = min(res, query(l, r, x << 1 | 1));
  return res;
}
void modify(int p, int x = 1) {
  if (t[x].l == t[x].r) {
    t[x].val = w[oppo[p]];
    return;
  }
  int mid = (t[x].l + t[x].r) >> 1;
  if (p <= mid)
    modify(p, x << 1);
  else
    modify(p, x << 1 | 1);
  pushup(x);
}
void change(int u, int s) {
  if (u != 1) {
    val[fa[u]].erase(val[fa[u]].find(w[u]));
    val[fa[u]].insert(s);
    w[fa[u]] = *val[fa[u]].begin();
    modify(tag[fa[u]]);
  }
  w[u] = s;
  modify(tag[u]);
}
int LCA(int u, int v) {
  int res = 0x3f3f3f3f;
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
    res = min(res, query(tag[top[u]], tag[u]));
    u = fa[top[u]];
  }
  if (dep[u] > dep[v]) swap(u, v);
  res = min(res, query(tag[u], tag[v]));
  if (u > n) res = min(res, w[fa[u]]);
  return res;
}
void init() {
  amount = n;
  for (int i = 1; i <= n; ++i)
    if (!dfn[i]) tarjan(i);
  DFS1(1, 0);
  DFS2(1, 0);
  for (int u = n + 1; u <= amount; ++u) {
    for (int i = circle.head[u]; i; i = circle.link[i].next) {
      int v = circle.link[i].to;
      if (v == fa[u]) continue;
      val[u].insert(w[v]);
    }
    if (val[u].empty())
      w[u] = 0x3f3f3f3f;
    else
      w[u] = *val[u].begin();
  }
  build(1, amount);
}
int main() {
  n = read();
  m = read();
  q = read();
  for (int i = 1; i <= n; ++i) w[i] = read();
  for (int i = 1; i <= m; ++i) {
    int u = read(), v = read();
    origin.connect(u, v);
    origin.connect(v, u);
  }
  init();
  while (q--) {
    char opt[4];
    scanf("%s", opt + 1);
    int a = read(), b = read();
    if (opt[1] == 'C')
      change(a, b);
    else
      printf("%d\n", LCA(a, b));
  }
}

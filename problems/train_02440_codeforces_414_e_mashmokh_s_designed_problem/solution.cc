#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char c = getchar();
  int x = 0;
  bool f = 0;
  for (; !isdigit(c); c = getchar()) f ^= !(c ^ 45);
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  if (f) x = -x;
  return x;
}
int n, m, q;
vector<int> e[200005];
int in[200005], out[200005], dep[200005], id[200005];
void dfs(int u, int d) {
  in[u] = ++m, id[m] = u, dep[m] = d;
  for (auto v : e[u]) dfs(v, d + 1);
  out[u] = ++m, id[m] = u, dep[m] = d;
}
int rt, tot;
int fa[200005], ch[200005][2], add[200005];
int sz[200005], mx[200005], mn[200005];
inline bool chk(int x) { return ch[fa[x]][1] == x; }
inline void pushup(int x) {
  int l = ch[x][0], r = ch[x][1];
  sz[x] = sz[l] + sz[r] + 1;
  mx[x] = max(dep[x], max(mx[l], mx[r]));
  mn[x] = min(dep[x], min(mn[l], mn[r]));
}
inline void pusht(int x, int v) {
  add[x] += v, mx[x] += v, mn[x] += v, dep[x] += v;
}
inline void pushdown(int x) {
  if (!add[x]) return;
  if (ch[x][0]) pusht(ch[x][0], add[x]);
  if (ch[x][1]) pusht(ch[x][1], add[x]);
  add[x] = 0;
}
inline void connect(int x, int y, int id) { fa[x] = y, ch[y][id] = x; }
inline void rotate(int x) {
  int y = fa[x], z = fa[y], k = chk(x), w = ch[x][!k];
  pushdown(y), pushdown(x);
  connect(w, y, k);
  connect(x, z, chk(y));
  connect(y, x, !k);
  pushup(y), pushup(x);
}
inline void splay(int x, int goal = 0) {
  for (int y = fa[x], z = fa[y]; fa[x] != goal; rotate(x), y = fa[x], z = fa[y])
    if (z != goal) rotate(chk(x) == chk(y) ? y : x);
  if (!goal) rt = x;
}
int build(int l, int r) {
  int mid = l + r >> 1, p = mid;
  if (l < mid) ch[p][0] = build(l, mid - 1), fa[ch[p][0]] = p;
  if (mid < r) ch[p][1] = build(mid + 1, r), fa[ch[p][1]] = p;
  return pushup(p), p;
}
int findk(int x, int k) {
  pushdown(x);
  int l = ch[x][0], r = ch[x][1];
  if (mn[r] <= k && mx[r] >= k) return findk(r, k);
  if (dep[x] == k) return splay(x), id[x];
  return findk(l, k);
}
inline int split(int l, int r) { return splay(l), splay(r, l), ch[r][0]; }
inline int pre(int x) {
  splay(x), x = ch[x][0];
  while (ch[x][1]) x = ch[x][1];
  return x;
}
inline int nxt(int x) {
  splay(x), x = ch[x][1];
  while (ch[x][0]) x = ch[x][0];
  return x;
}
inline int del(int l, int r) {
  int pl = pre(l), pr = nxt(r), x = split(pl, pr), y = fa[x];
  ch[y][0] = fa[x] = 0, pushup(y), pushup(fa[y]);
  return x;
}
void dfs(int p) {
  if (!p) return;
  pushdown(p);
  cout << dep[p] << ' ';
  dfs(ch[p][0]), dfs(ch[p][1]);
}
int main() {
  n = read(), q = read(), mn[0] = 0x3f3f3f3f;
  for (register int i = (1); i <= (n); ++i) {
    int t = read();
    while (t--) e[i].push_back(read());
  }
  dfs(1, 0), build(1, m);
  while (q--) {
    int op = read(), u, v, k, res, p;
    if (op == 1) {
      u = read(), v = read();
      res = 0;
      splay(in[u]), res += dep[in[u]];
      int rku = sz[ch[in[u]][0]] + 1;
      splay(in[v]), res += dep[in[v]];
      int rkv = sz[ch[in[v]][0]] + 1;
      if (rku > rkv) swap(u, v);
      int lca = split(in[u], out[v]);
      res -= (mn[lca] - 1) * 2;
      printf("%d\n", res);
    }
    if (op == 2) {
      u = read(), v = read();
      splay(in[u]);
      p = findk(ch[in[u]][0], dep[in[u]] - v);
      u = del(in[u], out[u]), pusht(u, -(v - 1));
      int q = pre(out[p]);
      splay(q), splay(out[p], q);
      connect(u, out[p], 0);
      pushup(out[p]), pushup(q);
    }
    if (op == 3) {
      k = read();
      splay(1), printf("%d\n", findk(1, k));
    }
  }
  return 0;
}

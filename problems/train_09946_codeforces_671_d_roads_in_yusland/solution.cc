#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool upmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
inline bool upmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
const long double eps = 1e-9;
const long double pi = acos(-1);
const int mods = 1e9 + 7;
const int oo = 1 << 30;
const long long loo = 3e14;
const int MAXN = 300005;
const int INF = 0x3f3f3f3f;
inline int read() {
  int f = 1, x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
vector<pair<int, int> > V[MAXN];
vector<int> e[MAXN];
long long tag[MAXN * 20], mn[MAXN * 20];
int ls[MAXN * 20], rs[MAXN * 20], dep[MAXN], rt[MAXN], stk[MAXN * 20],
    top = 0, nodenum = 0, n, m;
int nwnode() {
  int x = (top ? stk[top--] : ++nodenum);
  tag[x] = ls[x] = rs[x] = 0, mn[x] = loo;
  return x;
}
void del(int x) { stk[++top] = x; }
void puttag(int x, long long y) {
  if (!x) return;
  tag[x] += y, mn[x] += y;
}
void down(int x) {
  if (tag[x]) puttag(ls[x], tag[x]), puttag(rs[x], tag[x]), tag[x] = 0;
}
int insert(int x, int l, int r, int y, long long z) {
  if (!x) x = nwnode();
  upmin(mn[x], z);
  if (l == r) return x;
  down(x);
  int mid = (l + r) >> 1;
  if (y <= mid)
    ls[x] = insert(ls[x], l, mid, y, z);
  else
    rs[x] = insert(rs[x], mid + 1, r, y, z);
  return x;
}
long long query(int x, int l, int r, int L, int R) {
  if (!x) return loo;
  if (l >= L && r <= R) return mn[x];
  down(x);
  int mid = (l + r) >> 1;
  if (R <= mid)
    return query(ls[x], l, mid, L, R);
  else if (L > mid)
    return query(rs[x], mid + 1, r, L, R);
  else
    return min(query(ls[x], l, mid, L, mid),
               query(rs[x], mid + 1, r, mid + 1, R));
}
int merge(int x, int y) {
  if (!x || !y) return x | y;
  down(x), down(y);
  ls[x] = merge(ls[x], ls[y]);
  rs[x] = merge(rs[x], rs[y]);
  mn[x] = min(mn[x], mn[y]);
  del(y);
  return x;
}
void dfs(int x, int father) {
  dep[x] = dep[father] + 1;
  rt[x] = insert(rt[x], 1, n, dep[x], 0);
  for (auto v : e[x]) {
    if (v == father) continue;
    dfs(v, x);
    long long p = query(rt[x], 1, n, 1, dep[x]),
              q = query(rt[v], 1, n, 1, dep[x]);
    if (p != loo) puttag(rt[x], q);
    if (q != loo) puttag(rt[v], p);
    rt[x] = merge(rt[x], rt[v]);
  }
  for (auto v : V[x]) {
    long long p = query(rt[x], 1, n, 1, dep[x]);
    rt[x] = insert(rt[x], 1, n, dep[v.first], p + v.second);
  }
}
signed main() {
  n = read(), m = read();
  for (int i = 1; i < n; ++i) {
    int u = read(), v = read();
    e[u].push_back(v), e[v].push_back(u);
  }
  for (int i = 1; i <= m; ++i) {
    int u = read(), v = read(), c = read();
    V[u].push_back(make_pair(v, c));
  }
  dfs(1, 0);
  long long ans = query(rt[1], 1, n, 1, 1);
  printf("%lld\n", ans >= loo ? -1ll : ans);
  return 0;
}

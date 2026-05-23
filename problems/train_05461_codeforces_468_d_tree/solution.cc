#include <bits/stdc++.h>
using namespace std;
int n, mn[1000000], root, hson[1000000];
int timer, size[1000000], sum[1000000];
int dfn[1000000], id[1000000], gra[1000000];
long long dis[1000000];
set<pair<int, int> > s;
set<pair<int, int> >::iterator it;
int read() {
  int x = 0, k = 1;
  char c;
  c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') k = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * k;
}
struct edge {
  int cnp, to[1000000], last[1000000], head[1000000], co[1000000];
  edge() { cnp = 2; }
  void add(int u, int v, int w) {
    to[cnp] = v, co[cnp] = w, last[cnp] = head[u], head[u] = cnp++;
    to[cnp] = u, co[cnp] = w, last[cnp] = head[v], head[v] = cnp++;
  }
} E1;
void Get_root(int u, int fa) {
  size[u] = 1;
  for (int i = E1.head[u]; i; i = E1.last[i]) {
    int v = E1.to[i];
    if (v == fa) continue;
    Get_root(v, u);
    size[u] += size[v];
    hson[u] = max(hson[u], size[v]);
  }
  hson[u] = max(hson[u], n - size[u]);
  if (hson[u] < hson[root]) root = u;
}
void dfs(int u, int fa) {
  dfn[u] = ++timer;
  id[timer] = u, size[u] = 1;
  for (int i = E1.head[u]; i; i = E1.last[i]) {
    int v = E1.to[i];
    if (v == fa) continue;
    dis[v] = dis[u] + E1.co[i];
    dfs(v, u);
    size[u] += size[v];
  }
}
void Push_Up(int p) { mn[p] = min(mn[p << 1], mn[p << 1 | 1]); }
void Build(int p, int l, int r) {
  if (l == r) {
    mn[p] = id[l];
    return;
  }
  int mid = (l + r) >> 1;
  Build(p << 1, l, mid), Build(p << 1 | 1, mid + 1, r);
  Push_Up(p);
}
int Query(int p, int l, int r, int L, int R) {
  if (L <= l && R >= r) return mn[p];
  if (L > r || R < l) return 999999999;
  int mid = (l + r) >> 1;
  int t = Query(p << 1, l, mid, L, R);
  int t1 = Query(p << 1 | 1, mid + 1, r, L, R);
  return min(t, t1);
}
void Update(int p, int l, int r, int x) {
  if (l == r) {
    mn[p] = 999999999;
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    Update(p << 1, l, mid, x);
  else
    Update(p << 1 | 1, mid + 1, r, x);
  Push_Up(p);
}
void dfs2(int u, int root, int fa) {
  gra[u] = root;
  for (int i = E1.head[u]; i; i = E1.last[i]) {
    int v = E1.to[i];
    if (v == fa) continue;
    dfs2(v, root, u);
  }
}
void del(int x) {
  if (x != root) {
    int t = gra[x];
    it = s.lower_bound(make_pair(sum[t], t));
    s.erase(it);
    sum[t]--;
    s.insert(make_pair(sum[t], t));
  }
}
int main() {
  n = read();
  if (n == 1) {
    printf("0\n1\n");
    return 0;
  }
  for (int i = 1; i < n; i++) {
    int u = read(), v = read(), w = read();
    E1.add(u, v, w);
  }
  hson[root] = n + 1;
  Get_root(1, 0);
  dfs(root, 0);
  timer = 0;
  Build(1, 1, n);
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans += dis[i];
  printf("%I64d\n", ans * 2);
  for (int i = E1.head[root]; i; i = E1.last[i]) {
    int v = E1.to[i];
    sum[v] = size[v] * 2;
    dfs2(v, v, root);
    s.insert(make_pair(sum[v], v));
  }
  for (int i = 1, t = -1; i <= n; i++) {
    int res = n - i + 1;
    if (t == -1) {
      it = s.lower_bound(make_pair(res, 0));
      if (it != s.end()) t = (*it).second;
    }
    int u = 999999999, x = gra[i];
    if (t == -1) {
      if (i == root)
        u = Query(1, 1, n, 1, n);
      else {
        u = min(u, Query(1, 1, n, 1, dfn[x] - 1));
        u = min(u, Query(1, 1, n, dfn[x] + size[x], n));
      }
    } else {
      if (x == t) {
        u = min(u, Query(1, 1, n, 1, dfn[x] - 1));
        u = min(u, Query(1, 1, n, dfn[x] + size[x], n));
      } else
        u = Query(1, 1, n, dfn[t], dfn[t] + size[t] - 1);
    }
    printf("%d ", u);
    del(i);
    Update(1, 1, n, dfn[u]);
    if (i != u) del(u);
  }
  return 0;
}

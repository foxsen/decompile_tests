#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 15;
const long long inf = 1e18;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  return x * f;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
int n, q, s, t, l, r, w, p, u, v, tot;
int head[maxn << 3], cnt, tra[maxn << 3], trb[maxn << 3], in[maxn], out[maxn];
struct edge {
  int to, nxt, w;
} e[maxn << 4];
inline void add(int u, int v, int _w) {
  e[++cnt].to = v;
  e[cnt].w = _w;
  e[cnt].nxt = head[u];
  head[u] = cnt;
}
void build(int l, int r, int x) {
  tra[x] = ++tot;
  trb[x] = ++tot;
  if (l == r) {
    out[l] = trb[x];
    in[l] = tra[x];
    add(trb[x], tra[x], 0);
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, x << 1);
  build(mid + 1, r, x << 1 | 1);
  add(tra[x << 1], tra[x], 0);
  add(tra[x << 1 | 1], tra[x], 0);
  add(trb[x], trb[x << 1], 0);
  add(trb[x], trb[x << 1 | 1], 0);
}
void Updata(int l, int r, int L, int R, int x, int v, int w, int op) {
  if (l > R || r < L) return;
  if (l >= L && r <= R) {
    if (op == 2)
      add(in[v], trb[x], w);
    else
      add(tra[x], out[v], w);
    return;
  }
  int mid = (l + r) >> 1;
  Updata(l, mid, L, R, x << 1, v, w, op);
  Updata(mid + 1, r, L, R, x << 1 | 1, v, w, op);
}
long long dis[maxn << 3];
struct node {
  int x;
  long long len;
  friend bool operator<(node a, node b) { return a.len > b.len; }
};
void diskstra() {
  for (int i = 0; i <= tot; ++i) dis[i] = inf;
  dis[in[s]] = dis[out[s]] = 0;
  priority_queue<node> q;
  q.push(node{in[s], 0LL});
  while (!q.empty()) {
    node now = q.top();
    q.pop();
    if (now.len > dis[now.x]) continue;
    for (int i = head[now.x]; i; i = e[i].nxt) {
      int v = e[i].to;
      if (dis[v] > dis[now.x] + e[i].w) {
        dis[v] = dis[now.x] + e[i].w;
        q.push(node{v, dis[v]});
      }
    }
  }
}
int main() {
  n = read(), q = read(), s = read();
  build(1, n, 1);
  while (q--) {
    t = read();
    if (t == 1) {
      u = read(), v = read(), w = read();
      add(in[u], out[v], w);
    } else {
      v = read(), l = read(), r = read(), w = read();
      Updata(1, n, l, r, 1, v, w, t);
    }
  }
  diskstra();
  for (int i = 1; i <= n; ++i) {
    if (dis[out[i]] == inf)
      printf("-1 ");
    else
      write(dis[out[i]]), putchar(' ');
  }
  return 0;
}

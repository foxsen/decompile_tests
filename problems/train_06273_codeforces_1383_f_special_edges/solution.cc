#include <bits/stdc++.h>
#pragma GCC optimize(2, 3, "Ofast")
const int maxn = 1e4 + 5, maxk = 1101;
const int inf = 25;
template <typename T>
inline T min(const T &a, const T &b) {
  return a < b ? a : b;
}
struct IO {
  IO(){};
  char c;
  inline char gc() {
    static char buf[maxn], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, maxn, stdin), p1 == p2)
               ? EOF
               : *p1++;
  }
  template <typename T>
  inline IO &operator>>(T &_) {
    _ = 0;
    bool f = 1;
    c = gc();
    while (c < '0' || c > '9') {
      if (c == '-') f = 0;
      c = gc();
    }
    while (c >= '0' && c <= '9') {
      _ = _ * 10 + c - 48;
      c = gc();
    }
    if (!f) _ = -_;
    return *this;
  }
  template <typename T>
  inline IO &operator<<(T x) {
    if (!x) {
      putchar(48);
      putchar('\n');
      return *this;
    }
    static int wt[40], len;
    len = 0;
    if (x < 0) {
      putchar('-');
      x = -x;
    }
    for (; x; x /= 10) {
      wt[++len] = x % 10;
    }
    while (len) {
      putchar(wt[len--] + 48);
    }
    putchar('\n');
    return *this;
  }
} io;
struct edge {
  int v, nxt;
} e[maxn << 1];
int w[maxk][maxn << 1];
int n, m, k, q, edge_cnt = 1, fir[maxn];
int s, t, cur[maxn];
std::queue<int> Q;
int dep[maxn];
inline void add_edge(int u, int v, int W) {
  e[++edge_cnt].nxt = fir[u];
  e[edge_cnt].v = v;
  w[0][edge_cnt] = W;
  fir[u] = edge_cnt;
  e[++edge_cnt].nxt = fir[v];
  e[edge_cnt].v = u;
  w[0][edge_cnt] = 0;
  fir[v] = edge_cnt;
}
bool bfs() {
  memset(dep, 0, sizeof(dep));
  dep[s] = 1;
  Q.push(s);
  while (!Q.empty()) {
    int now = Q.front();
    Q.pop();
    cur[now] = fir[now];
    for (int i = fir[now]; i; i = e[i].nxt) {
      int v = e[i].v;
      if (w[0][i] && !dep[v]) {
        dep[v] = dep[now] + 1;
        Q.push(v);
      }
    }
  }
  return dep[t];
}
int dfs(int now, int minflow) {
  if (now == t) return minflow;
  int useflow = 0;
  for (int i = cur[now]; i && minflow; i = e[i].nxt) {
    cur[now] = i;
    int v = e[i].v;
    if (w[0][i] && dep[v] == dep[now] + 1) {
      int tmp = dfs(v, min(w[0][i], minflow));
      if (tmp == 0) dep[v] = -1;
      w[0][i] -= tmp, w[0][i ^ 1] += tmp;
      minflow -= tmp, useflow += tmp;
    }
  }
  return useflow;
}
int Dinic() {
  int maxflow = 0;
  while (bfs()) maxflow += dfs(s, inf);
  return maxflow;
}
int cut[maxk], Log[maxk];
inline int lowbit(int x) { return x & (-x); }
int fa[maxn], id[maxn];
int bfs(int idx) {
  memset(dep, 0, sizeof(dep));
  dep[s] = 1;
  Q.push(s);
  while (!Q.empty()) {
    int now = Q.front();
    Q.pop();
    for (int i = fir[now]; i; i = e[i].nxt) {
      int v = e[i].v;
      if (w[idx][i] && !dep[v]) {
        dep[v] = dep[now] + 1;
        Q.push(v);
        fa[v] = now, id[v] = i;
      }
      if (dep[t]) break;
    }
    if (dep[t])
      while (!Q.empty()) Q.pop();
  }
  if (dep[t] == 0) return 0;
  int now = t, flow = inf;
  while (now != s && now) flow = min(flow, w[idx][id[now]]), now = fa[now];
  now = t;
  while (now != s)
    w[idx][id[now]] -= flow, w[idx][id[now] ^ 1] += flow, now = fa[now];
  return flow;
}
int W[maxn], f[maxk];
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &q);
  s = 1, t = n;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    io >> u >> v >> w;
    add_edge(u, v, w);
  }
  Log[0] = 0;
  for (int i = 1; i < (1 << k); i++) Log[i] = Log[i >> 1] + 1;
  cut[0] = Dinic();
  for (int i = 1; i < (1 << k); i++) {
    for (int j = 2; j <= edge_cnt; j++) w[i][j] = w[i ^ lowbit(i)][j];
    w[i][Log[lowbit(i)] << 1] = inf;
    cut[i] = cut[i ^ lowbit(i)];
    int flow;
    while (flow = bfs(i)) cut[i] += flow;
  }
  while (q--) {
    for (int i = 1; i <= k; i++) io >> W[i];
    for (int i = 1; i < (1 << k); i++)
      f[i] = f[i ^ lowbit(i)] + W[Log[lowbit(i)]];
    int answer = 1e9 + 7;
    for (int i = 0; i < (1 << k); i++)
      answer = min(answer, f[i] + cut[((1 << k) - 1) ^ i]);
    io << answer;
  }
  return 0;
}

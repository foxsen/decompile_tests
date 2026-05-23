#include <bits/stdc++.h>
using namespace std;
int n, m, g, v[10010], s[10010], fri[2010], d[2010][11], w[2010], k[2010],
    opt[2010];
int S, T, dis[20010], ans, tim;
struct info {
  int v, c;
  unsigned r;
};
unsigned cur[20010];
vector<info> a[20010];
template <typename T>
void chkmin(T &x, T y) {
  x = min(x, y);
}
template <typename T>
void chkmax(T &x, T y) {
  x = max(x, y);
}
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
void add(int u, int v, int c) {
  a[u].push_back((info){v, c, (unsigned)a[v].size()});
  a[v].push_back((info){u, 0, (unsigned)a[u].size() - 1});
}
int bfs() {
  static int q[20010], l = 0, r = 0;
  for (int i = 0; i <= r; ++i) dis[q[i]] = 0;
  q[l = r = 0] = S, dis[S] = 1;
  while (l <= r) {
    int pos = q[l++];
    for (unsigned i = 0, si = a[pos].size(); i < si; ++i) {
      int to = a[pos][i].v, cap = a[pos][i].c;
      if (!dis[to] && cap) dis[to] = dis[pos] + 1, q[++r] = to;
    }
  }
  return (dis[T] != 0);
}
int dinic(int pos, int lim) {
  if (pos == T) return lim;
  int used = 0, tmp;
  for (unsigned &i = cur[pos], si = a[pos].size(); i < si; ++i) {
    int to = a[pos][i].v, cap = a[pos][i].c, re = a[pos][i].r;
    if (cap && dis[to] == dis[pos] + 1 &&
        (tmp = dinic(to, min(lim - used, cap)))) {
      a[pos][i].c -= tmp, a[to][re].c += tmp, used += tmp;
      if (used == lim) return used;
    }
  }
  return used;
}
int main() {
  read(n), read(m), read(g);
  for (int i = 1; i <= n; ++i) read(s[i]);
  for (int i = 1; i <= n; ++i) read(v[i]);
  for (int i = 1; i <= m; ++i) {
    read(opt[i]), read(w[i]), read(k[i]);
    ans += w[i];
    for (int j = 1; j <= k[i]; ++j) read(d[i][j]);
    read(fri[i]);
  }
  S = 0, T = tim = n + 1;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == 0)
      add(S, i, 0), add(i, T, v[i]);
    else
      add(S, i, v[i]), add(i, T, 0);
  }
  for (int i = 1; i <= m; ++i) {
    if (opt[i] == 1) {
      ++tim;
      add(S, tim, w[i] + fri[i] * g);
      for (int j = 1; j <= k[i]; ++j) add(tim, d[i][j], 0x3f3f3f3f);
    } else {
      ++tim;
      add(tim, T, w[i] + fri[i] * g);
      for (int j = 1; j <= k[i]; ++j) add(d[i][j], tim, 0x3f3f3f3f);
    }
  }
  while (bfs()) {
    memset(cur, 0, sizeof(cur));
    ans -= dinic(S, 0x3f3f3f3f);
  }
  printf("%d\n", ans);
  return 0;
}

#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
bool Finish_read;
template <class T>
inline void read(T &x) {
  Finish_read = 0;
  x = 0;
  int f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    if (ch == EOF) return;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  x *= f;
  Finish_read = 1;
}
template <class T>
inline void print(T x) {
  if (x / 10 != 0) print(x / 10);
  putchar(x % 10 + '0');
}
template <class T>
inline void writeln(T x) {
  if (x < 0) putchar('-');
  x = abs(x);
  print(x);
  putchar('\n');
}
template <class T>
inline void write(T x) {
  if (x < 0) putchar('-');
  x = abs(x);
  print(x);
}
const int maxn = 500010;
struct Edge {
  int u, v, w, id;
  inline bool operator<(const Edge &rhs) const { return w < rhs.w; }
} e[maxn];
int n, m, from[maxn], to[maxn], q, k, a[maxn], fa[maxn], ver, edg, vis[maxn];
bool can[maxn];
vector<int> G[maxn];
inline int gf(int x) { return x == fa[x] ? x : fa[x] = gf(fa[x]); }
inline void dfs(int tag, int x) {
  if (vis[x] == tag) return;
  vis[x] = tag;
  ver++;
  edg += G[x].size();
  for (int i = 0; i < G[x].size(); i++) dfs(tag, G[x][i]);
}
inline bool check(int tag, int x) {
  ver = edg = 0;
  dfs(tag, x);
  return edg == 2 * (ver - 1);
}
int main() {
  read(n);
  read(m);
  for (int i = 1; i <= m; i++) {
    read(e[i].u);
    read(e[i].v);
    read(e[i].w);
    e[i].id = i;
    from[i] = e[i].u;
    to[i] = e[i].v;
  }
  for (int i = 1; i <= n; i++) fa[i] = i;
  sort(e + 1, e + m + 1);
  for (int i = 1; i <= m; i++) {
    int pos = i;
    while (e[pos].w == e[i].w && pos <= m) {
      int u = gf(e[pos].u), v = gf(e[pos].v);
      from[e[pos].id] = u;
      to[e[pos].id] = v;
      can[e[pos].id] = u != v;
      pos++;
    }
    for (; i < pos; i++) fa[gf(e[i].u)] = gf(e[i].v);
    i--;
  }
  read(q);
  for (int c = 1; c <= q; c++) {
    read(k);
    bool yes = 1;
    for (int i = 1; i <= k; i++) {
      read(a[i]);
      if (!can[a[i]]) yes = 0;
      G[from[a[i]]].clear();
      G[to[a[i]]].clear();
    }
    for (int i = 1; i <= k; i++) {
      G[from[a[i]]].push_back(to[a[i]]);
      G[to[a[i]]].push_back(from[a[i]]);
    }
    for (int i = 1; i <= k; i++) {
      int x = from[a[i]], y = to[a[i]];
      if (vis[x] != c) yes &= check(c, x);
      if (vis[y] != c) yes &= check(c, y);
    }
    puts(yes ? "YES" : "NO");
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  register long long x = 0, f = 1;
  register char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  return x * f;
}
struct Edge {
  long long to, nxt, type;
  Edge() {}
  Edge(long long to, long long nxt, long long type)
      : to(to), nxt(nxt), type(type) {}
} edge[100099 * 2];
long long first[100099], nume;
void Addedge(long long a, long long b, long long c) {
  edge[nume] = Edge(b, first[a], c);
  first[a] = nume++;
}
long long fa[100099], son[100099], size[100099], up[100099], down[100099],
    top[100099], n;
long long deep[100099];
long long Pow[1000009];
void dfs1(long long u, long long f) {
  size[u] = 1;
  son[u] = 0;
  for (long long e = first[u]; ~e; e = edge[e].nxt) {
    long long v = edge[e].to;
    if (v != f) {
      deep[v] = deep[u] + 1;
      dfs1(v, u);
      size[u] += size[v];
      fa[v] = u;
      if (size[son[u]] < size[v]) son[u] = v;
    }
  }
}
void dfs2(long long u, long long chain) {
  top[u] = chain;
  if (son[u]) dfs2(son[u], chain);
  for (long long e = first[u]; ~e; e = edge[e].nxt) {
    long long v = edge[e].to;
    if (v != son[u] && v != fa[u]) dfs2(v, v);
  }
}
long long lca(long long x, long long y) {
  while (top[x] != top[y])
    if (deep[top[x]] > deep[top[y]])
      x = fa[top[x]];
    else
      y = fa[top[y]];
  return deep[x] > deep[y] ? y : x;
}
long long ans;
void dfs(long long u) {
  for (long long e = first[u]; ~e; e = edge[e].nxt) {
    long long v = edge[e].to;
    if (v == fa[u]) continue;
    dfs(v);
    if (edge[e].type == 1)
      ans = (ans + Pow[up[v]] - 1 + 1000000007) % 1000000007;
    if (edge[e].type == 2)
      ans = (ans + Pow[down[v]] - 1 + 1000000007) % 1000000007;
    up[u] += up[v];
    down[u] += down[v];
  }
}
signed main() {
  n = read();
  Pow[0] = 1;
  for (long long i = 1; i <= 1000000; i++)
    Pow[i] = 1LL * Pow[i - 1] * 2 % 1000000007;
  memset(first, -1, sizeof(first));
  nume = 0;
  for (long long i = 1; i < n; i++) {
    long long a = read(), b = read(), c = read();
    if (!c) {
      Addedge(a, b, 0);
      Addedge(b, a, 0);
    } else {
      Addedge(a, b, 1);
      Addedge(b, a, 2);
    }
  }
  size[0] = 0;
  deep[1] = 0;
  dfs1(1, 0);
  dfs2(1, 1);
  memset(up, 0, sizeof(up));
  memset(down, 0, sizeof(down));
  long long K = read();
  long long last = 1;
  for (long long i = 1; i <= K; i++) {
    long long now = read();
    long long tmp = lca(last, now);
    up[last]++;
    up[tmp]--;
    down[now]++;
    down[tmp]--;
    last = now;
  }
  ans = 0;
  dfs(1);
  printf("%I64d\n", ans);
  return 0;
}

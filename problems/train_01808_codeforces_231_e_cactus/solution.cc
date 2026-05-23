#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = 0;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return f ? x : -x;
}
const long long N = 1e5 + 5, M = 2e5 + 5, mod = 1e9 + 7;
long long tot = 1, ver[M], nxt[M], head[N];
void add(long long u, long long v) {
  ver[++tot] = v;
  nxt[tot] = head[u];
  head[u] = tot;
}
long long tot2, ver2[M], nxt2[M], head2[N];
void Add(long long u, long long v) {
  ver2[++tot2] = v;
  nxt2[tot2] = head2[u];
  head2[u] = tot2;
}
long long dfn[N], low[N], num, bridge[M];
void tarjan(long long u, long long lst) {
  dfn[u] = low[u] = ++num;
  for (long long i = head[u]; i; i = nxt[i]) {
    long long v = ver[i];
    if (!dfn[v]) {
      tarjan(v, i);
      low[u] = min(low[u], low[v]);
      if (low[v] > dfn[u]) bridge[i] = bridge[i ^ 1] = 1;
    } else if (i != (lst ^ 1))
      low[u] = min(low[u], dfn[v]);
  }
}
long long col[N], cnt[N], dcc;
void dfs1(long long u) {
  col[u] = dcc;
  cnt[dcc]++;
  for (long long i = head[u]; i; i = nxt[i]) {
    long long v = ver[i];
    if (bridge[i] || col[v]) continue;
    dfs1(v);
  }
}
long long dis[N];
void dfs2(long long u, long long fa) {
  dis[u] += (cnt[u] > 1);
  for (long long i = head2[u]; i; i = nxt2[i]) {
    long long v = ver2[i];
    if (v == fa) continue;
    dis[v] = dis[u];
    dfs2(v, u);
  }
}
long long dep[N], f[N][30], t = 20;
queue<long long> q;
void bfs(long long st) {
  q.push(st);
  dep[st] = 1;
  while (!q.empty()) {
    long long u = q.front();
    q.pop();
    for (long long i = head2[u]; i; i = nxt2[i]) {
      long long v = ver2[i];
      if (dep[v]) continue;
      dep[v] = dep[u] + 1;
      f[v][0] = u;
      for (long long j = 1; j <= t; j++) f[v][j] = f[f[v][j - 1]][j - 1];
      q.push(v);
    }
  }
}
long long lca(long long u, long long v) {
  if (dep[u] > dep[v]) swap(u, v);
  for (long long i = t; i >= 0; i--)
    if (dep[f[v][i]] >= dep[u]) v = f[v][i];
  if (u == v) return u;
  for (long long i = t; i >= 0; i--)
    if (f[u][i] != f[v][i]) {
      u = f[u][i];
      v = f[v][i];
    }
  return f[u][0];
}
long long qpow(long long a, long long x) {
  long long res = 1;
  while (x) {
    if (x & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    x >>= 1;
  }
  return res;
}
long long n, m, T;
signed main() {
  n = read(), m = read();
  for (long long i = 1; i <= m; i++) {
    long long u = read(), v = read();
    add(u, v);
    add(v, u);
  }
  tarjan(1, -1);
  for (long long i = 1; i <= n; i++) {
    if (!col[i]) {
      dcc++;
      dfs1(i);
    }
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = head[i]; j; j = nxt[j]) {
      long long v = ver[j];
      if (col[i] != col[v]) Add(col[i], col[v]);
    }
  }
  dfs2(1, -1);
  bfs(1);
  T = read();
  while (T--) {
    long long u = col[read()], v = col[read()];
    long long l = lca(u, v);
    printf("%lld\n", qpow(2, dis[u] + dis[v] - dis[l] * 2 + (cnt[l] > 1)));
  }
  return 0;
}

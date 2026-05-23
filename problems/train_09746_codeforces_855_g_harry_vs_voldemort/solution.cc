#include <bits/stdc++.h>
using namespace std;
struct edge {
  int to;
  int next;
} e[200005];
int n, tot = 0, sz[100005], dep[100005], fa[100005], last[100005], s[100005],
       f[100005];
long long ans = 0, val[100005];
int ff(int x) {
  if (f[x] == x) {
    return x;
  } else {
    return f[x] = ff(f[x]);
  }
}
void add_edge(int u, int v) {
  ++tot;
  e[tot].to = v;
  e[tot].next = last[u];
  last[u] = tot;
  return;
}
void insert_edge(int u, int v) {
  add_edge(u, v);
  add_edge(v, u);
  return;
}
void dfs(int x) {
  dep[x] = dep[fa[x]] + 1;
  sz[x] = 1;
  for (register int i = last[x]; i; i = e[i].next) {
    if (e[i].to == fa[x]) {
      continue;
    }
    fa[e[i].to] = x;
    dfs(e[i].to);
    sz[x] += sz[e[i].to];
    val[x] += 1LL * sz[e[i].to] * sz[e[i].to];
  }
  val[x] += 1LL * (n - sz[x]) * (n - sz[x]);
  ans -= val[x];
  return;
}
long long fact(int s) { return 1LL * s * (s - 1) * (s - 2); }
void merge(int x, int y) {
  ans -= 1LL * (n - s[x]) * (n - s[x]) * s[x] +
         1LL * (n - s[y]) * (n - s[y]) * s[y] - val[x] * s[x] - val[y] * s[y] +
         fact(s[x]) + fact(s[y]) + 1LL * s[x] * (s[x] - 1) * (n - s[x]) * 2 +
         1LL * s[y] * (s[y] - 1) * (n - s[y]) * 2;
  f[y] = x;
  s[x] += s[y];
  val[x] += val[y] - 1LL * sz[y] * sz[y] - 1LL * (n - sz[y]) * (n - sz[y]);
  ans += 1LL * (n - s[x]) * (n - s[x]) * s[x] - val[x] * s[x] + fact(s[x]) +
         1LL * s[x] * (s[x] - 1) * (n - s[x]) * 2;
  return;
}
int main() {
  int u, v, q, x, y;
  scanf("%d", &n);
  for (register int i = 1; i < n; ++i) {
    scanf("%d%d", &u, &v);
    insert_edge(u, v);
  }
  ans = 1LL * n * (n - 1) * (n - 1);
  dfs(1);
  printf("%lld", ans);
  for (register int i = 1; i <= n; ++i) {
    f[i] = i;
    s[i] = 1;
  }
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d", &x, &y);
    int fx = ff(x);
    int fy = ff(y);
    if (dep[fx] < dep[fy]) {
      swap(fx, fy);
    }
    while (fx != fy) {
      if (dep[fx] < dep[fy]) {
        swap(fx, fy);
      }
      merge(ff(fa[fx]), fx);
      fx = ff(fa[fx]);
    }
    printf("\n%lld", ans);
  }
}

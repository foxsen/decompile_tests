#include <bits/stdc++.h>
using namespace std;
bool vis[100008];
int tmp, head[100008], pre[100008];
struct edge {
  int u, v, nxt;
} e[100008 * 2];
struct node {
  int d, id, k;
} p[100008];
void adde(int, int);
void init(int, int);
inline int del(int, int);
bool cmp(node a, node b) { return a.d > b.d; }
int main() {
  int i, n, u, v, rt = 0, ans = 0;
  scanf("%d", &n);
  for (i = 1; i < n; ++i) {
    scanf("%d %d", &u, &v);
    adde(u, v);
    adde(v, u);
  }
  init(1, 0);
  rt = p[1].id;
  init(rt, 0);
  sort(p + 1, p + n + 1, cmp);
  tmp = 1;
  printf("1 ");
  if (n == 1) return 0;
  ans += del(p[1].k, p[1].id);
  ++tmp;
  printf("%d ", ans);
  for (i = 3; i <= n; ++i) {
    if (vis[p[i].k]) continue;
    ans += del(p[i].k, p[i].id);
    ++tmp;
    printf("%d ", ans);
  }
  while (++tmp <= n) printf("%d ", ans);
  return 0;
}
void init(int u, int fa) {
  int i, v;
  pre[u] = fa;
  p[u].k = p[u].id = u;
  p[u].d = 0;
  for (i = head[u]; i; i = e[i].nxt) {
    v = e[i].v;
    if (v == fa) continue;
    init(v, u);
    if (p[u].d < p[v].d + 1) {
      p[u].d = p[v].d + 1;
      p[u].id = p[v].id;
    }
  }
}
inline int del(int u, int v) {
  int cnt = 0;
  while (v != u) {
    ++cnt;
    vis[v] = 1;
    v = pre[v];
  }
  ++cnt;
  vis[u] = 1;
  return cnt;
}
void adde(int u, int v) {
  ++tmp;
  e[tmp].u = u;
  e[tmp].v = v;
  e[tmp].nxt = head[u];
  head[u] = tmp;
}

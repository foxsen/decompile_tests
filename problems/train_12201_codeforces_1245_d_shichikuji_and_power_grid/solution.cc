#include <bits/stdc++.h>
using namespace std;
int fa[4003];
struct node {
  long long x, y;
  long long cost, w;
} nodes[4003];
int fa_find(int a) { return fa[a] == a ? a : fa[a] = fa_find(fa[a]); }
void unite(int a, int b) {
  a = fa_find(a);
  b = fa_find(b);
  fa[a] = b;
}
struct edge {
  int f, t;
  long long w;
  void var(int _f, int _t, long long _w) {
    f = _f;
    t = _t;
    w = _w;
  }
} edges[5000000];
int cnt;
int used[4003];
void kruskal() {
  long long res = 0;
  int tol = 0;
  int num = 0;
  for (int i = 1; i <= cnt; i++) {
    if (fa_find(edges[i].f) != fa_find(edges[i].t)) {
      res += edges[i].w;
      used[++tol] = i;
      if (edges[i].f == 0) num++;
      unite(edges[i].f, edges[i].t);
    }
  }
  printf("%lld\n", res);
  printf("%d\n", num);
  for (int i = 1; i <= tol; i++) {
    int now = used[i];
    if (edges[now].f == 0) printf("%d ", edges[now].t);
  }
  printf("\n%d\n", tol - num);
  for (int i = 1; i <= tol; i++) {
    int now = used[i];
    if (edges[now].f != 0) printf("%d %d\n", edges[now].f, edges[now].t);
  }
}
void init(int n) {
  for (int i = 0; i <= n; i++) fa[i] = i;
}
long long cal(int i, int j) {
  return 1ll * (nodes[i].w + nodes[j].w) *
         (abs(nodes[i].x - nodes[j].x) + abs(nodes[i].y - nodes[j].y));
}
bool cmp(edge a, edge b) { return a.w < b.w; }
int main() {
  int n;
  scanf("%d", &n);
  init(n);
  for (int i = 1; i <= n; i++) scanf("%lld%lld", &nodes[i].x, &nodes[i].y);
  for (int i = 1; i <= n; i++) scanf("%lld", &nodes[i].cost);
  for (int i = 1; i <= n; i++) scanf("%lld", &nodes[i].w);
  cnt = 0;
  for (int i = 1; i <= n; i++) {
    edges[++cnt].var(0, i, nodes[i].cost);
  }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      edges[++cnt].var(i, j, cal(i, j));
    }
  sort(edges + 1, edges + cnt + 1, cmp);
  kruskal();
  return 0;
}

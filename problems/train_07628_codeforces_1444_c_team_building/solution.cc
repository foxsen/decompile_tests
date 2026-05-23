#include <bits/stdc++.h>
using namespace std;
typedef struct {
  int u, v, cu, cv;
} Edge;
const int N = 500010, M = 1000010;
int fa[M];
Edge e[M];
int cnt;
int sz[M];
int co[N];
int st[N];
pair<int, int> stk[M];
int top;
int n, m, k;
void init() {
  for (int i = 1; i <= n + n; i++) {
    fa[i] = i;
    sz[i] = 1;
  }
}
int cmp(Edge a, Edge b) {
  if (a.cu == b.cu) return a.cv < b.cv;
  return a.cu < b.cu;
}
int find(int x) {
  if (x == fa[x]) return x;
  return find(fa[x]);
}
void merge(int u, int v) {
  int fu = find(u), fv = find(v);
  if (sz[fu] < sz[fv]) swap(fu, fv);
  stk[++top] = {fu, fv};
  fa[fv] = fu;
  sz[fu] += sz[fv];
}
void undo() {
  pair<int, int> t = stk[top--];
  fa[t.second] = t.second;
  sz[t.first] -= sz[t.second];
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  init();
  for (int i = 1; i <= n; i++) scanf("%d", &co[i]);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (co[u] != co[v])
      e[++cnt] = {u, v, min(co[u], co[v]), max(co[u], co[v])};
    else {
      int fu = find(u), fv = find(v);
      if (fu == fv) {
        st[co[u]] = 1;
      } else {
        int fuu = find(u + n), fvv = find(v + n);
        merge(fv, fuu), merge(fu, fvv);
      }
    }
  }
  sort(e + 1, e + 1 + cnt, cmp);
  long long ans = 0;
  for (int i = 1; i <= k; i++) {
    if (!st[i]) ans++;
  }
  ans = ans * (ans - 1) / 2;
  int now = top;
  int flag = 0;
  for (int i = 1; i <= cnt; i++) {
    if (e[i].cu != e[i - 1].cu || e[i].cv != e[i - 1].cv) {
      while (now != top) undo();
      flag = 0;
    }
    if (st[e[i].cv] || st[e[i].cu]) continue;
    if (flag) continue;
    int fu = find(e[i].u), fv = find(e[i].v);
    if (fu == fv) {
      ans--;
      flag = 1;
      continue;
    } else {
      int fuu = find(e[i].u + n), fvv = find(e[i].v + n);
      merge(fu, fvv), merge(fv, fuu);
    }
  }
  printf("%lld", ans);
  return 0;
}

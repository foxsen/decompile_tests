#include <bits/stdc++.h>
const int N = 200005;
int n, k, rem;
char c[N];
int ls[N], rs[N], fa[N];
int cst[N];
int from[N];
bool vis[N], coled[N];
void dfs(int x, int &tt) {
  if (!x) return;
  dfs(ls[x], tt), from[++tt] = x, dfs(rs[x], tt);
  return;
}
inline void add(int x) {
  for (int i = 1; x; x = ls[x], ++i) cst[x] = i;
  return;
}
inline void col(int x) {
  while (x && !coled[x]) {
    --rem;
    add(rs[x]);
    coled[x] = 1;
    x = fa[x];
  }
  return;
}
int main(void) {
  scanf("%d%d%s", &n, &k, c + 1), rem = k;
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", ls + i, rs + i);
    if (ls[i]) fa[ls[i]] = i;
    if (rs[i]) fa[rs[i]] = i;
  }
  int tt = 0;
  dfs(1, tt);
  vis[n] = 0;
  for (int i = n - 1; i >= 1; --i)
    if (c[from[i]] < c[from[i + 1]] ||
        (c[from[i]] == c[from[i + 1]] && vis[i + 1]))
      vis[i] = 1;
  add(1);
  for (int i = 1; i <= n; ++i) {
    if (coled[from[i]]) continue;
    if (cst[from[i]] != 0 && cst[from[i]] <= rem && vis[i]) col(from[i]);
  }
  for (int i = 1; i <= n; ++i) {
    putchar(c[from[i]]);
    if (coled[from[i]]) putchar(c[from[i]]);
  }
  putchar('\n');
  return 0;
}

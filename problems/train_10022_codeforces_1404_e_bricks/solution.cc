#include <bits/stdc++.h>
using namespace std;
int n, m;
int fi[80004], ne[80004 << 4], to[80004 << 4], c[80004 << 4], num = 1;
void add(int x, int y, int z) {
  ne[++num] = fi[x];
  fi[x] = num;
  to[num] = y;
  c[num] = z;
  ne[++num] = fi[y];
  fi[y] = num;
  to[num] = x;
  c[num] = 0;
}
int dep[80004], q[80004], l, r, s, t, ans;
int cur[80004];
bool bfs() {
  l = 1;
  r = 0;
  q[++r] = s;
  for (int i = 0; i <= t; i++) dep[i] = 0, cur[i] = fi[i];
  dep[s] = 1;
  while (l <= r) {
    int k = q[l++];
    for (int i = fi[k]; i; i = ne[i])
      if (c[i] && !dep[to[i]]) {
        dep[to[i]] = dep[k] + 1;
        q[++r] = to[i];
      }
  }
  return dep[t] != 0;
}
int dfs(int k, int fl) {
  if (k == t) {
    ans += fl;
    return fl;
  }
  int us = 0, fx;
  for (int i = cur[k]; i; i = ne[i]) {
    cur[k] = i;
    if (dep[to[i]] == dep[k] + 1 && c[i]) {
      if (fx = dfs(to[i], min(fl - us, c[i]))) {
        us += fx;
        c[i] -= fx;
        c[i ^ 1] += fx;
        if (us == fl) break;
      }
    }
  }
  return us;
}
void dinic() {
  while (bfs()) dfs(s, 0x3f3f3f3f);
}
int sum, cnt, v[80004];
char ss[202][202];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", ss[i] + 1);
  s = 0;
  t = n * m * 2 + 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (ss[i][j] == '#') {
        sum++;
        int uu = (i - 1) * m + j, rr = uu + n * m, dd = i * m + j, ll = rr - 1;
        if (ss[i - 1][j] == '#' && !v[uu]) ++cnt, v[uu] = 1, add(s, uu, 1);
        if (ss[i][j - 1] == '#' && !v[ll]) ++cnt, v[ll] = 1, add(ll, t, 1);
        if (ss[i - 1][j] == '#') {
          if (ss[i][j + 1] == '#') add(uu, rr, 1);
          if (ss[i][j - 1] == '#') add(uu, ll, 1);
        }
        if (ss[i + 1][j] == '#') {
          if (ss[i][j + 1] == '#') add(dd, rr, 1);
          if (ss[i][j - 1] == '#') add(dd, ll, 1);
        }
      }
  dinic();
  printf("%d", sum - (cnt - ans));
  return 0;
}

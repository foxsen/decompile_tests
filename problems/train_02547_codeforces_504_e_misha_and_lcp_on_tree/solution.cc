#include <bits/stdc++.h>
using namespace std;
int n, head[300300], nxt[300300 << 1], to[300300 << 1], fa[300300][22],
    dp[300300];
void add_edge(int x, int y, int id) {
  nxt[id] = head[x], head[x] = id;
  to[id] = y;
}
void dfs(int x, int p = 0) {
  fa[x][0] = p;
  for (int i = 1; i <= 31 - __builtin_clz(n); i++)
    fa[x][i] = fa[fa[x][i - 1]][i - 1];
  for (int i = head[x]; i; i = nxt[i]) {
    int y = to[i];
    if (y == p) continue;
    dp[y] = dp[x] + 1;
    dfs(y, x);
  }
}
int anc(int x, int d) {
  if (!d) return x;
  for (int i = 31 - __builtin_clz(d); i >= 0; i--)
    if (d & (1 << i)) x = fa[x][i];
  return x;
}
int lca(int x, int y) {
  if (dp[x] > dp[y])
    x = anc(x, dp[x] - dp[y]);
  else if (dp[y] > dp[x])
    y = anc(y, dp[y] - dp[x]);
  if (x == y) return x;
  for (int i = 31 - __builtin_clz(dp[x]); i >= 0; i--) {
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  }
  return fa[x][0];
}
int rnk[300300 << 1][22], ord[300300 << 1], dro[300300 << 1], cnt[300300 << 1];
int prf[300300 << 1], suf[300300 << 1];
void build(char *s) {
  int m = 2 * n, p = 256;
  for (int i = 1; i <= n; i++) rnk[i][0] = rnk[i + n][0] = s[i];
  for (int j = 1; j <= 31 - __builtin_clz(n); j++) {
    for (int i = 1; i <= n; i++) {
      int pa = fa[i][j - 1];
      prf[i] = rnk[i][j - 1], suf[i] = rnk[pa][j - 1];
      prf[i + n] = rnk[pa ? pa + n : pa][j - 1], suf[i + n] = rnk[i + n][j - 1];
    }
    for (int i = 0; i <= p; i++) cnt[i] = 0;
    for (int i = 1; i <= m; i++) cnt[suf[i]]++;
    for (int i = 1; i <= p; i++) cnt[i] += cnt[i - 1];
    for (int i = 1; i <= m; i++) dro[cnt[suf[i]]--] = i;
    for (int i = 0; i <= p; i++) cnt[i] = 0;
    for (int i = 1; i <= m; i++) cnt[prf[i]]++;
    for (int i = 1; i <= p; i++) cnt[i] += cnt[i - 1];
    for (int i = m; i >= 1; i--) ord[cnt[prf[dro[i]]]--] = dro[i];
    p = 0;
    for (int i = 1; i <= m; i++) {
      if (prf[ord[i]] != prf[ord[i - 1]] || suf[ord[i]] != suf[ord[i - 1]]) p++;
      rnk[ord[i]][j] = p;
    }
  }
}
int lcp(int x, int y, int d) {
  if (!d) return 0;
  int rlt = 0;
  for (int i = 31 - __builtin_clz(d); i >= 0; i--) {
    if (rlt + (1 << i) > d) continue;
    int xx = x <= n ? x : anc(x - n, d - rlt - (1 << i)) + n;
    int yy = y <= n ? y : anc(y - n, d - rlt - (1 << i)) + n;
    if (rnk[xx][i] == rnk[yy][i]) {
      rlt += 1 << i;
      if (x <= n) x = fa[x][i];
      if (y <= n) y = fa[y][i];
    }
  }
  return rlt;
}
int query(int a, int b, int c, int d) {
  int ab = lca(a, b), cd = lca(c, d);
  if (dp[a] - dp[ab] < dp[c] - dp[cd]) {
    a ^= c ^= a ^= c;
    b ^= d ^= b ^= d;
    ab ^= cd ^= ab ^= cd;
  }
  int del = dp[c] - dp[cd];
  int rlt = lcp(a, c, del);
  if (rlt < del) return rlt;
  a = anc(a, del);
  int d1 = dp[a] - dp[ab] + 1, d2 = dp[d] - dp[cd] + 1;
  if (d1 >= d2) return rlt + lcp(a, d + n, d2);
  int md = anc(d, d2 - d1);
  int add = lcp(a, md + n, d1);
  rlt += add;
  if (add < d1) return rlt;
  d1 = dp[b] - dp[ab], d2 = dp[d] - dp[md];
  if (d1 > d2)
    b = anc(b, d1 - d2);
  else
    d = anc(d, d2 - d1);
  return rlt + lcp(b + n, d + n, min(d1, d2));
}
char s[300300];
int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    add_edge(x, y, i);
    add_edge(y, x, i + n);
  }
  dfs(1);
  build(s);
  int q, a, b, c, d;
  scanf("%d", &q);
  while (q--) {
    scanf("%d %d %d %d", &a, &b, &c, &d);
    printf("%d\n", query(a, b, c, d));
  }
  return 0;
}

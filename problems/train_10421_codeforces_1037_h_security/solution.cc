#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int cnt, np;
char s[N];
int ch[N][26], fa[N], l[N], rt[N], ls[N * 20], rs[N * 20], w[N], f[N], id[N];
inline int gi() {
  int x = 0, o = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch == '-' ? o = -1 : 0, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return o * x;
}
inline void insert(int c) {
  int x = np, y;
  l[np = ++cnt] = l[x] + 1;
  while (x && !ch[x][c]) ch[x][c] = np, x = fa[x];
  y = ch[x][c];
  if (!y)
    ch[x][c] = np;
  else if (l[y] == l[x] + 1)
    fa[np] = y;
  else {
    int nq = ++cnt;
    l[nq] = l[x] + 1;
    memcpy(ch[nq], ch[y], sizeof(ch[y]));
    fa[nq] = fa[y], fa[y] = fa[np] = nq;
    while (ch[x][c] == y) ch[x][c] = nq, x = fa[x];
  }
}
inline void insert(int l, int r, int p, int x, int &y) {
  y = ++cnt;
  if (l == r) return;
  ls[y] = ls[x], rs[y] = rs[x];
  int mid = (l + r) >> 1;
  if (p <= mid)
    insert(l, mid, p, ls[x], ls[y]);
  else
    insert(mid + 1, r, p, rs[x], rs[y]);
}
inline int merge(int x, int y) {
  if (!x || !y) return x | y;
  int z = ++cnt;
  ls[z] = merge(ls[x], ls[y]);
  rs[z] = merge(rs[x], rs[y]);
  return z;
}
inline bool query(int l, int r, int L, int R, int x) {
  if (!x) return 0;
  if (L <= l && r <= R) return 1;
  int mid = (l + r) >> 1;
  if (R <= mid)
    return query(l, mid, L, R, ls[x]);
  else if (L > mid)
    return query(mid + 1, r, L, R, rs[x]);
  else
    return query(l, mid, L, mid, ls[x]) | query(mid + 1, r, mid + 1, R, rs[x]);
}
int main() {
  int n, Q;
  scanf("%s%d", s + 1, &Q), n = strlen(s + 1);
  for (int i = 1; i <= n; i++) insert(s[i] - 'a'), w[np] = i;
  for (int i = 1; i <= cnt; i++) ++f[l[i]];
  for (int i = 1; i <= n; i++) f[i] += f[i - 1];
  for (int i = 1; i <= cnt; i++) id[f[l[i]]--] = i;
  for (int i = cnt; i; i--) {
    int x = id[i];
    if (w[x]) insert(1, n, w[x], rt[x], rt[x]);
    rt[fa[x]] = merge(rt[fa[x]], rt[x]);
  }
  while (Q--) {
    int l = gi(), r = gi(), m, p = 0, q = 0;
    scanf("%s", s + 1), m = strlen(s + 1) + 1;
    s[m] = 'a' - 1, m = min(m, r - l + 1);
    for (int i = 1, x = 0; i <= m; i++) {
      for (int j = s[i] - 'a' + 1; j < 26; j++)
        if (ch[x][j] && query(1, n, l + i - 1, r, rt[ch[x][j]])) {
          p = i, q = j;
          break;
        }
      if (i == m || !ch[x][s[i] - 'a']) break;
      x = ch[x][s[i] - 'a'];
    }
    s[p] = 'a' + q, s[p + 1] = '\0';
    puts(p ? s + 1 : "-1");
  }
  return 0;
}

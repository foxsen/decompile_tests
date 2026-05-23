#include <bits/stdc++.h>
const int N = 2e5 + 2;
long long dep[N];
int lj[N], nxt[N], len[N], fir[N], f[N][19], a[N], s[N];
int n, i, bs, c, x, y;
inline void read(int &x) {
  c = getchar();
  while ((c < 48) || (c > 57)) c = getchar();
  x = c ^ 48;
  c = getchar();
  while ((c >= 48) && (c <= 57)) {
    x = x * 10 + (c ^ 48);
    c = getchar();
  }
}
void dfs1(int x) {
  int i;
  for (i = 1; (i <= 18) && (f[x][i] = f[f[x][i - 1]][i - 1]); i++)
    ;
  y = x;
  for (--i; ~i; --i)
    if (dep[x] - dep[f[y][i]] <= a[x]) y = f[y][i];
  --s[f[y][0]];
  ++s[f[x][0]];
  for (i = fir[x]; i; i = nxt[i]) {
    f[lj[i]][0] = x;
    dep[lj[i]] = dep[x] + len[i];
    dfs1(lj[i]);
  }
}
void dfs2(int x) {
  int i;
  for (i = fir[x]; i; i = nxt[i]) {
    dfs2(lj[i]);
    s[x] += s[lj[i]];
  }
}
int main() {
  dep[0] = -1e18;
  read(n);
  for (i = 1; i <= n; i++) read(a[i]);
  for (i = 2; i <= n; i++) {
    read(x);
    read(y);
    lj[++bs] = i;
    len[bs] = y;
    nxt[bs] = fir[x];
    fir[x] = bs;
  }
  dfs1(1);
  dfs2(1);
  for (i = 1; i <= n; i++) printf("%d ", s[i]);
}

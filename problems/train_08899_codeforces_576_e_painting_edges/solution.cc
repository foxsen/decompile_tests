#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, M = 51;
int rd() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * w;
}
int n, m, l, q, e[N][2], qq[N][2], bq[N], nt[N], ne[N][2], co[N], nc[N], pt;
map<int, int> id[M];
int fa[N * 3], ch[N * 3][2], sz[N * 3], ti[N], mea[N * 3];
bool tg[N * 3];
bool nrt(int x) { return ch[fa[x]][0] == x || ch[fa[x]][1] == x; }
void rev(int x) {
  if (x) swap(ch[x][0], ch[x][1]), tg[x] ^= 1;
}
void psup(int x) {
  sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + (x <= m);
  mea[x] =
      ti[mea[ch[x][0]]] < ti[mea[ch[x][1]]] ? mea[ch[x][0]] : mea[ch[x][1]];
  if (x <= m) mea[x] = ti[mea[x]] < ti[x] ? mea[x] : x;
}
void rot(int x) {
  int y = fa[x], z = fa[y], yy = ch[y][1] == x, w = ch[x][!yy];
  if (nrt(y)) ch[z][ch[z][1] == y] = x;
  ch[x][!yy] = y, ch[y][yy] = w;
  if (w) fa[w] = y;
  fa[y] = x, fa[x] = z;
  psup(y);
}
void psdn(int x) {
  if (tg[x]) rev(ch[x][0]), rev(ch[x][1]), tg[x] = 0;
}
void ppush(int x) {
  if (nrt(x)) ppush(fa[x]);
  psdn(x);
}
void spl(int x) {
  ppush(x);
  while (nrt(x)) {
    int y = fa[x], z = fa[y];
    if (nrt(y)) ((ch[y][1] == x) ^ (ch[z][1] == y)) ? rot(x) : rot(y);
    rot(x);
  }
  psup(x);
}
void acs(int x) {
  for (int y = 0; x; y = x, x = fa[x]) spl(x), ch[x][1] = y, psup(x);
}
void mkrt(int x) { acs(x), spl(x), rev(x); }
int fdrt(int x) {
  acs(x), spl(x), psdn(x);
  while (ch[x][0]) x = ch[x][0], psdn(x);
  spl(x);
  return x;
}
void split(int x, int y) { mkrt(x), acs(y), spl(y); }
void link(int x, int y) { split(x, y), fa[x] = y; }
void linke(int i) {
  ne[i][0] = id[nc[i]][e[i][0]], ne[i][1] = id[nc[i]][e[i][1]];
  link(ne[i][0], i), link(ne[i][1], i);
}
void cut(int x, int y) {
  split(x, y);
  fa[x] = ch[y][0] = 0, psup(y);
}
void cute(int i) { cut(i, ne[i][0]), cut(i, ne[i][1]), nc[i] = 0; }
int main() {
  n = rd(), m = rd(), l = rd(), q = rd();
  for (int i = 1; i <= m; ++i) e[i][0] = rd(), e[i][1] = rd();
  pt = m;
  for (int i = 1; i <= q; ++i) qq[i][0] = rd(), qq[i][1] = rd();
  for (int i = 1; i <= m; ++i) bq[i] = q + 1;
  for (int i = q; i; --i) nt[i] = bq[qq[i][0]], bq[qq[i][0]] = i;
  ti[0] = 1 << 30;
  for (int i = 1; i <= q; ++i) {
    int x = qq[i][0], y = qq[i][1];
    if (nc[x]) cute(x);
    ti[x] = nt[i];
    bool fg = 0;
    if (!id[y].count(e[x][0])) fg = 1, id[y][e[x][0]] = ++pt;
    if (!id[y].count(e[x][1])) fg = 1, id[y][e[x][1]] = ++pt;
    int xx = id[y][e[x][0]], yy = id[y][e[x][1]];
    if (!fg) {
      if (fdrt(xx) != fdrt(yy))
        fg = 1;
      else {
        split(xx, yy);
        fg |= sz[yy] & 1;
      }
    }
    if (fg) {
      puts("YES");
      co[x] = y;
      if (fdrt(xx) == fdrt(yy)) {
        split(xx, yy);
        int ze = mea[yy];
        if (ti[x] <= ti[ze]) continue;
        cute(ze);
        nc[x] = y, linke(x);
      } else
        nc[x] = y, linke(x);
    } else {
      puts("NO");
      if (co[x]) {
        xx = id[co[x]][e[x][0]], yy = id[co[x]][e[x][1]];
        if (fdrt(xx) == fdrt(yy)) {
          split(xx, yy);
          int ze = mea[yy];
          if (ti[x] <= ti[ze]) continue;
          cute(ze);
          nc[x] = co[x], linke(x);
        } else
          nc[x] = co[x], linke(x);
      }
    }
  }
  return 0;
}

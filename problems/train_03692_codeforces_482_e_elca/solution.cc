#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  bool flag = false;
  while (!isdigit(c)) {
    if (c == '-') flag = true;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  if (flag) x = -x;
}
int n, m;
int f[100010], fa[100010], ch[100010][2];
long long a[100010], siz[100010], s[100010], s2[100010], ans[100010],
    val[100010], sum[100010];
char opt[3];
bool check(int x) { return ch[fa[x]][1] == x; }
bool notroot(int x) { return ch[fa[x]][0] == x || ch[fa[x]][1] == x; }
void pushup(int x) {
  int ls = ch[x][0], rs = ch[x][1];
  siz[x] = siz[ls] + siz[rs] + s[x], sum[x] = sum[ls] + sum[rs] + a[x] * s[x];
  ans[x] = ans[ls] + ans[rs] + val[x] + a[x] * (s[x] * s[x] - s2[x]) +
           2 * a[x] * siz[rs] * s[x] + 2 * sum[ls] * (siz[x] - siz[ls]);
}
void rotate(int x) {
  int y = fa[x], z = fa[y], k = check(x), w = ch[x][k ^ 1];
  if (notroot(y)) ch[z][check(y)] = x;
  ch[x][k ^ 1] = y, ch[y][k] = w;
  if (w) fa[w] = y;
  fa[x] = z, fa[y] = x;
  pushup(y), pushup(x);
}
void splay(int x) {
  for (int y; notroot(x); rotate(x))
    if (notroot(y = fa[x])) rotate(check(x) ^ check(y) ? x : y);
  pushup(x);
}
long long c(long long x) { return x * x; }
void access(int x) {
  for (int y = 0; x; y = x, x = fa[x]) {
    splay(x);
    s[x] += siz[ch[x][1]] - siz[y];
    s2[x] += c(siz[ch[x][1]]) - c(siz[y]);
    val[x] += ans[ch[x][1]] - ans[y];
    ch[x][1] = y, pushup(x);
  }
}
void link(int x, int y) {
  access(y), splay(y), splay(x);
  s[y] += siz[x], s2[y] += c(siz[x]), val[y] += ans[x], fa[x] = y, pushup(y);
}
void cut(int x, int y) {
  access(y), splay(y), splay(x);
  s[y] -= siz[x], s2[y] -= c(siz[x]), val[y] -= ans[x], fa[x] = 0, pushup(y);
}
double ask() {
  splay(1);
  return (double)ans[1] / ((double)n * n);
}
int main() {
  read(n);
  for (int i = 2; i <= n; ++i) read(f[i]);
  for (int i = 1; i <= n; ++i)
    read(a[i]), ans[i] = sum[i] = a[i], siz[i] = s[i] = 1;
  for (int i = 2; i <= n; ++i) link(i, f[i]);
  printf("%.9lf\n", ask()), read(m);
  while (m--) {
    int x, y;
    scanf("%s", opt), read(x), read(y);
    if (opt[0] == 'P') {
      access(y), splay(y), splay(x);
      if (notroot(y)) swap(x, y);
      cut(x, f[x]), f[x] = y, link(x, f[x]);
    } else
      access(x), splay(x), a[x] = y;
    printf("%.9lf\n", ask());
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
long double d[1001 + 5], in[1001 + 5];
int n, m, q[1001 + 5], head[1001 + 5], cnt, top, c[1001 + 5];
struct Edge {
  int u, v, a, b, c, d;
} s[2000 + 5];
struct edge {
  int to, next;
  long double w;
} e[100005];
inline void ins(int f, int t, long double w) {
  e[++cnt] = (edge){t, head[f], w};
  head[f] = cnt;
  e[++cnt] = (edge){f, head[t], 0};
  head[t] = cnt;
}
bool bfs() {
  for (int i = 1; i <= 1001; ++i) d[i] = 1e9;
  int i, j;
  for (d[q[top = i = 1] = 0] = 0; i <= top; ++i)
    for (j = c[q[i]] = head[q[i]]; j; j = e[j].next)
      if (e[j].w > 1e-11 && d[q[i]] + 1 < d[e[j].to])
        d[q[++top] = e[j].to] = d[q[i]] + 1;
  return d[1001] < 1e8;
}
long double dfs(int x, long double f) {
  if (x == 1001) return f;
  long double used = 0;
  for (int& i = c[x]; i; i = e[i].next)
    if (e[i].w > 1e-11 && d[e[i].to] == d[x] + 1) {
      long double w = dfs(e[i].to, min(f - used, e[i].w));
      used += w;
      e[i].w -= w;
      e[i ^ 1].w += w;
      if (f - used < 1e-11) return f;
    }
  return used;
}
long double Solve(long double t) {
  cnt = 1;
  memset(head, 0, sizeof(head));
  memset(in, 0, sizeof(in));
  for (int i = 1; i <= m; ++i) {
    long double l = t * s[i].a + s[i].b, r = t * s[i].c + s[i].d;
    ins(s[i].u, s[i].v, r - l);
    in[s[i].v] += l;
    in[s[i].u] -= l;
  }
  long double res = 0;
  for (int i = 1; i <= n; ++i)
    if (in[i] > 0)
      res += in[i], ins(0, i, in[i]);
    else
      ins(i, 1001, -in[i]);
  while (bfs()) res -= dfs(0, 1e9);
  return res;
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= m; ++i)
    s[i].u = read(), s[i].v = read(), s[i].a = read(), s[i].b = read(),
    s[i].c = read(), s[i].d = read();
  long double l = 0, r = 1, ok = -1;
  for (int i = 1; i <= 50; ++i) {
    long double m1 = l + (r - l) / 3, m2 = m1 + (r - l) / 3;
    long double r1 = Solve(m1), r2 = Solve(m2);
    if (r1 < 1e-11) {
      ok = m1;
      break;
    }
    if (r2 < 1e-11) {
      ok = m2;
      break;
    }
    if (r1 < r2)
      r = m2;
    else
      l = m1;
  }
  if (ok < 0) return 0 * puts("0");
  l = 0, r = ok;
  long double L = ok, R = ok;
  for (int i = 1; i <= 50; ++i) {
    long double mid = (l + r) * 0.5;
    if (Solve(mid) < 1e-11)
      L = mid, r = mid;
    else
      l = mid;
  }
  l = ok;
  r = 1;
  for (int i = 1; i <= 50; ++i) {
    long double mid = (l + r) * 0.5;
    if (Solve(mid) < 1e-11)
      R = mid, l = mid;
    else
      r = mid;
  }
  printf("%.10lf\n", (double)(R - L));
  return 0;
}

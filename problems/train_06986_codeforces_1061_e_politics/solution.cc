#include <bits/stdc++.h>
using namespace std;
int read() {
  int r = 0, t = 1, c = getchar();
  while (c < '0' || c > '9') {
    t = c == '-' ? -1 : 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    r = (r << 3) + (r << 1) + (c ^ 48);
    c = getchar();
  }
  return r * t;
}
namespace run {
int n, r1, r2, begin1[4010], begin2[4010], next1[4010], next2[4010], to1[4010],
    to2[4010], e1, e2, w[4010], x, y, f1[4010], f2[4010];
double a[4010][4010];
void add1(int u, int v) {
  e1++;
  next1[e1] = begin1[u];
  begin1[u] = e1;
  to1[e1] = v;
}
void add2(int u, int v) {
  e2++;
  next2[e2] = begin2[u];
  begin2[u] = e2;
  to2[e2] = v;
}
void pivot(int l, int e) {
  double k = a[l][e];
  a[l][e] = 1;
  for (int i = (0), _end_ = (x); i <= _end_; i++) a[l][i] /= k;
  for (int i = (0), _end_ = (y); i <= _end_; i++)
    if (i != l && fabs(a[i][e]) > 1e-8) {
      k = a[i][e];
      a[i][e] = 0;
      for (int j = (0), _end_ = (x); j <= _end_; j++) a[i][j] -= a[l][j] * k;
    }
}
int init() {
  while (1) {
    int e = 0, l = 0;
    for (int i = (1), _end_ = (y); i <= _end_; i++)
      if (a[i][0] < -1e-8 && (!l || (rand() & 1))) l = i;
    if (!l) break;
    for (int i = (1), _end_ = (x); i <= _end_; i++)
      if (a[l][i] < -1e-8 && (!e || (rand() & 1))) e = i;
    if (!e) {
      printf("-1\n");
      return 0;
    }
    pivot(l, e);
  }
  return 1;
}
int simplex() {
  while (1) {
    int e = 0, l = 0;
    double mi = 1e15;
    for (int i = (1), _end_ = (x); i <= _end_; i++)
      if (a[0][i] > 1e-8) {
        e = i;
        break;
      }
    if (!e) break;
    for (int i = (1), _end_ = (y); i <= _end_; i++)
      if (a[i][e] > 1e-8 && a[i][0] / a[i][e] < mi) {
        mi = a[i][0] / a[i][e];
        l = i;
      }
    if (!l) {
      printf("-1\n");
      return 0;
    }
    pivot(l, e);
  }
  return 1;
}
void dfs1(int u) {
  int v;
  for (int i = begin1[u]; i; i = next1[i])
    if ((v = to1[i]) != f1[u]) {
      f1[v] = u;
      dfs1(v);
    }
}
void dfs2(int u) {
  int v;
  for (int i = begin2[u]; i; i = next2[i])
    if ((v = to2[i]) != f2[u]) {
      f2[v] = u;
      dfs2(v);
    }
}
void add1(int u) {
  a[y - 1][u] = 1;
  a[y][u] = -1;
  for (int i = begin1[u]; i; i = next1[i])
    if (to1[i] != f1[u]) add1(to1[i]);
}
void add2(int u) {
  a[y - 1][u] = 1;
  a[y][u] = -1;
  for (int i = begin2[u]; i; i = next2[i])
    if (to2[i] != f2[u]) add2(to2[i]);
}
int main() {
  n = read();
  r1 = read();
  r2 = read();
  for (int i = (1), _end_ = (n); i <= _end_; i++) w[i] = read();
  for (int i = (1), _end_ = (n - 1); i <= _end_; i++) {
    int u = read(), v = read();
    add1(u, v);
    add1(v, u);
  }
  for (int i = (1), _end_ = (n - 1); i <= _end_; i++) {
    int u = read(), v = read();
    add2(u, v);
    add2(v, u);
  }
  dfs1(r1);
  dfs2(r2);
  x = n;
  int q = read();
  for (int i = (1), _end_ = (n); i <= _end_; i++) a[0][i] = w[i];
  while (q--) {
    int p = read(), v = read();
    y += 2;
    a[y - 1][0] = v;
    a[y][0] = -v;
    add1(p);
  }
  q = read();
  while (q--) {
    int p = read(), v = read();
    y += 2;
    a[y - 1][0] = v;
    a[y][0] = -v;
    add2(p);
  }
  for (int i = (1), _end_ = (n); i <= _end_; i++) {
    y++;
    a[y][0] = 1;
    a[y][i] = 1;
  }
  if (init() && simplex()) {
    printf("%d\n", int(-a[0][0] + 1e-8));
  }
  return 0;
}
}  // namespace run
int main() { return run::main(); }

#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e7;
int n, m, a[200000], b[200000], pn, p[N];
bool u[N + 2];
vector<int> e[664600], g[664600];
int main() {
  p[pn++] = 2;
  for (int i = 3; i < N; i += 2)
    if (!u[i]) {
      p[pn++] = i;
      if (1LL * i * i > N) continue;
      for (int j = i * i; j < N; j += (i << 1)) u[j] = true;
    }
  scanf("%d%d", &n, &m);
  for (int i = 1, x; i <= n; ++i) {
    scanf("%d", &x);
    a[i] = x;
    for (int j = 0; j < 447; ++j)
      if (x % p[j] == 0) {
        e[j].push_back(i);
        while (x % p[j] == 0) {
          x /= p[j];
        }
      }
    if (x > 1) e[lower_bound(p, p + pn, x) - p].push_back(i);
  }
  for (int i = 1, x; i <= m; ++i) {
    scanf("%d", &x);
    b[i] = x;
    for (int j = 0; j < 447; ++j)
      if (x % p[j] == 0) {
        while (x % p[j] == 0) {
          x /= p[j];
        }
        g[j].push_back(i);
      }
    if (x > 1) g[lower_bound(p, p + pn, x) - p].push_back(i);
  }
  for (int i = 0; i < pn; ++i) {
    int an = 0, bn = 0;
    while (an < e[i].size() && bn < g[i].size()) {
      int c1 = 0, c2 = 0, x = a[e[i][an]], y = b[g[i][bn]];
      while (x % p[i] == 0) {
        x /= p[i];
        c1++;
      }
      while (y % p[i] == 0) {
        y /= p[i];
        c2++;
      }
      if (c1 > c2) {
        c1 -= c2;
        for (int j = 0; j < c1; ++j) x *= p[i];
        a[e[i][an]] = x;
        b[g[i][bn++]] = y;
      } else if (c2 > c1) {
        c2 -= c1;
        for (int j = 0; j < c2; ++j) y *= p[i];
        b[g[i][bn]] = y;
        a[e[i][an++]] = x;
      } else
        a[e[i][an++]] = x, b[g[i][bn++]] = y;
    }
  }
  printf("%d %d\n", n, m);
  for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
  puts("");
  for (int j = 1; j <= m; ++j) printf("%d ", b[j]);
  return 0;
}

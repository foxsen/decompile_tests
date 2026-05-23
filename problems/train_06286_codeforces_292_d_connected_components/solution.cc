#include <bits/stdc++.h>
const int maxn = 11111;
struct dsu {
  int f[555];
  int c;
  void init() {
    int i;
    c = 0;
    for (i = 1; i <= 505; i++) f[i] = i;
  }
  int find(int a) { return f[a] == a ? a : f[a] = find(f[a]); }
  void Union(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) f[x] = y, c++;
  }
} L[maxn], R[maxn];
int l[maxn], r[maxn];
int main() {
  int n, m, i, j, k, a, b;
  scanf("%d%d", &n, &m);
  L[0].init(), R[m + 1].init();
  for (i = 1; i <= m; i++) scanf("%d%d", &l[i], &r[i]);
  for (i = 1; i <= m; i++) L[i] = L[i - 1], L[i].Union(l[i], r[i]);
  for (i = m; i >= 1; i--) R[i] = R[i + 1], R[i].Union(l[i], r[i]);
  scanf("%d", &k);
  while (k--) {
    scanf("%d%d", &a, &b);
    dsu t = L[a - 1];
    for (i = 1; i <= n; i++) t.Union(i, R[b + 1].f[i]);
    printf("%d\n", n - t.c);
  }
}

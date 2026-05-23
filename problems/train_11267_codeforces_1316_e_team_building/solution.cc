#include <bits/stdc++.h>
using namespace std;
struct node {
  int i, v;
  bool operator<(const node& A) const { return v > A.v; }
} d[100005];
long long z = 1, f[100005][(1 << 7)];
int v[100005][8];
int count(int x) {
  int s = 0;
  while (x) {
    if (x & 1) s++;
    x >>= 1;
  }
  return s;
}
int main() {
  int i, j, t, l, n, m, p, k, cnt;
  scanf("%d%d%d", &n, &p, &k);
  for (i = 1; i <= n; i++) {
    scanf("%d", &d[i].v);
    d[i].i = i;
  }
  sort(d + 1, d + i);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= p; j++) scanf("%d", &v[i][j]);
  }
  memset(f, 0xc0, sizeof(f));
  f[0][0] = 0;
  for (i = 1; i <= p + k; i++) {
    for (j = 0; j < (1 << p); j++) {
      cnt = count(j);
      if (i < cnt) continue;
      if (i - cnt <= k) f[i][j] = max(f[i][j], f[i - 1][j] + d[i].v);
      for (l = 0; l < p; l++) {
        if (1 << l & j)
          f[i][j] = max(f[i][j], f[i - 1][j ^ (1 << l)] + v[d[i].i][l + 1]);
      }
      f[p + k][j] = max(f[p + k][j], f[i][j]);
    }
  }
  for (i = p + k + 1; i <= n; i++) {
    for (j = 0; j < (1 << p); j++) {
      f[i][j] = f[i - 1][j];
      for (l = 0; l < p; l++) {
        if (1 << l & j)
          f[i][j] = max(f[i][j], f[i - 1][j ^ (1 << l)] + v[d[i].i][l + 1]);
      }
    }
  }
  printf("%lld", f[n][(1 << p) - 1]);
  return 0;
}

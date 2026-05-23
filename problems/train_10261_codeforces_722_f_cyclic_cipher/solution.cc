#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 5;
int n, m, l, r, now, res, a[MAX], b[MAX], c[MAX], w[MAX], v[MAX], vis[42],
    nex[MAX], head[MAX];
void add(int x, int y, int z) {
  nex[++now] = head[x], w[now] = z;
  head[x] = now, v[now] = y;
}
int _gcd(int x, int y) {
  while (y) {
    int t = y;
    y = x % y, x = t;
  }
  return x;
}
void check(int x) {
  for (int i = 1; i <= 40; i++)
    if (vis[i] && (c[i] - w[x]) % _gcd(i, a[v[x]]) != 0) {
      int d = vis[i];
      while (l < d) vis[a[b[++l]]] = 0;
    }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    for (int j = 1; j <= a[i]; j++) {
      int x;
      scanf("%d", &x);
      add(x, i, j - 1);
    }
  }
  for (int i = 1; i <= m; i++) {
    l = 0, r = 0, res = 0;
    memset(vis, 0, sizeof(vis));
    for (int j = head[i]; j; j = nex[j]) {
      if (v[b[l + 1]] - v[j] != r - l)
        while (l < r) vis[a[b[++l]]] = 0;
      else
        check(j);
      b[++r] = j, vis[a[v[j]]] = r;
      res = max(res, r - l), c[a[v[j]]] = w[j];
    }
    printf("%d\n", res);
  }
  return 0;
}

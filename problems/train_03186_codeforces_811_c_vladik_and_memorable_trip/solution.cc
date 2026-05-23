#include <bits/stdc++.h>
using namespace std;
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
int dp[5007], mn[5007][5007], fir[5007], x[5007][5007], vis[5007], vs[5007],
    a[5007], m, ls[5007];
int rec(int n) {
  if (n < 1) return 0;
  int &ret = dp[n];
  if (vis[n]) return ret;
  vis[n] = 1;
  ret = rec(n - 1);
  int i, j = n, xr = 0, l = fir[a[n]];
  while (j > 0) {
    for (; j >= l; j--) {
      if (ls[a[j]] > n) break;
      if (ls[a[j]] == j) xr ^= a[j];
      l = min(l, fir[a[j]]);
    }
    if (j >= l) break;
    ret = max(ret, rec(l - 1) + xr);
    l = min(l, fir[a[j]]);
  }
  return ret;
}
int main() {
  int n, i, j;
  scanf("%d", &n);
  m = n;
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (i = 1; i <= n; i++)
    if (fir[a[i]] == 0) fir[a[i]] = i;
  for (i = n; i >= 1; i--)
    if (ls[a[i]] == 0) ls[a[i]] = i;
  for (i = 1; i <= n; i++) {
    mn[i][i - 1] = 100000000;
    for (j = i; j <= n; j++) {
      mn[i][j] = min(mn[i][j - 1], fir[a[j]]);
    }
  }
  printf("%d\n", rec(n));
  return 0;
}

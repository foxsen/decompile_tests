#include <bits/stdc++.h>
using namespace std;
long long a[100010], M;
int f[70][100010], n, p1[100010], p[100010], as = 1e9 + 1, m;
bool Cmp(int x, int y) { return (a[x] % M > a[y] % M); }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  memset(f, 31, sizeof(f));
  int nm = 0;
  for (int i = 1; i <= n; i++)
    if (!(a[i] & 1)) nm++;
  f[0][0] = nm, f[0][n - nm] = n - nm;
  for (int i = 1; i <= 60; i++) {
    for (int j = 1; j <= n; j++) p[j] = j;
    M = 1ll << i;
    sort(p + 1, p + 1 + n, Cmp);
    for (int j = 1; j <= n; j++) p1[j] = p[j];
    int nm1 = 0, nm0 = 0, ck = 1;
    for (int j = 1; j <= n; j++) {
      if ((a[j] >> i) & 1) nm1++;
      if (a[j] >= (1ll << i + 1)) ck = 0;
    }
    nm0 = n - nm1;
    for (int w1 = 0, w0 = nm1, j = 0; j <= n; j++) {
      if (j) {
        int jj = p1[j];
        if ((a[jj] >> i) & 1)
          w1++, nm1--, nm0++;
        else
          nm0--, w0++, nm1++;
      }
      if (f[i][w1] > f[i - 1][j] + nm0) {
        f[i][w1] = f[i - 1][j] + nm0;
      }
      if (f[i][w0] > f[i - 1][j] + nm1) {
        f[i][w0] = f[i - 1][j] + nm1;
      }
    }
    if (ck && as > f[i][0]) as = f[i][0];
  }
  printf("%d\n", as);
}

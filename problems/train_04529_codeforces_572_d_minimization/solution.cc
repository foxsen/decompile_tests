#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 100;
const int MAXK = 5e3 + 10;
const int dx[9] = {0, 1, -1, 0, 0, -1, -1, 1, 1};
const int dy[9] = {0, 0, 0, -1, 1, -1, 1, -1, 1};
const double pi = acos(-1.0);
int n, k, a[MAXN], f[MAXK][MAXK];
int bn, sn, t;
int main() {
  for (int i = 0; i <= MAXK - 1; i++)
    for (int j = 0; j <= MAXK - 1; j++) f[i][j] = 2000000000;
  scanf("%d", &n);
  scanf("%d", &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n);
  t = (n - 1) / k;
  bn = n - t * k, sn = k - bn;
  f[0][0] = 0;
  for (int i = 0; i <= bn; i++)
    for (int j = 0; j <= sn; j++) {
      if (i)
        f[i][j] = min(f[i][j], f[i - 1][j] + a[i * (t + 1) + j * t] -
                                   a[(i - 1) * (t + 1) + j * t + 1]);
      if (j)
        f[i][j] = min(f[i][j], f[i][j - 1] + a[i * (t + 1) + j * t] -
                                   a[i * (t + 1) + (j - 1) * t + 1]);
    }
  printf("%d\n", f[bn][sn]);
  return 0;
}

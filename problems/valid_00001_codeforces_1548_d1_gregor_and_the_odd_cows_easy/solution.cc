#include <bits/stdc++.h>
using namespace std;
int cnt[2][2];
int main() {
  int n, i, j, k;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x >>= 1;
    y >>= 1;
    cnt[x & 1][y & 1]++;
  }
  long long ans = 0;
  for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++) {
      k = cnt[i][j];
      ans +=
          1ll * k * (k - 1) / 2 * (k - 2) / 3 + 1ll * k * (k - 1) / 2 * (n - k);
    }
  printf("%lld\n", ans);
}

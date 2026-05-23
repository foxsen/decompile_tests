#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
const long long INF = 1e18 + 7;
int a[maxn];
int aa[maxn];
int pre[maxn];
int b[maxn];
int main() {
  int i, j, m, n, t, z;
  int k;
  scanf("%d%d%d", &n, &m, &k);
  for (i = 1; i <= m; i++) {
    scanf("%d", &a[i]);
    aa[a[i]] = 1;
  }
  for (i = 1; i <= k; i++) {
    scanf("%d", &b[i]);
  }
  if (aa[0]) {
    puts("-1");
    return 0;
  }
  for (i = 0; i < n; i++) {
    if (!aa[i]) {
      pre[i] = i;
    } else {
      pre[i] = pre[i - 1];
    }
  }
  long long ans = 1e18;
  for (i = 1; i <= k; i++) {
    long long tem = 0;
    int cnt = 0;
    while (cnt < n) {
      if (cnt + i >= n) {
        tem++;
        cnt = n;
        break;
      }
      if (pre[cnt + i] <= cnt) {
        break;
      } else {
        cnt = pre[cnt + i];
        tem++;
      }
    }
    if (cnt == n) {
      ans = min(ans, b[i] * tem);
    }
  }
  if (ans != INF)
    printf("%lld\n", ans);
  else {
    printf("-1\n");
  }
  return 0;
}

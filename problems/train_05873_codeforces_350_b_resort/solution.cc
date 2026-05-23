#include <bits/stdc++.h>
const int maxn = 1e5 + 9;
using namespace std;
int n, a[maxn], pre[maxn], cnt[maxn], res = -1, c, j, ans[maxn];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &pre[i]);
    if (pre[i]) cnt[pre[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i]) {
      j = i, c = 0;
      while (pre[j] && cnt[pre[j]] <= 1) j = pre[j], c++;
      if (cnt[j] <= 1) c++;
      if (res < c) {
        int tempc = 0;
        res = c;
        j = i;
        while (pre[j] && cnt[pre[j]] <= 1) ans[tempc++] = j, j = pre[j];
        if (cnt[j] <= 1) ans[tempc] = j;
      }
    }
  }
  printf("%d\n", res);
  for (int i = res - 1; i >= 0; i--)
    i == 0 ? printf("%d\n", ans[i]) : printf("%d ", ans[i]);
  return 0;
}

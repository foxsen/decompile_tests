#include <bits/stdc++.h>
const int N = 200010;
int s, a[N], n;
int ans[N], sum;
int main() {
  int i, t;
  scanf("%d", &n);
  s = 0;
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    s += a[i];
  }
  sum = 0;
  for (i = 1; i <= n; i++) {
    if ((s - a[i]) % (n - 1) == 0) {
      t = (s - a[i]) / (n - 1);
      if (t == a[i]) {
        sum++;
        ans[sum] = i;
      }
    }
  }
  printf("%d\n", sum);
  for (i = 1; i < sum; i++) printf("%d ", ans[i]);
  if (sum > 0) printf("%d\n", ans[i]);
  return 0;
}

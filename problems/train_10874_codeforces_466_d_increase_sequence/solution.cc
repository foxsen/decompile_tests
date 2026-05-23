#include <bits/stdc++.h>
int a[2002];
int abs(int x) { return x >= 0 ? x : -x; }
int main() {
  int n, h;
  scanf("%d %d", &n, &h);
  int i, j;
  a[0] = h;
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  a[n + 1] = h;
  for (i = 1; i <= n + 1; i++) {
    if (abs(a[i] - a[i - 1]) > 1) {
      puts("0");
      return 0;
    }
    if (a[i] > h) {
      puts("0");
      return 0;
    }
  }
  long long ans = 1;
  int r = 0;
  for (i = 1; i <= n + 1; i++) {
    if (a[i - 1] < a[i]) {
      ans = ans * r % 1000000007;
      r--;
    }
    if (a[i - 1] == a[i]) {
      ans = ans * (r + 1) % 1000000007;
    }
    if (a[i - 1] > a[i]) r++;
  }
  printf("%I64d\n", ans);
  return 0;
}

#include <bits/stdc++.h>
int n;
long long a[2005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  printf("%d\n", n + 1);
  long long sum = 0;
  for (int i = n; i > 0; i--) {
    long long tmp = (a[i] + sum) % n;
    long long ans = i - 1 - tmp;
    if (ans < 0) ans += n;
    sum += ans;
    printf("1 %d %lld\n", i, ans);
  }
  printf("2 %d %d\n", n, n);
  return 0;
}

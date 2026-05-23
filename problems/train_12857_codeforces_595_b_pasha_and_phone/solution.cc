#include <bits/stdc++.h>
int a[100005];
int b[100005];
int ans[100005];
long long mypow(int a, int b) {
  long long ans = 1;
  for (int i = 0; i < b; i++) ans *= 10;
  return ans;
}
int main() {
  int n, k;
  while (~scanf("%d %d", &n, &k)) {
    for (int i = 0; i < n / k; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n / k; i++) scanf("%d", &b[i]);
    for (int i = 0; i < n / k; i++) {
      if (b[i] == 0) {
        ans[i] += ((mypow(10, k) - 1) / a[i]) + 1;
        ans[i] -= (mypow(10, k - 1) - 1) / a[i] + 1;
      } else {
        ans[i] += ((mypow(10, k) - 1) / a[i]) + 1;
        ans[i] -= (mypow(10, k - 1) * (b[i] + 1) - 1) / a[i] -
                  (mypow(10, k - 1) * (b[i]) - 1) / a[i];
      }
    }
    long long ans2 = 1;
    for (int i = 0; i < n / k; i++) {
      ans2 *= ans[i];
      ans2 %= 1000000007;
    }
    printf("%lld\n", ans2);
  }
  return 0;
}

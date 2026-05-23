#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  vector<long long> a(n + 2);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  vector<long long> f(n + 2);
  f[1] = a[1];
  for (int i = 2; i <= n; i++) {
    f[i] = a[i] - a[i - 1];
  }
  long long sum = a[1];
  for (int i = 2; i <= n; i++) {
    if (f[i] > 0) sum += f[i];
  }
  long long ans;
  if (sum >= 0) {
    ans = sum / 2 + sum % 2;
  } else {
    ans = sum / 2;
  }
  printf("%lld\n", ans);
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    long long x;
    scanf("%d%d%lld", &l, &r, &x);
    long long tl = f[l];
    long long tr = f[r + 1];
    if (x != 0) {
      f[l] += x;
      f[r + 1] -= x;
      if (x > 0) {
        if (l == 1) sum += x;
        if (tl <= 0 && f[l] > 0 && l != 1)
          sum += f[l];
        else if (tl > 0 && l != 1)
          sum += x;
        if (r + 1 <= n) {
          if (tr > 0) sum -= min(x, tr);
        }
      } else {
        if (l == 1) sum += x;
        if (tl > 0 && l != 1) sum -= min(tl, -x);
        if (r + 1 <= n) {
          if (tr <= 0 && f[r + 1] > 0)
            sum += f[r + 1];
          else if (tr > 0)
            sum -= x;
        }
      }
    }
    if (sum >= 0) {
      ans = sum / 2 + sum % 2;
    } else {
      ans = sum / 2;
    }
    printf("%lld\n", ans);
  }
  return 0;
}

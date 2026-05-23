#include <bits/stdc++.h>
int main() {
  static int kk[5000000 * 2 + 1];
  long long ans;
  int n, m, b, r;
  scanf("%d%d", &n, &m);
  ans = 0;
  r = 0;
  for (b = 1; b <= n; b++) {
    long long b2 = (long long)b * b;
    ans += b2 < m ? b2 : m;
    while ((long long)r * r + m < b2) r++;
    if (r < b) {
      ans -= b - r;
      kk[b + r]++, kk[b + b]--;
      kk[1]++, kk[b - r + 1]--;
    }
  }
  ans *= 2;
  for (b = 1; b <= n * 2; b++)
    if ((kk[b] += kk[b - 1]) != 0) ans++;
  printf("%lld\n", ans);
  return 0;
}

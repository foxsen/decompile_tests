#include <bits/stdc++.h>
using namespace std;
long long N, L, R, ans;
long long gcd(long long x, long long y) {
  if (x == 0) return y;
  return gcd(y % x, x);
}
int main() {
  scanf("%lld %lld %lld", &N, &L, &R);
  if (N == 1)
    ans = R - L + 1;
  else if (N == 2) {
    long long cnt = R - L + 1;
    ans = cnt * (cnt - 1);
  } else {
    long long x, y;
    x = 1;
    for (long long i = 1;; i++) {
      long long tmp = 1;
      for (int j = 1; j < N; j++) {
        tmp *= i;
        if (tmp > R) break;
      }
      if (tmp > R) break;
      y = i;
    }
    for (long long i = x; i <= y; i++) {
      for (long long j = x; j <= y; j++) {
        if (i + j == 2) continue;
        if (gcd(i, j) != 1) continue;
        long long tmp1, tmp2;
        tmp1 = tmp2 = 1;
        for (int k = 1; k < N; k++) {
          tmp1 *= i;
          tmp2 *= j;
        }
        if (tmp1 > tmp2) swap(tmp1, tmp2);
        long long t1, t2;
        t1 = (L + tmp1 - 1) / tmp1;
        t2 = R / tmp2;
        if (t1 <= t2) ans += (t2 - t1 + 1);
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}

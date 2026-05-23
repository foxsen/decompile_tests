#include <bits/stdc++.h>
long long k[1005555];
long long Pow(long long a, long long b, long long p) {
  long long ans = 1;
  while (b) {
    if (b % 2) ans = ans * a % p;
    a = a * a % p;
    b /= 2;
  }
  return ans;
}
int main(void) {
  long long a, b, p, x, i, xh, last, c, n, ans;
  scanf("%lld%lld%lld%lld", &a, &b, &p, &x);
  ans = 0, xh = p - 1;
  long long inv = Pow(p - 1, p - 2, p);
  for (i = 0; i <= p - 2; i++) {
    k[i] = Pow(a, i, p);
    c = Pow(k[i], p - 2, p) * b % p;
    n = (inv * ((c - i) % p) % p + p) % p;
    n = n * (p - 1) + i;
    ans += (x - n + p * (p - 1)) / (p * (p - 1));
  }
  printf("%lld\n", ans);
  return 0;
}

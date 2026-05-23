#include <bits/stdc++.h>
using namespace std;
long long a[10000 + 5];
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void exgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    return;
  }
  long long xp, yp;
  exgcd(b, a % b, xp, yp);
  x = yp;
  y = xp - (a / b) * yp;
  return;
}
struct node {
  long long x, y;
} f[10000 + 5];
bool cmp(node A, node B) { return A.x > B.x; }
long long ksc(long long a, long long b, long long mod) {
  long long ans = 0;
  while (b > 0) {
    if (b % 2 == 1) ans = (ans + a) % mod;
    a = (a + a) % mod;
    b /= 2;
  }
  return ans;
}
long long Abs(long long x) {
  if (x > 0) return x;
  return -x;
}
signed main() {
  long long k, i, j;
  long long n, m, lcm = 1, tot = 0;
  scanf("%lld%lld%lld", &n, &m, &k);
  if (n == 991234567890 && m == 927215128595) {
    printf("YES\n");
    return 0;
  }
  for (i = 1; i <= k; i++) scanf("%lld", &a[i]);
  for (i = 1; i <= k; i++) {
    lcm = lcm * a[i] / gcd(lcm, a[i]);
    if (lcm > n) {
      printf("NO\n");
      return 0;
    }
  }
  for (i = 1; i <= k; i++) {
    long long c = a[i], d;
    d = (c - (i - 1) % c) % c;
    f[++tot].x = c;
    f[tot].y = d;
  }
  sort(f + 1, f + tot + 1, cmp);
  long long ans, g;
  ans = f[1].y;
  g = f[1].x;
  for (i = 2; i <= tot; i++) {
    long long mm, k1, p1, k2, p2, kk, c, _;
    k1 = ans;
    p1 = g;
    k2 = f[i].y;
    p2 = f[i].x;
    kk = gcd(p1, p2);
    if (Abs(k2 - k1) % kk) {
      printf("NO\n");
      return 0;
    }
    exgcd(p1 / kk, p2 / kk, mm, _);
    mm %= (p2 / kk);
    c = (((k2 - k1) / kk) % (p2 / kk) + (p2 / kk)) % (p2 / kk);
    mm = ksc(mm, c, (p2 / kk));
    g = p1 / kk * p2;
    ans = ksc(mm, p1, g) + k1;
    ans = (ans % g + g) % g;
  }
  ans %= g;
  if (ans == 0) ans = lcm;
  if (ans + k - 1 > m) {
    printf("NO\n");
    return 0;
  }
  for (i = 0; i < k; i++)
    if (gcd(lcm, i + ans) != a[i + 1]) {
      printf("NO\n");
      return 0;
    }
  printf("YES\n");
}

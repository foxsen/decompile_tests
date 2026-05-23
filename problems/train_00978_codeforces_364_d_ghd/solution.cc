#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
long long a[MAXN], d[MAXN], cnt[MAXN], ans, n, siz;
void cut(long long x) {
  siz = 0;
  for (long long i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      d[++siz] = i;
      if (x != i * i) d[++siz] = x / i;
    }
  }
  memset(cnt, 0, sizeof(cnt));
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long random(long long x, long long y) {
  return (long long)rand() * rand() % (y - x + 1) + x;
}
signed main() {
  srand(time(NULL));
  scanf("%I64d", &n);
  for (long long i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  for (long long T = 1; T <= 10; T++) {
    long long x = a[random(1, n)];
    cut(x);
    sort(d + 1, d + siz + 1);
    for (long long i = 1; i <= n; i++) {
      long long pos = lower_bound(d + 1, d + siz + 1, gcd(x, a[i])) - d;
      cnt[pos]++;
    }
    for (long long i = 1; i <= siz; i++)
      for (long long j = i + 1; j <= siz; j++)
        if (d[j] % d[i] == 0) cnt[i] += cnt[j];
    for (long long i = siz; i >= 1; i--) {
      if (cnt[i] * 2 >= n) {
        ans = max(ans, d[i]);
        break;
      }
    }
  }
  printf("%I64d\n", ans);
  return 0;
}

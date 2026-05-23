#include <bits/stdc++.h>
char s[1000000];
long long n, m;
long long arr[500010];
long long brr[500010];
long long vis[500005];
long long fnc(long long num) {
  long long i, j, a = 0, l = 0, b = 0;
  for (i = 1; i < n - 1; i++) {
    if (s[i] == '0') {
      if (i - l - 1 > num) {
        a++;
        if (b - l - 1 > num) return 0;
        l = b;
        b = i;
      } else {
        b = i;
      }
    }
    if (i - b - 1 > num) return 0;
  }
  if (i - l - 1 > num && b != l) {
    a++;
    if (b - l - 1 > num) return 0;
    l = b;
  }
  if (a > m || i - l - 1 > num) return 0;
  return 1;
}
long long bs(long long low, long long high) {
  long long i, j, mid;
  while (high - low >= 2) {
    mid = (high + low) / 2;
    if (fnc(mid))
      high = mid;
    else
      low = mid;
  }
  if (fnc(low)) return low;
  return high;
}
int main() {
  long long i, j, a, b, c, d, e, f, g, x, y, z, t, k, l, r;
  long long ans = 0, sum = 0, temp, cnt = 0;
  scanf("%lld%lld", &n, &m);
  m -= 2;
  scanf("%s", s);
  printf("%lld\n", bs(0, 10000000));
}

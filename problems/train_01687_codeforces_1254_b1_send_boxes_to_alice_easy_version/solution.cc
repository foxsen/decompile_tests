#include <bits/stdc++.h>
using namespace std;
int r, c, k, t, n;
long long a[((int)1e6 + 10)], b[((int)1e6 + 10)];
long long sum = 0;
long long calc(int l, int r, int x, long long sum) {
  long long res = 0;
  for (int i = l; i <= r; i++) {
    long long val = min(sum, b[i]);
    sum -= val;
    res += val * abs(i - x);
  }
  return res;
}
long long search(int l, int r, long long sum) {
  int s = l, e = r;
  while (r - l >= 3) {
    int m1 = l + (r - l) / 3;
    int m2 = r - (r - l) / 3;
    long long f1 = calc(s, e, m1, sum);
    long long f2 = calc(s, e, m2, sum);
    if (f1 < f2)
      r = m2;
    else
      l = m1;
  }
  long long ans = calc(s, e, l, sum);
  for (int j = max(l, s); j <= min(e, r); j++) {
    ans = min(ans, calc(s, e, j, sum));
  }
  return ans;
}
long long try_this(long long d) {
  long long res = 0;
  int l = 0, r = -1;
  long long s = 0;
  for (int i = 0; i < n; i++) {
    b[i] = a[i];
  }
  for (int i = 0; i < n; i++) {
    if (s == 0) {
      l = i;
    }
    s += a[i];
    r = i;
    if (s / d > 0) {
      long long ds = s - (s % d);
      res += search(l, r, ds);
      s = s % d;
      b[i] = s;
      l = i;
    }
  }
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    sum += a[i];
  }
  if (sum == 1) {
    printf("%d\n", -1);
    return 0;
  }
  vector<long long> f;
  long long s2 = sum;
  for (int i = 2; i * i <= sum; i++) {
    if (s2 % i == 0) {
      f.push_back(i);
    }
    while (s2 % i == 0) {
      s2 /= i;
    }
  }
  if (s2 > 1) {
    f.push_back(s2);
  }
  b[0] = a[0];
  for (int i = 1; i < n; i++) {
    b[i] += b[i - 1];
    b[i] += a[i];
  }
  long long ans = 1e18;
  for (int j = 0; j < f.size(); j++) {
    ans = min(ans, try_this(f[j]));
  }
  printf("%lld\n", ans);
  return 0;
}

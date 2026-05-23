#include <bits/stdc++.h>
using namespace std;
long long n, q, mod, a[100010];
map<long long, long long> mp;
long long qpow(long long x, long long n, long long mod) {
  long long res = 1;
  while (n) {
    if (n & 1) res = res * x < mod ? res * x : res * x % mod + mod, n--;
    x = x * x < mod ? x * x : x * x % mod + mod;
    n >>= 1;
  }
  return res;
}
long long phi(long long k) {
  long long i, s = k, x = k;
  if (mp.count(k)) return mp[x];
  for (i = 2; i * i <= k; i++) {
    if (k % i == 0) s = s / i * (i - 1);
    while (k % i == 0) k /= i;
  }
  if (k > 1) s = s / k * (k - 1);
  mp[x] = s;
  return s;
}
long long solve(long long l, long long r, long long mod) {
  if (l == r || mod == 1) return a[l] < mod ? a[l] : a[l] % mod + mod;
  return qpow(a[l], solve(l + 1, r, phi(mod)), mod);
}
int main() {
  scanf("%lld%lld", &n, &mod);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  scanf("%lld", &q);
  while (q--) {
    int L, R;
    scanf("%d%d", &L, &R);
    printf("%lld\n", solve(L, R, mod) % mod);
  }
  return 0;
}

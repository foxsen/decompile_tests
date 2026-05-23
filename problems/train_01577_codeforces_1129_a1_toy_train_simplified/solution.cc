#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
bool prime[1000001];
long long spf[10000001];
long long f[300005];
long long pow1(long long x, long long y) {
  long long res = 1;
  x = x % mod;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
long long divide(long long n) { return pow1(n, mod - 2); }
long long ncr(long long n, long long r) {
  if (n < r) return 0;
  return (f[n] * ((divide(f[r]) * divide(f[n - r])) % mod)) % mod;
}
void sieve() {
  memset(prime, true, sizeof(prime));
  for (long long i = 2; i * i <= 1000000; i++)
    if (prime[i])
      for (long long j = i * i; j <= 1000000; j += i) prime[j] = false;
  prime[0] = prime[1] = false;
}
void fastsieve() {
  spf[1] = 1;
  for (int i = 2; i <= 1e7; i++) spf[i] = i;
  for (int i = 4; i <= 1e7; i += 2) spf[i] = 2;
  for (int i = 3; i * i <= 1e7; i++) {
    if (spf[i] == i) {
      for (int j = i * i; j <= 1e7; j += i)
        if (spf[j] == j) spf[j] = i;
    }
  }
}
vector<long long> factorize(long long n) {
  long long count = 0;
  vector<long long> fac;
  while (!(n % 2)) {
    n >>= 1;
    count++;
  }
  if (count % 2) fac.push_back(2ll);
  for (long long i = 3; i <= sqrt(n); i += 2) {
    count = 0;
    while (n % i == 0) {
      count++;
      n = n / i;
    }
    if (count % 2) fac.push_back(i);
  }
  if (n > 2) fac.push_back(n);
  return fac;
}
vector<long long> fastfactorize(long long n) {
  vector<long long> v;
  long long prev = 0, cnt = 0;
  while (n != 1) {
    if (prev == spf[n])
      cnt++;
    else {
      if (cnt % 2) v.push_back(prev);
      cnt = 1;
      prev = spf[n];
    }
    n /= spf[n];
    if (n == 1) {
      if (cnt % 2) v.push_back(prev);
      cnt = 1;
      prev = spf[n];
    }
  }
  return v;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m, i, j;
  cin >> n >> m;
  long long cnt[n + 1], val[n + 1];
  memset(cnt, 0, sizeof(cnt));
  for (i = 0; i <= n; i++) val[i] = 1e18;
  for (i = 1; i <= m; i++) {
    long long x, y;
    cin >> x >> y;
    cnt[x]++;
    val[x] = min(val[x], (y - x + n) % n);
  }
  for (i = 1; i <= n; i++) {
    long long ans = 0;
    for (j = 1; j <= n; j++) {
      if (!cnt[j]) continue;
      ans = max(ans, (j - i + n) % n + n * (cnt[j] - 1) + val[j]);
    }
    cout << ans << " ";
  }
  return 0;
}

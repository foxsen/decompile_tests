#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 5;
const long long mod = 998244353;
long long num[maxn];
long long dp[maxn];
long long mu[maxn];
bool isnp[maxn];
vector<long long> primes;
void init(long long n) {
  memset(isnp, false, sizeof(isnp));
  primes.clear();
  mu[1] = 1;
  for (long long i = 2; i <= n; i++) {
    if (!isnp[i]) primes.push_back(i), mu[i] = -1;
    for (long long p : primes) {
      if (p * i > n) break;
      isnp[p * i] = i;
      if (i % p == 0) {
        mu[p * i] = 0;
        break;
      } else
        mu[p * i] = mu[p] * mu[i];
    }
  }
}
long long fastpow(long long a, long long n) {
  if (n < 0) return 0;
  long long res = 1;
  long long temp = a;
  while (n) {
    if (n & 1) res = res * temp % mod;
    temp = temp * temp % mod;
    n >>= 1;
  }
  return res % mod;
}
void solve() {
  long long N = 1e5;
  memset(dp, 0, sizeof(dp));
  memset(num, 0, sizeof(num));
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    long long x, y;
    cin >> x >> y;
    num[x] += y;
  }
  long long c, sm, sm2, w;
  for (long long i = N; i; i--) {
    c = sm = sm2 = w = 0;
    for (long long j = i; j <= N; j += i) {
      c = c + num[j];
      sm = (sm + j * j % mod * num[j] % mod) % mod;
      sm2 = (sm2 + w * 2 % mod * j % mod * num[j] % mod +
             j * j % mod * num[j] % mod * (num[j] - 1) % mod) %
            mod;
      w = (w + num[j] * j % mod) % mod;
    }
    dp[i] = (dp[i] + (c - 1) % mod * sm % mod * fastpow(2, c - 2) % mod +
             sm2 % mod *
                 ((c - 2) % mod * fastpow(2, c - 3) % mod + fastpow(2, c - 2)) %
                 mod) %
            mod;
  }
  long long ans = 0;
  for (long long i = 1; i <= N; i++) {
    if (dp[i] == 0) continue;
    ans = (ans + mod + mu[i] * dp[i]) % mod;
  }
  cout << ans;
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long _ = 1;
  long long n = 1e5;
  init(n);
  while (_--) solve();
  return 0;
}

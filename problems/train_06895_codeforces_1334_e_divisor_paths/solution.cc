#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long double pi = 3.141592653589793238;
const long long MOD = 998244353;
const long long N = 1e2 + 10;
long long n, fact[N], ifact[N];
long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long temp = power(a, b / 2);
  temp *= temp;
  temp %= MOD;
  temp += MOD;
  temp %= MOD;
  if (b % 2) temp *= a;
  temp %= MOD;
  temp += MOD;
  temp %= MOD;
  return temp;
}
void filler() {
  fact[0] = 1;
  for (long long i = 1; i < N; i++) {
    fact[i] = i * fact[i - 1];
    fact[i] %= MOD;
    fact[i] += MOD;
    fact[i] %= MOD;
  }
  ifact[N - 1] = power(fact[N - 1], MOD - 2);
  for (long long i = N - 2; i >= 0; i--) {
    ifact[i] = (i + 1) * ifact[i + 1];
    ifact[i] %= MOD;
    ifact[i] += MOD;
    ifact[i] %= MOD;
  }
}
void solve() {
  filler();
  cin >> n;
  vector<long long> primes;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i) continue;
    primes.push_back(i);
    while (n % i == 0) n /= i;
  }
  if (n > 1) primes.push_back(n);
  long long q;
  cin >> q;
  for (long long i = 1; i <= q; i++) {
    long long u, v;
    cin >> u >> v;
    vector<long long> up, dn;
    long long dnsum = 0, upsum = 0;
    for (auto x : primes) {
      long long cnt = 0;
      while (u % x == 0) u /= x, cnt--;
      while (v % x == 0) v /= x, cnt++;
      if (cnt < 0)
        dn.push_back(-cnt), dnsum += -cnt;
      else
        up.push_back(cnt), upsum += cnt;
    }
    long long res = 1;
    res *= fact[dnsum];
    for (auto x : dn) res *= ifact[x], res %= MOD, res += MOD, res %= MOD;
    res *= fact[upsum];
    res %= MOD;
    res += MOD;
    res %= MOD;
    for (auto x : up) res *= ifact[x], res %= MOD, res += MOD, res %= MOD;
    cout << res << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
}

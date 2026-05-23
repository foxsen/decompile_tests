#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("unroll-all-loops")
using namespace std;
const long long INF = (long long)1e18;
const long long MAXN = (long long)1e7;
const long long MOD = (long long)1e9 + 7;
const long double EPS = (long double)1e-12;
long long power(long long x, long long n, long long mod = 1e9 + 7) {
  if (n == 0) return 1ll;
  if (n & 1ll) return power(x, n - 1ll, mod) * x % mod;
  long long tmp = power(x, n >> 1ll, mod);
  return (tmp * tmp) % mod;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long gcd(long long a, long long b, long long &x, long long &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long g = gcd(b % a, a, x, y);
  long long y0 = y;
  long long x0 = x;
  x = y0 - (b / a) * x0;
  y = x0;
  return g;
}
signed main() {
  iostream::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  srand(time(NULL));
  vector<long long> calc(MAXN);
  long long M = 1e6;
  calc[0] = 1;
  for (long long i = 1; i <= M; i++) {
    calc[i] = (calc[i - 1] * 2) % MOD;
  }
  long long n;
  cin >> n;
  vector<long long> input(MAXN, 0);
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    input[x]++;
  }
  for (long long i = 1; i <= M; i++) {
    for (long long j = i * 2; j <= M; j += i) {
      input[i] += input[j];
    }
  }
  for (long long i = 1; i <= M; i++) {
    if (input[i] == 0) continue;
    input[i] = (calc[input[i] - 1] * input[i]) % MOD;
  }
  long long ans = 0;
  for (long long i = M; i > 1; i--) {
    for (long long j = 2 * i; j <= M; j += i)
      input[i] = (input[i] + MOD - input[j]) % MOD;
    ans += input[i] * i;
    ans %= MOD;
  }
  cout << ans % MOD << "\n";
}

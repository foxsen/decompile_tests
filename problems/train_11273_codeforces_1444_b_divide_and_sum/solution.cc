#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long fact(long long n) {
  if (n == 0) return 1;
  return n * fact(n - 1) % mod;
}
long long power(long long a, long long b, long long c) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return res;
}
long long ncr(long long n, long long r) {
  long long num = fact(n);
  long long den = fact(r) * fact(n - r) % mod;
  den = power(den, mod - 2, mod);
  num = num * den % mod;
  return num;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n * 2);
  for (long long i = 0; i < n * 2; i++) cin >> v[i];
  sort(v.begin(), v.end());
  long long tot = 0;
  for (long long i = 0, j = n * 2 - 1; i < j; i++, j--) {
    tot += v[j] - v[i];
    tot %= mod;
  }
  tot *= ncr(n * 2, n);
  tot %= mod;
  cout << tot << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
}

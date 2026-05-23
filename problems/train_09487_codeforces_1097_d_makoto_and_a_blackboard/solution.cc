#include <bits/stdc++.h>
using namespace std;
void start_func() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
map<long long, long long> factors;
long long dp[65][10001];
void primeFactors(long long n) {
  while (n % 2 == 0) {
    factors[2]++;
    n = n / 2;
  }
  for (long long i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      factors[i]++;
      n = n / i;
    }
  }
  if (n > 2) {
    factors[n]++;
  }
}
long long powmod(long long a, long long n) {
  if (!n) return 1;
  long long p = powmod(a, n / 2);
  p = (p * p) % 1000000007;
  if (n & 1) return (p * a) % 1000000007;
  return p;
}
long long FindNumDen(long long num, long long power, long long k) {
  if (dp[power][k] != -1) return dp[power][k];
  if (power == 0) return dp[power][k] = 1;
  if (k == 0) return dp[power][k] = pow(num, power);
  long long numer = 0, den = power + 1;
  for (long long p = 0; p <= power; ++p) {
    numer = (numer + FindNumDen(num, p, k - 1)) % 1000000007;
  }
  return dp[power][k] = (numer * powmod(den, 1000000007 - 2)) % 1000000007;
}
int32_t main() {
  start_func();
  long long n, k;
  cin >> n >> k;
  primeFactors(n);
  long long final = 1;
  for (auto &p : factors) {
    long long num = p.first;
    long long power = p.second;
    memset(dp, -1, sizeof(dp));
    long long ans = FindNumDen(num, power, k);
    final = (final * ans) % 1000000007;
  }
  cout << final << '\n';
  return 0;
}

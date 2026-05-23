#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
map<long long, long long> res, res1;
void prime_factor(long long n) {
  for (long long i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      res[i]++;
      n /= i;
    }
  }
  if (n != 1) res[n]++;
  return;
}
long long pow(long long a, long long n) {
  long long x = 1;
  while (n > 0) {
    if (n & 1) {
      x = ((x % MOD) * (a % MOD)) % MOD;
    }
    a = ((a % MOD) * (a % MOD)) % MOD;
    n >>= 1;
  }
  return x % MOD;
}
int main() {
  long long x, n, ans = 1;
  cin >> x >> n;
  prime_factor(x);
  for (auto i : res) {
    long long a = n;
    while (a >= i.first) {
      ans *= pow(i.first, (a / i.first)) % MOD;
      ans %= MOD;
      a /= i.first;
    }
  }
  cout << ans % MOD << endl;
  return 0;
}

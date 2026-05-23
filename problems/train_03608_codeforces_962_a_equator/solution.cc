#include <bits/stdc++.h>
using namespace std;
long long int fastExpo(long long int a, long long int n, long long int mod) {
  long long int result = 1;
  while (n > 0) {
    if (n & 1) result = (result * a) % mod;
    a = (a * a) % mod;
    n >>= 1;
  }
  return result;
}
long long int modInverse(long long int n, long long int mod) {
  return fastExpo(n, mod - 2, mod);
}
vector<long long int> factorial(long long int n) {
  std::vector<long long int> fac(n + 2, 0);
  fac[0] = 1;
  for (long long int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % 1000000007;
  return fac;
}
long long int __nCr(long long int n, long long int r,
                    vector<long long int>& Fact, long long int mod) {
  long long int ans = (((Fact[n] * modInverse(Fact[r], mod)) % mod) *
                       modInverse(Fact[n - r], mod)) %
                      mod;
  return ans;
}
void runcases(long long int T) {
  long long int n;
  cin >> n;
  vector<long long int> v(n);
  long long int sum = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
  }
  long long int l = 0;
  for (long long int i = 0; i < n; i++) {
    l += v[i];
    if (2 * l >= sum) {
      cout << (i + 1) << "\n";
      return;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int T = 1;
  for (long long int t = 1; t <= T; t++) {
    runcases(t);
  }
  return 0;
}

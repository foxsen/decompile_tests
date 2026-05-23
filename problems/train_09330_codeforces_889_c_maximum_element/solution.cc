#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const long long MOD = 1e9 + 7;
long long d[N], psum[N], fact[N], ifact[N], n, k, ans, tmp;
long long bigExp(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  fact[0] = 1;
  for (int i = 1; i <= n; i++) fact[i] = (fact[i - 1] * i) % MOD;
  ifact[n] = bigExp(fact[n], MOD - 2);
  for (int i = n - 1; i >= 0; i--) ifact[i] = (ifact[i + 1] * (i + 1)) % MOD;
  assert(bigExp(fact[25], MOD - 2) == ifact[25]);
  for (int i = k + 1; i <= n; i++) {
    d[i] = ((i - k - 1) + (psum[i - 1] - psum[i - k - 1] + MOD)) % MOD;
    d[i] = (d[i] * fact[i - 2]) % MOD;
    psum[i] = (psum[i - 1] + d[i] * ifact[i - 1]) % MOD;
  }
  for (int i = 1; i <= n; i++) {
    tmp = (d[i] * fact[n - 1]) % MOD;
    tmp = (tmp * ifact[i - 1]) % MOD;
    ans = (ans + tmp) % MOD;
  }
  cout << ans << "\n";
  return 0;
}

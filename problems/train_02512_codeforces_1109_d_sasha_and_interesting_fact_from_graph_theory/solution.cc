#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)1e9 + 7;
const int N = 1e6 + 5, inf = 1e9 + 5;
long long add(long long x, long long y) {
  x += y;
  if (x >= MOD) return x - MOD;
  return x;
}
long long sub(long long x, long long y) {
  x -= y;
  if (x < 0) return x + MOD;
  return x;
}
long long mult(long long x, long long y) { return (x * y) % MOD; }
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long mod_pow(long long x, long long e) {
  long long ans = 1;
  while (e > 0) {
    if (e & 1) ans = mult(ans, x);
    x = mult(x, x);
    e >>= 1;
  }
  return ans;
}
long long fact[N], inv_fact[N];
void pre_fact() {
  fact[0] = inv_fact[0] = 1;
  for (long long i = 1; i <= N; ++i) {
    fact[i] = mult(fact[i - 1], i);
    inv_fact[i] = mod_pow(fact[i], MOD - 2);
  }
}
long long binom(long long n, long long k) {
  if (k == 0) return 1;
  return mult(fact[n], mult(inv_fact[k], inv_fact[n - k]));
}
long long cayley(long long n, long long k) {
  if (n - k - 1 < 0) return 1;
  return mult(k, mod_pow(n, n - k - 1));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m, a, b;
  cin >> n >> m >> a >> b;
  long long ans = 0;
  pre_fact();
  for (long long k = 1; k < min(n, m + 1); ++k) {
    long long curr = 1;
    curr = mult(curr, binom(m - 1, k - 1));
    curr = mult(curr, mod_pow(m, n - 1 - k));
    curr = mult(curr, cayley(n, k + 1));
    curr = mult(curr, mult(fact[n - 2], inv_fact[n - 2 - (k - 1)]));
    ans = add(ans, curr);
  }
  cout << ans << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
int n;
long long s;
long long f[22];
long long mult(long long a, long long b) { return (a * b) % mod; }
long long add(long long a, long long b) { return (a + b) % mod; }
long long inv(long long n) {
  long long ret = 1;
  for (int i = 0; (1LL << i) <= mod - 2; ++i) {
    if ((((mod - 2) >> i) & 1) == 1) ret = mult(ret, n);
    n = mult(n, n);
  }
  return ret;
}
long long I[22];
long long ways(long long s, int n) {
  long long ret = 1;
  for (long long i = s + n - 1; i > s; --i) ret = mult(ret, i % mod);
  for (long long i = n - 1; i >= 1; --i) ret = mult(ret, I[i]);
  return ret;
}
int main(void) {
  cin >> n >> s;
  for (int i = 0; i < n; ++i) cin >> f[i];
  for (int i = 1; i < n; ++i) I[i] = inv(i);
  long long sol = 0;
  for (int mask = 0; mask < (1 << n); ++mask) {
    long long rem = 0;
    for (int i = 0; i < n; ++i)
      if (((mask >> i) & 1) == 1) rem += f[i] + 1;
    if (s - rem < 0) continue;
    int sgn = (__builtin_popcount(mask) % 2) ? -1 : +1;
    sol = add(sol, add(mod, sgn * ways(s - rem, n)));
  }
  cout << sol << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
void FastIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long modpow(long long a, long long p, long long mod) {
  long long ret = 1;
  while (p) {
    if (p & 1) ret = (ret * a) % mod;
    a = (a * a) % mod;
    p /= 2;
  }
  return ret;
}
long long power(long long a, long long p) {
  long long ret = 1;
  while (p) {
    if (p & 1) ret = (ret * a);
    a = (a * a);
    p /= 2;
  }
  return ret;
}
long long fib(long long n, long long mod = LLONG_MAX) {
  long long fib[2][2] = {{1, 1}, {1, 0}}, ret[2][2] = {{1, 0}, {0, 1}},
            tmp[2][2] = {{0, 0}, {0, 0}};
  long long i, j, k;
  while (n) {
    if (n & 1) {
      memset(tmp, 0, sizeof(tmp));
      for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
          for (int k = 0; k < 2; k++)
            tmp[i][j] = (tmp[i][j] + (ret[i][k] * fib[k][j]) % mod) % mod;
      for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) ret[i][j] = tmp[i][j];
    }
    memset(tmp, 0, sizeof(tmp));
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
        for (int k = 0; k < 2; k++)
          tmp[i][j] = (tmp[i][j] + (fib[i][k] * fib[k][j]) % mod) % mod;
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++) fib[i][j] = tmp[i][j];
    n /= 2;
  }
  return (ret[0][1]);
}
int main() {
  FastIO();
  long long n, k, l, m;
  cin >> n >> k >> l >> m;
  long long ans = 1;
  long long f = fib(n + 2, m);
  long long p = (modpow(2LL, n, m) - f + m) % m;
  if (l < 63 && (1LL << l) <= k) {
    cout << 0 << '\n';
    return 0;
  }
  ans %= m;
  for (int i = 0; i < l; i++) {
    if ((k >> i) & 1LL)
      ans = (ans * p) % m;
    else
      ans = (ans * f) % m;
  }
  cout << ans << '\n';
  return 0;
}

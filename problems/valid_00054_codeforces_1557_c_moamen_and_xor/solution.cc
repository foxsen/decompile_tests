#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, y = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') y = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * y;
}
long long b[100005];
long long c[100005];
const int mod = 1e9 + 7;
long long qpow(long long x, long long y) {
  long long res = 1, m = x;
  while (y) {
    if (y & 1) res = (res * m) % mod;
    m = (m * m) % mod;
    y >>= 1;
  }
  return res;
}
int main() {
  int T = read();
  while (T--) {
    long long n = read(), k = read();
    if (n & 1) {
      long long ans = qpow(2, n - 1);
      ans = (ans + 1) % mod;
      ans = qpow(ans, k);
      printf("%lld\n", ans);
    } else {
      long long ans = 1;
      long long m = 1;
      for (int i = 1; i <= k; i++) {
        ans = ((ans * (qpow(2, n - 1) - 1)) % mod + m) % mod;
        m = (m * qpow(2, n)) % mod;
      }
      ans = ((ans % mod) + mod) % mod;
      printf("%lld\n", ans);
    }
  }
  return 0;
}

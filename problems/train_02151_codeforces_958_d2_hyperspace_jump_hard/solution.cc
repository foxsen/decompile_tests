#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline int getint() {
  int ret = 0;
  bool ok = 0, neg = 0;
  for (;;) {
    int c = getchar();
    if (c >= '0' && c <= '9')
      ret = (ret << 3) + ret + ret + c - '0', ok = 1;
    else if (ok)
      return neg ? -ret : ret;
    else if (c == '-')
      neg = 1;
  }
}
int m, d, n;
long long base[10][10], a[10];
map<long long, int> hs;
int main() {
  m = getint();
  d = getint();
  for (int zz = 0; zz < m; zz++) {
    int c = getint();
    for (int j = 0; j < d; j++)
      for (int k = 0; k < d; k++) base[j][k] = 0;
    for (int z = 0; z < c; z++) {
      for (int k = 0; k < d; k++) {
        a[k] = getint();
        if (a[k] < 0) a[k] += mod;
      }
      for (int j = 0; j < d; j++) {
        if (!a[j]) continue;
        if (base[j][j]) {
          long long w = mod - a[j];
          for (int k = j; k < d; k++) a[k] = (a[k] + w * base[j][k]) % mod;
        } else {
          long long w = powmod(a[j], mod - 2);
          for (int k = j; k < d; k++) base[j][k] = a[k] * w % mod;
          break;
        }
      }
    }
    for (int j = 0; j < d; j++)
      if (base[j][j]) {
        for (int i = 0; i < j; i++)
          if (base[i][j]) {
            long long w = mod - base[i][j];
            for (int k = j; k < d; k++) {
              base[i][k] = (base[i][k] + w * base[j][k]) % mod;
            }
          }
      }
    long long p = 0;
    for (int j = 0; j < d; j++) {
      for (int k = 0; k < d; k++) p = p * 13331 + base[j][k];
    }
    if (!hs.count(p)) hs[p] = ++n;
    printf("%d ", hs[p]);
  }
}

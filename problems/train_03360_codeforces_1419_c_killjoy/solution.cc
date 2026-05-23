#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y) {
  if (y == 0)
    return 1;
  else if (y % 2 == 0)
    return (power(x, y / 2) * power(x, y / 2)) % 998244353;
  else
    return ((x * power(x, y / 2)) % 998244353 * power(x, y / 2)) % 998244353;
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long modInverse(long long n, long long p) { return power(n, p - 2, p); }
long long fac[100000 + 1];
void pre(long long p) {
  fac[0] = 1;
  for (long long i = 1; i <= 100000; i++) fac[i] = (fac[i - 1] * i) % p;
}
long long nCrModPFermat(long long n, long long r, long long p) {
  if (r == 0) return 1;
  if (r > n) return 0;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t, n, i, j, x, ans;
  cin >> t;
  while (t--) {
    cin >> n >> x;
    long long a[n];
    cin >> a[0];
    long long s = a[0] - x;
    long long f = 0;
    if (a[0] == x) f = 1;
    long long flag = 0;
    for (i = 1; i < n; i++) {
      cin >> a[i];
      if (a[i] == x) f = 1;
      if (a[0] != a[i]) {
        flag = 1;
      }
      s += a[i] - x;
    }
    if (flag == 0 && a[0] == x) {
      cout << 0;
    } else if (s == 0 || f == 1) {
      cout << 1;
    } else
      cout << 2;
    cout << "\n";
  }
  cerr << (1000 * clock()) / CLOCKS_PER_SEC << "ms";
  return 0;
}

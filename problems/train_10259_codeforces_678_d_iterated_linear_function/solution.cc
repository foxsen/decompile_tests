#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long power(long long x, unsigned long long y) {
  long long temp;
  if (y == 0) return 1;
  temp = power(x, y / 2) % mod;
  if (y % 2 == 0)
    return (temp % mod * temp % mod) % mod;
  else
    return ((x % mod * temp) % mod * temp) % mod;
}
long long mod_inv(long long a) { return power(a, mod - 2); }
int main() {
  long long a, b, n, x;
  cin >> a >> b >> n >> x;
  long long z = n % mod;
  if (a != 1)
    z = (((power(a, n) - 1) % mod + mod) % mod * mod_inv((a - 1))) % mod;
  cout << ((power(a, n) * x) % mod + b * z) % mod;
  return 0;
}

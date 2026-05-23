#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long inv(long long x) { return power(x, MOD - 2, MOD); }
int main() {
  long long n;
  long long m;
  cin >> n >> m;
  long long mult = inv(m + 1);
  mult *= n;
  mult += 1;
  mult %= MOD;
  long long out = m + 1;
  for (int i = 2; i <= n; i++) {
    long long add = m * inv(i);
    add %= MOD;
    out += add;
    out %= MOD;
  }
  out *= mult;
  out %= MOD;
  cout << out << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long inv_euclid(long long a, long long m = 998244353) {
  long long m0 = m;
  long long y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long q = a / m;
    long long t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
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
long long max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long min(long long a, long long b) {
  if (a < b) return a;
  return b;
}
long long ssum(long long n) { return (n * (n + 1)) / 2; }
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    string s = "";
    for (long long i = 0; i < a + 1; i++) {
      s += "0";
    }
    for (long long i = 0; i < c + 1; i++) {
      s += "1";
    }
    for (long long i = 0; i < b - 1; i++) {
      s += ((i % 2) + '0');
    }
    if (a == 0 && b == 0) {
      for (long long i = 0; i < c + 1; i++) cout << "1";
      cout << "\n";
      continue;
    }
    if (c == 0 && b == 0) {
      for (long long i = 0; i < a + 1; i++) cout << "0";
      cout << "\n";
      continue;
    }
    cout << s << "\n";
  }
}

#include <bits/stdc++.h>
using namespace std;
const long long mod1 = static_cast<long long>(1073741824);
const long long mod2 = static_cast<long long>(1000000007);
const long long INF = 1ll * 1000 * 1000 * 1000 * 1000 * 1000 * 1000 + 7;
const long double ldOne = 1.0;
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x %= p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long exp(long long x, long long n) {
  if (n == 0)
    return 1;
  else if (n & 1)
    return x * exp(x * x, (n - 1) / 2);
  else
    return exp(x * x, n / 2);
}
bool isPrime(long long n) {
  for (long long i = 0; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
vector<long long> SieveOfEratosthenes(long long n) {
  vector<bool> prime(n + 1, true);
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p]) {
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  vector<long long> v;
  for (long long i = 2; i <= n; i++) {
    if (prime[i]) v.push_back(i);
  }
  return v;
}
map<long long, long long> PrimeFactorization(long long n) {
  vector<long long> v = SieveOfEratosthenes(static_cast<long long>(sqrt(n)));
  map<long long, long long> m;
  for (unsigned long long i = 0; i < v.size(); i++) {
    if (n % v[i] == 0) {
      n /= v[i];
      m[v[i]]++;
      i--;
    }
  }
  return m;
}
long long nCr(long long n, long long r) {
  vector<long long> c(r + 1, 0);
  c[0] = 1;
  for (long long i = 0; i < n + 1; i++) {
    for (long long j = min(i, r); j > 0; j--) c[j] = c[j - 1] + c[j];
  }
  return c[r];
}
long long num(char a) {
  switch (a) {
    case '0':
      return 2;
    case '1':
      return 7;
    case '2':
      return 2;
    case '3':
      return 3;
    case '4':
      return 3;
    case '5':
      return 4;
    case '6':
      return 2;
    case '7':
      return 5;
    case '8':
      return 1;
    case '9':
      return 2;
  }
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  long long multi = 1;
  for (long long i = 0; i < static_cast<long long>(s.length()); i++) {
    multi *= num(s[i]);
  }
  cout << multi;
  cerr << "Time : " << 1000 * (long double)clock() / (long double)CLOCKS_PER_SEC
       << "ms\n";
  ;
  return 0;
}

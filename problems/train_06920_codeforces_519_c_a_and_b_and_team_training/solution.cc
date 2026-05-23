#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long mod(long long a, long long b) {
  if (a > b)
    return (a - b);
  else
    return (b - a);
}
double distance(long long x1, long long y1, long long x2, long long y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}
long long fact(long long n) {
  long long res = 1;
  for (long long i = 2; i <= n; i++) res = res * i;
  return res;
}
long long nCr(long long n, long long r) {
  return fact(n) / (fact(r) * fact(n - r));
}
bool isPerfectSquare(long double x) {
  long double sr = sqrt(x);
  return ((sr - floor(sr)) == 0);
}
bool palindrome(string s, long long i, long long j) {
  if (i > j) return true;
  if (s[i] != s[j])
    return false;
  else
    return palindrome(s, i + 1, j - 1);
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
bool isPowerOfTwo(long long n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long n, m;
  cin >> n >> m;
  if (min(n, m) * 2 <= max(n, m)) {
    cout << min(m, n);
  } else {
    long long a, b;
    a = min(n, m);
    b = max(n, m);
    long long cnt = 0;
    cnt += (b - a);
    a = a - (b - a);
    cnt += (2 * a) / 3;
    cout << cnt;
  }
  return 0;
}

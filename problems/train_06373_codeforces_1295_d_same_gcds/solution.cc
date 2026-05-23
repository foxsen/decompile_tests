#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  register long long x = 0, f = 1;
  register char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = 0;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + (ch ^ '0');
    ch = getchar();
  }
  return f ? x : -x;
}
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline long long phi(long long n) {
  long long ans = n;
  for (long long i = 2; i <= sqrt(n); ++i)
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      ans /= i, ans *= (i - 1);
    }
  if (n > 1) ans /= n, ans *= (n - 1);
  return ans;
}
int main() {
  for (int t = (1), _ed = (read()); t <= _ed; ++t) {
    long long a = read(), m = read();
    printf("%lld\n", phi(m / gcd(a, m)));
  }
  return 0;
}

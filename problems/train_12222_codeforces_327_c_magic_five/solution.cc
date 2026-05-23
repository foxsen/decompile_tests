#include <bits/stdc++.h>
using namespace std;
string s;
int n;
long long inverse(long long a, long long b, long long *X, long long *Y) {
  if (b == 0) {
    *X = 1;
    *Y = 0;
    return a;
  } else {
    long long xx, yy;
    long long ret = inverse(b, a % b, &xx, &yy);
    *X = yy;
    *Y = xx - (a / b) * yy;
    return ret;
  }
}
long long power(int base, int exp) {
  if (exp == 0) return 1LL;
  if (exp % 2) return (power(base, exp - 1) * base) % 1000000007;
  long long x = power(base, exp / 2);
  return (x * x) % 1000000007;
}
int main() {
  cin >> s >> n;
  int len = s.size();
  long long r = power(2, len);
  long long ans = 0;
  for (int i = 0; i < len; i++) {
    if (s[i] == '0' || s[i] == '5') {
      long long ppp =
          ((power(2, i) * ((power(r, n) - 1 + 1000000007) % 1000000007)) %
           1000000007);
      long long x, y;
      inverse(r - 1, 1000000007, &x, &y);
      x = (x + 1000000007) % 1000000007;
      ppp = ppp * x;
      ppp %= 1000000007;
      ans += ppp;
      ans %= 1000000007;
    }
  }
  cout << ans << endl;
}

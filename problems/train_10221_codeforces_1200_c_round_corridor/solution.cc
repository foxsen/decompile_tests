#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1000000007;
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return a / gcd(a, b) * b;
}
long long int power(long long int a, long long int n) {
  if (n == 0) return 1;
  long long int p = power(a, n / 2);
  p = (p * p) % MOD;
  if (n % 2)
    return (p * a) % MOD;
  else
    return p % MOD;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long int test = 1;
  while (test--) {
    long long int n, m, q;
    cin >> n >> m >> q;
    long long int c = gcd(n, m);
    long long int q1 = n / c;
    long long int q2 = m / c;
    while (q--) {
      long long int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      y1--;
      y2--;
      long long int secno1, secno2;
      if (x1 == 1) {
        secno1 = y1 / q1;
      } else {
        secno1 = y1 / q2;
      }
      if (x2 == 1) {
        secno2 = y2 / q1;
      } else {
        secno2 = y2 / q2;
      }
      if (secno1 != secno2) {
        cout << "NO";
      } else {
        cout << "YES";
      }
      cout << '\n';
    }
  }
  return 0;
}

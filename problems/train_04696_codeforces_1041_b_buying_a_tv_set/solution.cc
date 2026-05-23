#include <bits/stdc++.h>
using namespace std;
long long a, b, x, y;
long long gcd(long long p, long long q) {
  if (q == 0)
    return p;
  else
    return gcd(q, p % q);
}
int main() {
  cin >> a >> b >> x >> y;
  long long p = gcd(x, y);
  x /= p;
  y /= p;
  long long u = a / x, v = b / y;
  cout << min(u, v);
  return 0;
}

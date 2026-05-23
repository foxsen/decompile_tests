#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
long long a, b, xx, yy, XX, YY;
long long divf(long long n, long long q) {
  if (n >= 0) return n / q;
  long long r = n / q;
  if (r * q > n) r--;
  return r;
}
int main() {
  cin >> a >> b >> xx >> yy >> XX >> YY;
  long long k1 = abs(divf(xx + yy, 2 * a) - divf(XX + YY, 2 * a));
  long long k2 = abs(divf(xx - yy, 2 * b) - divf(XX - YY, 2 * b));
  cout << max(k1, k2) << endl;
  return 0;
}

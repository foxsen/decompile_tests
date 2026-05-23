#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b, long long& x, long long& y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  long long ans = gcd(b, a % b, x, y);
  int temp = x;
  x = y;
  y = temp - a / b * y;
  return ans;
}
int main() {
  long long a, b, c, d, x, y;
  cin >> a >> b >> c;
  d = gcd(a, b, x, y);
  if (c % d != 0)
    cout << -1 << endl;
  else
    cout << -x * (c / d) << " " << -y * (c / d) << endl;
  return 0;
}

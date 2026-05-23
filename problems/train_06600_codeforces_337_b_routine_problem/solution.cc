#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000")
int a, b, c, d;
int gcd(int x, int y) {
  if (!y) return x;
  return gcd(y, x % y);
}
int main() {
  cin >> a >> b >> c >> d;
  int d1 = gcd(a, b), d2 = gcd(c, d);
  a /= d1, b /= d1;
  c /= d2;
  d /= d2;
  int d3 = b * d / gcd(b, d);
  if ((a * d3 / b) >= (c * d3 / d)) {
    int aa = a * d3 / b - c * d3 / d, bb = a * d3 / b, dd = gcd(aa, bb);
    cout << aa / dd << "/" << bb / dd << endl;
    return 0;
  }
  int d4 = a * c / gcd(a, c);
  if ((b * d4 / a) > (d * d4 / c)) {
    int aa = b * d4 / a - d * d4 / c, bb = b * d4 / a, dd = gcd(aa, bb);
    cout << aa / dd << "/" << bb / dd << endl;
  }
}

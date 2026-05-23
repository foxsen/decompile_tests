#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) { return y == 0 ? x : gcd(y, x % y); }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long p, q, b;
  int n;
  cin >> n;
  while (n--) {
    cin >> p >> q >> b;
    long long x = p / gcd(p, q);
    long long y = q / gcd(p, q);
    long long cheek = gcd(y, b);
    while (y != 1 && cheek != 1) {
      while (y % cheek == 0) y /= cheek;
      cheek = gcd(b, y);
    }
    if (y == 1)
      cout << "Finite\n";
    else
      cout << "Infinite\n";
  }
}

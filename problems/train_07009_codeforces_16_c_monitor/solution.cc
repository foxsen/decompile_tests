#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const int N = 5e4 + 10;
int gcd(int n, int m) { return m == 0 ? n : gcd(m, n % m); }
int main() {
  int a, b, x, y;
  cin >> a >> b >> x >> y;
  int g = gcd(x, y);
  x /= g;
  y /= g;
  int ratio = min(a / x, b / y);
  cout << x * ratio << ' ' << y * ratio << endl;
  return 0;
}

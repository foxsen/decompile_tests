#include <bits/stdc++.h>
using namespace std;
long long t, d, ct, q, ans, l, m, r, n, mx, mn, i, j, k, x, y, z, s;
char ch;
string ss = "", str = "";
map<long long, long long> mp;
long long a[200003], b[200003];
long long power(long long a, long long b) {
  long long res = 1;
  for (long long i = 1; i <= b; i++) res *= a;
  return res;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  cin >> t;
  while (t--) {
    s = k = d = l = mx = m = mn = r = q = i = j = z = x = y = ct = ans = 0;
    cin >> x >> y;
    mx = 1;
    set<long long> st;
    if (y > x || x % y != 0) {
      cout << x << "\n";
      continue;
    }
    m = x;
    d = 1000000000000000000;
    for (i = 2; i * i <= y; i++) {
      if (y % i == 0) {
        s = 0;
        while (y % i == 0) y /= i, s++;
        k = 0;
        while (x % i == 0) x /= i, k++;
        d = min(d, power(i, k - s + 1));
      }
    }
    if (y > 1) {
      k = y;
      s = 0;
      while (x % k == 0) x /= k, s++;
      d = min(d, power(k, s));
    }
    cout << m / d << "\n";
  }
  return 0;
}

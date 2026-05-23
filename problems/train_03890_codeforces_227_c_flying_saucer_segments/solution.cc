#include <bits/stdc++.h>
using namespace std;
long long u, v;
long long quickpow(long long m, long long n, long long k) {
  long long b = 1;
  while (n > 0) {
    if (n & 1) b = (b * m) % k;
    n = n >> 1;
    m = (m * m) % k;
  }
  return b;
}
int main() {
  while (cin >> u >> v) {
    if (u == 0) {
      cout << "0" << endl;
      continue;
    }
    long long ans = quickpow(3, u, v);
    if (ans == 0)
      ans = v - 1;
    else
      ans -= 1;
    cout << ans << endl;
  }
  return 0;
}

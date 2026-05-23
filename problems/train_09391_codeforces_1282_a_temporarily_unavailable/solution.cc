#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 2e5 + 100;
const int INF = 0x3f3f3f3f;
inline long long dpow(long long a, long long b) {
  long long r = 1, t = a;
  while (b) {
    if (b & 1) r = (r * t) % MOD;
    b >>= 1;
    t = (t * t) % MOD;
  }
  return r;
}
inline long long fpow(long long a, long long b) {
  long long r = 1, t = a;
  while (b) {
    if (b & 1) r = (r * t);
    b >>= 1;
    t = (t * t);
  }
  return r;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > b) swap(a, b);
    long long L = c - d, R = c + d;
    if (R < a)
      cout << b - a << endl;
    else if (L > b)
      cout << b - a << endl;
    else {
      long long ans = 0;
      if (L > a) ans += L - a;
      if (R < b) ans += b - R;
      cout << ans << endl;
    }
  }
  return 0;
}

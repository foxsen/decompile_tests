#include <bits/stdc++.h>
using namespace std;
long long mo(long long a) { return a % (long long)(1e9 + 7); }
long long po(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y >>= 1;
    x = (x * x) % p;
  }
  return res % p;
}
struct celeb {
  long long x, y, t;
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long r, n;
  cin >> r >> n;
  vector<long long> dp(n + 1, -1e18), mx(n + 1, 0), t(n + 1), x(n + 1),
      y(n + 1);
  dp[0] = 0;
  x[0] = 1;
  y[0] = 1;
  for (long long i = 1; i <= n; i++) {
    cin >> t[i] >> x[i] >> y[i];
    for (long long j = i - 1; j >= 0; j--) {
      if (t[i] - t[j] >= abs(x[i] - x[j]) + abs(y[i] - y[j])) {
        if (t[i] - t[j] >= 2 * r) {
          dp[i] = max(dp[i], 1 + mx[j]);
          break;
        } else {
          dp[i] = max(dp[i], 1 + dp[j]);
        }
      }
    }
    mx[i] = max(mx[i - 1], dp[i]);
  }
  long long ans = *max_element(dp.begin(), dp.end());
  cout << ans << "\n";
  return 0;
}

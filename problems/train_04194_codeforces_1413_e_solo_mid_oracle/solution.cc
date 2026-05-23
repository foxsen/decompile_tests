#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1;
const long long INFLL = 1e18 + 1;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long left = 0, right = INF;
    while (right - left > 1) {
      long long mid = (left + right) / 2;
      if (a - b * min(c, mid * d) > 0)
        left = mid;
      else
        right = mid;
    }
    if (left == INF - 1) {
      cout << -1 << "\n";
      continue;
    }
    if (left == 0) {
      cout << a << "\n";
      continue;
    }
    long long x = left + 1;
    long long ans = a * x;
    long long k = (c + d - 1) / d;
    long long cnt1 = max(0LL, x - 1 - (k - 1));
    long long cnt2 = x - 1 - cnt1;
    long long sum1 = c * cnt1;
    long long sum2 = 0;
    if (cnt2 > 0) {
      long long p = min(k - 1, cnt2);
      sum2 = ((p + 1) * d * p) / 2;
    }
    cout << ans - b * sum1 - b * sum2 << "\n";
  }
  return 0;
}

#include <bits/stdc++.h>
long long inf = 2e18;
long long minf = -inf;
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  cin >> n;
  long long ans = 0;
  while (n--) {
    long long a, b, c;
    cin >> a >> b >> c;
    long long bru = a * x1 + b * y1 + c;
    long long bro = a * x2 + b * y2 + c;
    if (bro > 0 and bru < 0) ans++;
    if (bro < 0 and bru > 0) ans++;
  }
  cout << ans << endl;
}

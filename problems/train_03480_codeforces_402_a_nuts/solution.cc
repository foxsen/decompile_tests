#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  int k, a, b, v;
  cin >> k >> a >> b >> v;
  int ans = 0;
  while (a > 0) {
    ++ans;
    if (b + 1 <= k) {
      a -= (b + 1) * v;
      b = 0;
    } else {
      a -= k * v;
      b -= k - 1;
    }
  }
  cout << ans << endl;
  return 0;
}

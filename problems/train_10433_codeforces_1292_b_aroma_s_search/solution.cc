#include <bits/stdc++.h>
using namespace std;
const long long N = 76;
long long x[N], y[N];
long long ax, ay, bx, by, xs, ys, t, cntx, cnty, ans = 0;
signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> x[0] >> y[0] >> ax >> ay >> bx >> by >> xs >> ys >> t;
  for (cntx = 1; x[cntx - 1] <= 5e16; ++cntx) x[cntx] = ax * x[cntx - 1] + bx;
  for (cnty = 1; y[cnty - 1] <= 5e16; ++cnty) y[cnty] = ay * y[cnty - 1] + by;
  for (long long i = 0; i <= min(cntx, cnty) - 1; ++i) {
    long long tmp = abs(xs - x[i]) + abs(ys - y[i]);
    if (tmp > t) continue;
    for (long long j = i - 1; ~j; --j) {
      tmp += abs(x[j + 1] - x[j]) + abs(y[j + 1] - y[j]);
      if (tmp > t) {
        ans = max(ans, i - j);
        break;
      }
    }
    if (tmp > t) continue;
    long long pre = 0;
    for (long long j = i + 1;; j++) {
      tmp += abs(x[j] - x[pre]) + abs(y[j] - y[pre]);
      if (tmp > t) {
        ans = max(ans, j);
        break;
      }
      pre = j;
    }
  }
  cout << ans << '\n';
  return 0;
}

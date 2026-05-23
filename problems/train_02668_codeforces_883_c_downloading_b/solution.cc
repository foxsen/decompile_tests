#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e7 + 5;
constexpr long long LINF = 1e18;
int main() {
  ios::sync_with_stdio(false);
  long long f, t, t0;
  cin >> f >> t >> t0;
  long long a1, t1, p1;
  cin >> a1 >> t1 >> p1;
  long long a2, t2, p2;
  cin >> a2 >> t2 >> p2;
  auto bs = [&](long long data, long long time) -> long long {
    if (data * t0 > time && data * t2 > time) return LINF;
    long long l = 0, r = (data + (a2 - 1)) / a2;
    while (l < r) {
      long long mid = (l + r) >> 1;
      long long usage = min(mid * a2, data);
      if (usage * t2 + (data - usage) * t0 <= time)
        r = mid;
      else
        l = mid + 1;
    }
    return l * p2;
  };
  long long ans = LINF;
  for (int usage = 0; usage < f + 1; usage++) {
    long long lfdata = f - usage, lftime = t - usage * t1,
              price = (usage + (a1 - 1)) / a1 * p1;
    if (t0 <= t2) {
      if (lfdata * t0 <= lftime) ans = min(ans, price);
    } else
      ans = min(ans, price + bs(lfdata, lftime));
  }
  cout << (ans != LINF ? ans : -1) << endl;
}

#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
long long int power(long long int x, long long int y,
                    long long int mod = 1000000007) {
  long long int ret = 1;
  x = x % mod;
  while (y) {
    if (y & 1) ret = (ret * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return ret % mod;
}
long long int curbest(long long int d, long long int x) {}
void solve() {
  long long int th, tc, x;
  cin >> th >> tc >> x;
  long long int low = 0;
  long long int high = 1e12;
  auto val = [&](long long int mid) {
    long double ret = 1;
    ret = (long double)(mid * (tc + th) - tc) / (2 * mid - 1);
    return abs(x - ret);
  };
  long double eqdiff = (long double)x - (long double)(tc + th) / 2;
  if (2 * x == tc + th) {
    cout << 2 << endl;
    return;
  }
  if (x == th) {
    cout << 1 << endl;
    return;
  }
  while (low + 1 < high) {
    long long int mid = (high - low + 1) / 2 + low;
    if (val(mid) <= val(mid + 1)) {
      high = mid;
    } else
      low = mid;
    if (mid == (high - low + 1) / 2 + low) break;
  }
  low++;
  long double bd = val(low);
  long long int turn = 2 * low - 1;
  long long int lturn = turn;
  for (long long int i = max(1ll, lturn - 1000); i < lturn + 1000; i += 2) {
    if (val(i / 2) < bd) {
      bd = val(i);
      turn = i;
    }
  }
  if (bd < eqdiff) {
    cout << turn << endl;
  } else {
    cout << 2 << endl;
  }
}
signed main() {
  long long int t;
  cin >> t;
  while (t--) solve();
}

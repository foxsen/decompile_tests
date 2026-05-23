#include <bits/stdc++.h>
namespace loquat {
namespace bitmanip {
template <typename T>
inline auto ctz(T x) noexcept -> T {
  return __builtin_ctzll(x);
}
template <typename T>
inline auto clz(T x) noexcept -> T {
  return __builtin_clzll(x);
}
template <typename T>
inline T flp2(T x) noexcept {
  if (x == 0u) {
    return 0u;
  }
  return T(1u) << (sizeof(T) * 8u - 1u - clz(x));
}
}  // namespace bitmanip
}  // namespace loquat
using namespace std;
using ll = long long;
int main() {
  const int n = 62;
  vector<ll> shift(n);
  int q;
  scanf("%d", &q);
  while (q--) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      ll x, k;
      scanf("%lld%lld", &x, &k);
      const int t = loquat::bitmanip::ctz(loquat::bitmanip::flp2(x));
      k &= ((1ll << t) - 1);
      shift[t] = (shift[t] + k) & ((1ll << t) - 1);
    } else if (type == 2) {
      ll x, k;
      scanf("%lld%lld", &x, &k);
      const int t = loquat::bitmanip::ctz(loquat::bitmanip::flp2(x));
      k &= ((1ll << t) - 1);
      for (int i = t; i < n; ++i) {
        const ll ki = (k << (i - t));
        shift[i] = (shift[i] + ki) & ((1ll << i) - 1);
      }
    } else if (type == 3) {
      ll x;
      scanf("%lld", &x);
      const int t = loquat::bitmanip::ctz(loquat::bitmanip::flp2(x));
      x ^= (1ll << t);
      x = (x + shift[t]) & ((1ll << t) - 1);
      for (int i = t; i >= 0; --i) {
        const ll p = (x - shift[i]) & ((1ll << i) - 1);
        printf("%lld ", (p + (1ll << i)));
        x >>= 1;
      }
      printf("\n");
    }
  }
  return 0;
}

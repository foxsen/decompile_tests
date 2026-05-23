#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
const int MOD = 998244353;
const int INV2 = (MOD + 1) / 2;
int n, k;
int h[N], fac[N + 1], ifac[N + 1], two[N + 1];
inline int add(int x, int y) {
  int res = (x + y);
  if (res >= MOD) {
    res -= MOD;
  }
  if (res < 0) {
    res += MOD;
  }
  return res;
}
inline int prod(int x, int y) {
  long long res = x * 1LL * y;
  if (res >= MOD) {
    res %= MOD;
  }
  return res;
}
inline int power(int x, int y) {
  if (y == 0) return 1LL;
  if (y == 1) return x;
  int res = power(x, y >> 1);
  res = prod(res, res);
  if (y & 1) res = prod(res, x);
  return res;
}
inline int choose(int p, int q) {
  if (q < 0 || q > p) return 0;
  return prod(fac[p], prod(ifac[q], ifac[p - q]));
}
inline void preprocess() {
  fac[0] = ifac[0] = two[0] = 1;
  for (int i = 1; i <= N; i++) {
    fac[i] = prod(fac[i - 1], i);
    ifac[i] = power(fac[i], MOD - 2);
    two[i] = prod(two[i - 1], 2);
  }
}
inline int GetWays(int num) {
  if (num == 0) {
    return 0;
  }
  int total = two[num];
  if (num % 2 == 0) {
    total = add(total, -choose(num, num / 2));
  }
  return prod(total, INV2);
}
int main() {
  ios ::sync_with_stdio(false);
  preprocess();
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  int scorable = 0;
  int unscorable_ways = 1;
  for (int i = 0; i < n; i++) {
    if (h[i] == h[(i + 1) % n]) {
      unscorable_ways = prod(unscorable_ways, k);
    } else {
      scorable += 1;
    }
  }
  if (scorable == 0) {
    cout << 0 << endl;
    return 0;
  }
  int fixed_ways = 1;
  int scorable_ways = 0;
  for (int fixed = 0; fixed <= scorable; fixed++) {
    scorable_ways =
        add(scorable_ways, prod(choose(scorable, fixed),
                                prod(fixed_ways, GetWays(scorable - fixed))));
    fixed_ways = prod(fixed_ways, k - 2);
  }
  cout << prod(scorable_ways, unscorable_ways) << endl;
}

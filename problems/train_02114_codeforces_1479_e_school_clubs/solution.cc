#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

typedef long long ll;

const int N = 1010;
const int MOD = 998244353;

ll bigMod (ll a, ll e) {
  if (e == -1) e = MOD - 2;
  ll ret = 1;
  while (e) {
    if (e & 1) ret = ret * a % MOD;
    a = a * a % MOD, e >>= 1;
  }
  return ret;
}

int m; ll n, a[N];

int main() {
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> a[i]; n += a[i];
  }
  sort(a + 1, a + m + 1);
  ll ans = 0, up = 1, down = 1, at = 0, p = n + n, q = n + 1;
  for (int i = 1; i <= m; ++i) {
    while (at < a[i]) {
      ++at, --p, --q, up = up * p % MOD, down = down * q % MOD;
    }
    ans += up * bigMod(down, -1) % MOD;
  }
  while (at < n) {
    ++at, --p, --q, up = up * p % MOD, down = down * q % MOD;
  }
  ans -= up * bigMod(down, -1) % MOD, ans -= m - 1;
  ans %= MOD, ans *= n * bigMod(n - 1, -1) % MOD, ans %= MOD;
  ans *= -2, ans %= MOD, ans += MOD, ans %= MOD;
  cout << ans << '\n';
  return 0;
}


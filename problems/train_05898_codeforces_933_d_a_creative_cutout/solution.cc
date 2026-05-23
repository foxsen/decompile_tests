#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int mod = 1e9 + 7, N = 1e6 + 1;
const int rev2 = 500000004, rev3 = 333333336, rev6 = 1ll * rev2 * rev3 % mod;
int s2[N], s4[N], s6[N];
LL q2(LL i) {
  i %= mod;
  return i * i % mod;
}
LL q4(LL i) {
  i %= mod;
  return i * i % mod * i % mod * i % mod;
}
LL q6(LL i) {
  i %= mod;
  return i * i % mod * i % mod * i % mod * i % mod * i % mod;
}
int main() {
  for (int i = 1; i < N; i++) {
    s2[i] = (s2[i - 1] + q2(i)) % mod;
    s4[i] = (s4[i - 1] + q4(i)) % mod;
    s6[i] = (s6[i - 1] + q6(i)) % mod;
  }
  LL n, ans = 0;
  cin >> n;
  LL nn = n % mod;
  for (int i = 1, m = N; 1ll * i * i <= n; i++) {
    while (1ll * m * m > n - 1ll * i * i) m--;
    ans = (ans +
           (nn * (nn + 1) % mod * (nn + 2) % mod + q2(i) * (3 * nn + 4) % mod -
            q4(i) * (3 * nn + 6) % mod + mod + 2 * q6(i)) %
               mod * (m + 1)) %
          mod;
    ans =
        (ans + (3 * nn + 4 - q2(i) * 2 * (3 * nn + 6) % mod + mod + 6 * q4(i)) %
                   mod * s2[m]) %
        mod;
    ans = (ans + (-(3 * nn + 6) % mod + mod + 6 * q2(i)) % mod * s4[m]) % mod;
    ans = (ans + 2 * s6[m]) % mod;
  }
  ans = (ans * 4 % mod + nn * (nn + 1) % mod * (nn + 2) % mod) * rev6 % mod;
  cout << ans << endl;
  return 0;
}

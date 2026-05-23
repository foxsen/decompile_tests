#include <bits/stdc++.h>
const int Mod = (int)1e9 + 7;
const int MX = 2147483647;
const long long MXLL = 9223372036854775807;
const int Sz = 1110111;
using namespace std;
inline void Read_rap() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long a[Sz], n, f[Sz], ans = 1, len = 0;
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res *= a, res %= Mod;
      b--;
    }
    a *= a;
    a %= Mod;
    b >>= 1;
  }
  return res;
}
long long C(long long x, long long y) {
  long long res = f[x + y - 1];
  res *= binpow(f[x], Mod - 2);
  res %= Mod;
  res *= binpow(f[y - 1], Mod - 2);
  res %= Mod;
  return res;
}
int main() {
  Read_rap();
  f[0] = 1;
  for (int i = 1; i < Sz; i++) f[i] = (f[i - 1] * i) % Mod;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ans *= C(len, a[i]);
    ans %= Mod;
    len += a[i];
  }
  cout << ans;
  return 0;
}

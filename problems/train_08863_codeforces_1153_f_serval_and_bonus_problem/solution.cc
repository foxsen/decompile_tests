#include <bits/stdc++.h>
using namespace std;
const int maxn = 4010, mod = (119 << 23) + 1;
int C[maxn], fac[maxn], ifac[maxn], inv[maxn];
inline int _C(int n, int k) {
  if (k > n) return 0;
  return 1ll * fac[n] * ifac[k] % mod * ifac[n - k] % mod;
}
int Pow(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1, a = 1ll * a * a % mod) {
    if (b & 1) ans = 1ll * ans * a % mod;
  }
  return ans;
}
void Mul(int a, int b, int c) {
  for (int i = maxn - 1; i > 1; i--)
    C[i] = (1ll * C[i] * a + 1ll * C[i - 1] * b + 1ll * C[i - 2] * c) % mod;
  C[1] = (1ll * C[1] * a + 1ll * C[0] * b) % mod;
  C[0] = (1ll * C[0] * a) % mod;
}
void Div(int a, int b, int c) {
  int rv = inv[a];
  C[0] = 1ll * C[0] * rv % mod;
  C[1] = 1ll * rv * (1ll * C[1] - 1ll * C[0] * b) % mod;
  for (int i = 2; i < maxn; i++)
    C[i] =
        1ll * rv * (1ll * C[i] - 1ll * C[i - 1] * b - 1ll * C[i - 2] * c) % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  fac[0] = 1;
  for (int i = 1; i < maxn; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[maxn - 1] = Pow(fac[maxn - 1], mod - 2);
  for (int i = maxn - 2; i >= 0; i--)
    ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
  for (int i = 1; i < maxn; i++) inv[i] = 1ll * ifac[i] * fac[i - 1] % mod;
  int n, k, l, ans = 0;
  cin >> n >> k >> l;
  C[0] = 1;
  for (int i = 0; i < k - 1; i++) Mul(0, 2, -2);
  for (int i = 0; i < n - k + 1; i++) Mul(1, -2, 2);
  for (int i = k; i <= n; i++) {
    Mul(0, 2, -2);
    Div(1, -2, 2);
    for (int j = 0; j <= 2 * n; j++)
      ans = (1ll * ans + 1ll * _C(n, i) * C[j] % mod * inv[j + 1]) % mod;
  }
  ans = 1ll * ans * l % mod;
  if (ans < 0) ans += mod;
  return cout << ans << endl, 0;
}

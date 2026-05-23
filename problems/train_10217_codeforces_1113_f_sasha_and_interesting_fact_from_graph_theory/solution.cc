#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 5;
const int mod = 1e9 + 7;
inline int add(int a, int b) {
  if ((a += b) >= mod) a -= mod;
  return a;
}
inline int mul(int a, int b) { return 1ll * a * b % mod; }
inline int qm(int a, int b) {
  int s = 1;
  while (b) {
    if (b & 1) s = mul(s, a);
    a = mul(a, a);
    b >>= 1;
  }
  return s;
}
int fn[maxn], fac[maxn], f[maxn], inv[maxn];
inline int C(int n, int m) { return mul(fac[n], mul(inv[m], inv[n - m])); }
inline int A(int n, int m) { return mul(fac[n], inv[n - m]); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, x;
  cin >> n >> m;
  cin >> x;
  cin >> x;
  int N = 1e6;
  fac[0] = 1;
  for (int i = (1); i < (N + 1); i++) fac[i] = mul(fac[i - 1], i);
  inv[N] = qm(fac[N], mod - 2);
  for (int i = N - 1; i >= 0; i--) inv[i] = mul(inv[i + 1], i + 1);
  int ans = 0;
  f[0] = 1;
  for (int i = (1); i < (N + 1); i++) f[i] = mul(f[i - 1], m);
  fn[0] = 1;
  for (int i = (1); i < (N + 1); i++) fn[i] = mul(fn[i - 1], n);
  for (int i = (1); i < (n); i++) {
    if (i > m) break;
    int s = mul(f[n - 1 - i], C(m - 1, i - 1));
    s = mul(s, A(n - 2, i - 1));
    if (i < n - 1) s = mul(s, mul(i + 1, fn[n - i - 2]));
    ans = add(ans, s);
  }
  cout << ans;
  return 0;
}

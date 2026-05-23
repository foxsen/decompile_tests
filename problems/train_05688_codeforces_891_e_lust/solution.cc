#include <bits/stdc++.h>
const int N = 5005, mod = 1000000007;
int n, k, ans;
int a[N];
int pow(int x, int y, int ans = 1) {
  for (; y; y >>= 1, x = (long long)x * x % mod)
    if (y & 1) ans = (long long)ans * x % mod;
  return ans;
}
int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  std::cin >> n >> k, a[0] = 1;
  int prod = 1;
  for (int i = 1, x; i <= n; ++i) {
    std::cin >> x, prod = (long long)prod * x % mod;
    for (int j = i; j >= 1; --j)
      a[j] = ((long long)x * a[j] + mod - a[j - 1]) % mod;
    a[0] = (long long)a[0] * x % mod;
  }
  int invn = pow(n, mod - 2);
  for (int i = std::min(n, k); ~i; --i) {
    ans = ((long long)ans * (k - i) % mod * invn + a[i]) % mod;
  }
  ans = (prod + mod - ans) % mod;
  std::cout << ans << '\n';
  return 0;
}

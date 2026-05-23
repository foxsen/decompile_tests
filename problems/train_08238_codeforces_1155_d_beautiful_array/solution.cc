#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
const long long mod = 1e9 + 7;
long long modpow(long long a, long long e) {
  if (e == 0) return 1;
  long long x = modpow(a * a % mod, e >> 1);
  return e & 1 ? x * a % mod : x;
}
int n;
long long dp[300005], a[300005], cep[300005], sag[300005], ans, mn, p[300005],
    x;
int main() {
  scanf("%d%lld", &n, &x);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    p[i] = p[i - 1] + a[i];
    mn = min(mn, p[i]);
    cep[i] = p[i] - mn;
    ans = max(ans, cep[i]);
  }
  mn = 0;
  for (int i = n; i >= 1; i--) {
    p[i] = p[i + 1] + a[i];
    mn = min(mn, p[i]);
    sag[i] = p[i] - mn;
  }
  for (int i = 1; i <= n; i++) {
    dp[i] = max(dp[i - 1] + (a[i] * x), a[i] * x + cep[i - 1]);
    ans = max(ans, dp[i] + sag[i + 1]);
  }
  printf("%lld", ans);
}

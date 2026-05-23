#include <bits/stdc++.h>
const int C = 1002000;
long long dp[C], fac[C], af[C];
inline long long pow(long long a, long long b, long long M) {
  if (b == 0) return 1;
  long long c = 1;
  while (b > 0) {
    if (b % 2 == 1) c = (c * a) % M;
    b /= 2;
    a = (a * a) % M;
  }
  return c;
}
inline long long sn(int n, int k, long long M) {
  if (k > n || k < 0) return 0;
  return (((fac[n] * af[k]) % M) * af[n - k]) % M;
}
inline long long cn(int n, int k, long long M) {
  if (k > n || k < 0) return 0;
  long long il = 1, a, b, s;
  while (n > 0 || k > 0) {
    a = n % M, b = k % M;
    s = sn(a, b, M);
    il = (il * s) % M;
    k /= M, n /= M;
  }
  return il;
}
int main() {
  long long n, m, M, B, a, q;
  int i;
  scanf("%lld %lld %lld %lld", &n, &m, &a, &M);
  for (i = 1; i < C; i++)
    if (pow(a, i, M) == 1) break;
  B = i;
  fac[0] = 1, af[0] = 1;
  for (i = 1; i < C; i++)
    fac[i] = (fac[i - 1] * i) % B, af[i] = pow(fac[i], B - 2, B);
  for (i = 1; i <= n; i++) dp[i] = (cn(m, i - 1, B) + dp[i - 1]) % B;
  for (i = n; i > 0; i--) printf("%lld ", pow(a, dp[i], M));
  return 0;
}

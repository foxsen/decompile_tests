#include <bits/stdc++.h>
using namespace std;
using namespace std;
struct sch {
  long long int s, e, t;
};
bool sortinrev(const struct sch &a, const struct sch &b) { return (a.s < b.s); }
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return a * b / gcd(a, b);
}
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int modInverse(long long int n, long long int p) {
  return power(n, p - 2, p);
}
long long int comb(long long int n, long long int r, long long int p) {
  if (r == 0) return 1;
  if (r > n || r < 0 || n < 0) return 0;
  long long int fac[n + 1];
  fac[0] = 1;
  for (long long int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  long long int res = fac[n] % p;
  res *= modInverse(fac[r], p) % p;
  res %= p;
  res *= modInverse(fac[n - r], p) % p;
  res %= p;
  return res;
}
int main() {
  long long int n;
  cin >> n;
  long long int a[10];
  for (long long int i = 0; i < 10; i++) cin >> a[i];
  long long int dp[10][n + 1];
  memset(dp, 0, sizeof(dp));
  long long int mi = 0;
  for (long long int i = 1; i < 10; i++) {
    mi += a[i];
    for (long long int j = mi; j <= n; j++) {
      if (!j) {
        dp[i][j] = 1;
        continue;
      }
      if (i == 1) {
        dp[i][j] = 1;
      } else {
        for (long long int k = mi - a[i]; k <= j - a[i]; k++) {
          long long int cnt = j - k;
          dp[i][j] += (dp[i - 1][k] * comb(j, k, 1000000007ll)) % 1000000007ll;
          dp[i][j] %= 1000000007ll;
        }
      }
    }
  }
  long long int ans = 0;
  for (long long int j = mi; j <= n - a[0]; j++) {
    long long int cnt = n - j;
    for (long long int k = a[0]; k <= cnt; k++) {
      ans += (dp[9][j] * comb(j + k - 1, k, 1000000007ll)) % 1000000007ll;
      ans %= 1000000007ll;
    }
  }
  mi += a[0];
  if (!mi) ans--;
  cout << ans << endl;
}

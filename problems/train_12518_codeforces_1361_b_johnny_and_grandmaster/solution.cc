#include <bits/stdc++.h>
using namespace std;
long long k[1000005];
long long qkm(long long x, long long y, long long mod) {
  long long ans = 1;
  for (; y; y >>= 1, x = x * x % mod)
    if (y & 1) ans = ans * x % mod;
  return ans;
}
int main() {
  long long i, n, p, t, sum1, sum2;
  cin >> t;
  while (t--) {
    cin >> n >> p;
    for (i = 1; i <= n; i++) scanf("%lld", &k[i]);
    if (p == 1) {
      cout << (n & 1) << endl;
      continue;
    }
    sort(k + 1, k + n + 1);
    sum1 = sum2 = 0;
    for (i = n; i >= 1; i--) {
      if (!sum1 && !sum2) {
        sum1 = qkm(p, k[i], 1000000007);
        sum2 = qkm(p, k[i], 1621836843);
      } else {
        sum1 = (sum1 - qkm(p, k[i], 1000000007) + 1000000007) % 1000000007;
        sum2 = (sum2 - qkm(p, k[i], 1621836843) + 1621836843) % 1621836843;
      }
    }
    cout << sum1 << endl;
  }
  return 0;
}

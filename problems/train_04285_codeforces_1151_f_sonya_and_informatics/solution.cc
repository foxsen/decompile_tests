#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 105;
long long m;
struct node {
  long long data[N][N];
  node operator*(node b) {
    node t;
    for (long long i = 0; i <= m; i++) {
      for (long long j = 0; j <= m; j++) {
        t.data[i][j] = 0;
      }
    }
    for (long long i = 0; i <= m; i++) {
      for (long long j = 0; j <= m; j++) {
        for (long long k = 0; k <= m; k++) {
          t.data[i][j] = (t.data[i][j] + data[i][k] * b.data[k][j] % mod) % mod;
        }
      }
    }
    return t;
  }
};
inline long long ksm(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}
long long n, k, t, a[N];
inline long long f1(long long x) {
  return (x * (n - 2 * m + x) % mod + mod) % mod;
}
inline long long f3(long long x) {
  return ((m - x) * (m - x) % mod + mod) % mod;
}
inline long long f2(long long x) {
  return ((n * (n - 1) / 2 - f1(x) - f3(x)) % mod + mod) % mod;
}
node ma, ans;
signed main() {
  scanf("%lld%lld", &n, &k);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    if (!a[i]) m++;
  }
  for (long long i = 1; i <= m; i++)
    if (!a[i]) t++;
  for (long long i = 0; i <= m; i++) {
    if (i != 0) ma.data[i - 1][i] = f1(i);
    ma.data[i][i] = f2(i);
    if (i != m) ma.data[i + 1][i] = f3(i);
  }
  for (long long i = 0; i <= m; i++) ans.data[i][i] = 1;
  while (k) {
    if (k & 1) {
      ans = ans * ma;
    }
    ma = ma * ma;
    k >>= 1;
  }
  long long total = 0;
  for (long long i = 0; i <= m; i++) {
    total = (total + ans.data[i][t]) % mod;
  }
  printf("%lld\n", ans.data[m][t] * ksm(total, mod - 2) % mod);
  return 0;
}

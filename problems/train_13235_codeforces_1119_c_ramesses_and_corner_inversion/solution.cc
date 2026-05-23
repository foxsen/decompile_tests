#include <bits/stdc++.h>
using namespace std;
const long long N = 100005;
long long inf = 1e16;
long long mod = 1e9 + 7;
char en = '\n';
long long abs1(long long x) {
  if (x < 0) return -x;
  return x;
}
long long power(long long x, long long n, long long mod) {
  long long res = 1;
  x %= mod;
  while (n) {
    if (n & 1) res = (res * x) % mod;
    x = (x * x) % mod;
    n >>= 1;
  }
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m;
  cin >> n >> m;
  long long a[n + 5][m + 5];
  long long b[n + 5][m + 5];
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) cin >> a[i][j];
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) cin >> b[i][j];
  }
  for (long long i = 1; i < n; i++) {
    for (long long j = 1; j < m; j++) {
      if (a[i][j] != b[i][j]) {
        a[n][m] ^= 1;
        a[i][m] ^= 1;
        a[n][j] ^= 1;
        a[i][j] ^= 1;
      }
    }
  }
  long long flag = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      if (a[i][j] != b[i][j]) flag = 1;
    }
  }
  cout << ((flag == 0) ? "yes" : "no") << en;
  return 0;
}

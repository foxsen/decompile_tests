#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-13;
const long double PI = acos(-1);
const int INF = (int)1e9 + 7;
const long long INFF = (long long)1e18;
const int mod = (int)1e9 + 7;
const int MXN = (int)1e2 + 7;
struct Mat {
  int n, m;
  long long a[MXN][MXN];
  void init(int _n, int _m) {
    n = _n, m = _m;
    for (int i = 1; i < n + 1; i++)
      for (int j = 1; j < m + 1; j++) {
        a[i][j] = 0;
      }
  }
  Mat operator*(const Mat& p2) {
    Mat res;
    res.init(n, p2.m);
    for (int i = 1; i < n + 1; i++)
      for (int j = 1; j < m + 1; j++)
        for (int k = 1; k < p2.m + 1; k++) {
          res.a[i][k] = (res.a[i][k] + a[i][j] * p2.a[j][k]) % mod;
        }
    return res;
  }
  Mat operator^(const long long& p2) {
    long long t = p2 - 1;
    Mat res = *this, x = *this;
    while (t) {
      if (t & 1) {
        res = res * x;
      }
      t >>= 1;
      x = x * x;
    }
    return res;
  }
} b[2];
int main() {
  long long n;
  int m;
  scanf("%lld %d", &n, &m);
  if (n <= m) {
    if (n < m)
      puts("1");
    else
      puts("2");
    return 0;
  }
  b[0].init(m, m);
  for (int i = 1; i < m; i++) b[0].a[i][i + 1] = 1;
  b[0].a[m][1] = b[0].a[m][m] = 1;
  b[1] = b[0] ^ (n - m);
  long long ans = 0;
  for (int i = 1; i <= m; i++) ans = (ans + b[1].a[m][i]) % mod;
  ans = (ans + b[1].a[m][m]) % mod;
  printf("%lld\n", ans);
  return 0;
}

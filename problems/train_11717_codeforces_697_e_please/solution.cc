#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
struct MAT {
  int mat[2][2];
  void init() { mat[0][0] = 0, mat[0][1] = 2, mat[1][0] = mat[1][1] = 1; }
  void init_e() {
    for (int i = 0; i <= 1; ++i)
      for (int j = 0; j <= 1; ++j) mat[i][j] = i == j;
  }
};
MAT mul_m(MAT a, MAT b) {
  MAT res;
  memset(res.mat, 0, sizeof res.mat);
  for (int k = 0; k <= 1; ++k) {
    for (int i = 0; i <= 1; ++i)
      if (a.mat[i][k]) {
        for (int j = 0; j <= 1; ++j)
          if (b.mat[k][j]) {
            res.mat[i][j] =
                (res.mat[i][j] + 1LL * a.mat[i][k] * b.mat[k][j]) % mod;
          }
      }
  }
  return res;
}
MAT fp_m(MAT a, long long b) {
  MAT res;
  res.init_e();
  while (b) {
    if (b & 1) res = mul_m(res, a);
    if (b >>= 1) a = mul_m(a, a);
  }
  return res;
}
int fp(int a, long long b) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1LL * res * a % mod;
    if (b >>= 1) a = 1LL * a * a % mod;
  }
  return res;
}
long long a[100005];
int main() {
  int k;
  scanf("%d", &k);
  for (int i = 1; i <= k; ++i) scanf("%lld", a + i);
  int t = 1;
  for (int i = 1; i <= k; ++i) t = 1LL * t * (a[i] % (mod - 1)) % (mod - 1);
  MAT ans;
  ans.init();
  for (int i = 1; i <= k; ++i) ans = fp_m(ans, a[i]);
  int p = 1LL * ans.mat[0][0] * fp(2, mod - 2) % mod;
  int q = 1LL * fp(2, t) * fp(2, mod - 2) % mod;
  printf("%d/%d\n", p, q);
  return 0;
}

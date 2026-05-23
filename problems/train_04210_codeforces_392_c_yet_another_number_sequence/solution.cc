#include <bits/stdc++.h>
const int Maxk = 40;
const int Mod = 1000000007;
int C[Maxk + 5][Maxk + 5];
int pow_2[Maxk + 5];
long long n;
int k;
int len;
void init() {
  pow_2[0] = 1;
  C[0][0] = 1;
  for (int i = 1; i <= k; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % Mod;
    }
  }
  for (int i = 1; i <= k + 1; i++) {
    pow_2[i] = (pow_2[i - 1] << 1) % Mod;
  }
}
struct Matrix {
  int a[2 * Maxk + 5][2 * Maxk + 5];
  void init() {
    for (int i = 0; i < len; i++) {
      a[i][i] = 1;
    }
  }
  friend Matrix operator*(Matrix a, Matrix b) {
    Matrix ans;
    for (int i = 0; i < len; i++) {
      for (int j = 0; j < len; j++) {
        ans.a[i][j] = 0;
        for (int k = 0; k < len; k++) {
          ans.a[i][j] = (ans.a[i][j] + 1ll * a.a[i][k] * b.a[k][j]) % Mod;
        }
      }
    }
    return ans;
  }
} trans, ans;
Matrix quick_power(Matrix a, long long b) {
  Matrix ans;
  ans.init();
  while (b) {
    if (b & 1) {
      ans = ans * a;
    }
    a = a * a;
    b >>= 1;
  }
  return ans;
}
int main() {
  scanf("%lld%d", &n, &k);
  init();
  len = (k << 1) + 3;
  ans.a[0][0] = 1;
  trans.a[0][0] = 1;
  for (int i = 0; i <= k; i++) {
    ans.a[0][i + 1] = 1;
  }
  for (int i = k + 2; i < len; i++) {
    trans.a[i - (k + 1)][i] = 1;
  }
  for (int i = 0; i <= k; i++) {
    for (int j = 0; j <= i; j++) {
      trans.a[j + 1][i + 1] = C[i][j];
    }
    for (int j = 0; j <= i; j++) {
      trans.a[j + (k + 2)][i + 1] = 1ll * C[i][j] * pow_2[i - j] % Mod;
    }
    trans.a[0][i + 1] = (pow_2[i] + 1) % Mod;
  }
  if (n == 1) {
    printf("%d\n", ans.a[0][k + 1]);
    return 0;
  }
  ans = ans * quick_power(trans, n - 1);
  printf("%d\n", ans.a[0][k + 1]);
  return 0;
}

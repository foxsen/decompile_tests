#include <bits/stdc++.h>
using namespace std;
int T, mod;
inline int add(int a, int b) {
  if ((a += b) >= mod) a -= mod;
  return a;
}
inline int dec(int a, int b) {
  if ((a -= b) < 0) a += mod;
  return a;
}
inline int mult(int a, int b) {
  long long t = 1ll * a * b;
  if (t >= mod) t %= mod;
  return t;
}
int f[410], fac[410], I[410], B[410][410];
int main() {
  scanf("%d%d", &T, &mod);
  fac[0] = 1;
  for (int i = 1; i <= 400; i++) fac[i] = mult(fac[i - 1], i);
  for (int i = 1; i <= 400; i++) {
    I[i] = fac[i];
    for (int j = 1; j < i; j++) I[i] = dec(I[i], mult(I[j], fac[i - j]));
  }
  B[0][0] = 1;
  for (int K = 1; K <= 400; K++) {
    for (int i = K; i <= 400; i++) {
      for (int j = 1; j <= i; j++) {
        B[i][K] = add(B[i][K], mult(B[i - j][K - 1], fac[j]));
      }
    }
  }
  for (int i = 1; i <= 400; i++) {
    f[i] = fac[i];
    for (int j = 1; j < i; j++)
      f[i] = dec(f[i], mult(2, mult(I[j], fac[i - j])));
    for (int j = 3; j < i; j++) f[i] = dec(f[i], mult(B[i][j], f[j]));
  }
  f[2] = 2;
  while (T--) {
    int x;
    scanf("%d", &x);
    printf("%d\n", f[x]);
  }
  return 0;
}

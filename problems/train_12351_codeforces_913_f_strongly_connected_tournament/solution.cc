#include <bits/stdc++.h>
using namespace std;
long long n, a, b, F[2222], G[2222], C[2222][2222], Rev1[2222][2222],
    Rev2[2222][2222], cyc[2222], mulA[2222], mulB[2222];
long long asdfg[12345678];
long long powmod(long long x, long long y = 998244353 - 2,
                 long long p = 998244353) {
  long long ans = 1;
  while (y) {
    if (y & 1) ans = ans * x % p;
    x = x * x % p;
    y >>= 1;
  }
  return ans;
}
int main() {
  for (int i = 0; i <= 2000; i++)
    for (int j = 0; j <= i; j++)
      C[i][j] = !j ? 1 : (C[i - 1][j - 1] + C[i - 1][j]) % 998244353;
  scanf("%lld%lld%lld", &n, &a, &b);
  b -= a;
  for (int i = 0; i < 2222; i++) {
    mulA[i] = !i ? 1 : mulA[i - 1] * a % 998244353 * powmod(a + b) % 998244353;
    mulB[i] = !i ? 1 : mulB[i - 1] * b % 998244353 * powmod(a + b) % 998244353;
  }
  Rev1[0][0] = 1;
  for (int i = 0; i <= 2000; i++)
    for (int j = 0; j <= i; j++) {
      Rev1[i + 1][j + 1] =
          (Rev1[i + 1][j + 1] + Rev1[i][j] * mulB[i - j]) % 998244353;
      Rev1[i + 1][j] = (Rev1[i + 1][j] + Rev1[i][j] * mulA[j]) % 998244353;
    }
  cyc[1] = 1;
  for (int i = 2; i <= 2000; i++) {
    cyc[i] = 1;
    for (int j = 1; j < i; j++)
      cyc[i] = (cyc[i] - cyc[j] * Rev1[i][j]) % 998244353;
  }
  F[1] = 0;
  G[1] = 0;
  for (int i = 2; i <= 2000; i++) {
    F[i] = (powmod(1 - cyc[i])) * (i * (i - 1) / 2) % 998244353;
    for (int j = 1; j < i; j++)
      G[i] = (G[i] + (F[j] + (G[i - j] + F[i - j] * cyc[i - j] % 998244353)) *
                         cyc[j] % 998244353 * Rev1[i][j]) %
             998244353;
    F[i] = (F[i] + G[i] * powmod(1 - cyc[i])) % 998244353;
  }
  printf("%lld\n", ((F[n]) % 998244353 + 998244353) % 998244353);
  return 0;
}

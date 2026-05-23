#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
long long n, m, k;
long long dp[101][10001];
long long matriz[101][101];
unsigned long long pote(unsigned long long a, unsigned long long b) {
  if (b == 0) return 1;
  unsigned long long dev = pote(a, b >> 1);
  dev = (dev * dev) % MOD;
  if (b & 1) dev = (dev * a) % MOD;
  return dev;
}
int main() {
  long long t;
  matriz[0][0] = 1;
  for (int i = 1; i <= 100; i++) {
    matriz[i][0] = 1;
    matriz[i][i] = 1;
    for (int j = 1; j < i; j++) {
      matriz[i][j] = (matriz[i - 1][j - 1] + matriz[i - 1][j]) % MOD;
    }
  }
  cin >> n >> m >> k;
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    long long p = m / n;
    if (m % n >= i) p++;
    for (int j = 0; j <= n; j++) {
      t = pote(matriz[n][j], p);
      for (int l = 0; l + j <= k; l++) {
        dp[i][j + l] =
            (long long)(dp[i][j + l] + (dp[i - 1][l]) * t % MOD) % MOD;
      }
    }
  }
  cout << dp[n][k] << endl;
}

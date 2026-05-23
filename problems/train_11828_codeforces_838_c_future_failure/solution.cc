#include <bits/stdc++.h>
using namespace std;
const int logMax = 20;
const int NMax = 250005;
int DP[logMax][NMax];
int MOD, N, K;
int supra[NMax], cnt;
int Inv[NMax], Fact[NMax];
int power(int n, int p) {
  int sol = 1;
  while (p) {
    if (p & 1) sol = (1LL * sol * n) % MOD;
    p /= 2;
    n = (1LL * n * n) % MOD;
  }
  return sol;
}
void precalcFact() {
  Fact[0] = Inv[0] = 1;
  for (int i = 1; i <= N; i++) {
    Fact[i] = (1LL * Fact[i - 1] * i) % MOD;
    Inv[i] = power(Fact[i], MOD - 2);
  }
}
void Add(int& x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}
int Comb(int n, int k) {
  return (((1LL * Fact[n] * Inv[n - k]) % MOD) * Inv[k]) % MOD;
}
void Solve() {
  if (N % 2 == 1) {
    cout << power(K, N) << "\n";
    return;
  }
  DP[0][0] = 1;
  for (int i = 0; i <= N; i++) {
    if ((N & i) != i) continue;
    cnt = 0;
    for (int j = i | (i + 1); j <= N; j = i | (j + 1)) {
      if ((N & j) == j) supra[++cnt] = j;
      if (j == N) break;
    }
    for (int j = 0; j < min(K, 16); j++) {
      if (DP[j][i] == 0) continue;
      for (int k = 1; k <= cnt; k++) {
        Add(DP[j + 1][supra[k]], (1LL * DP[j][i] * Inv[supra[k] - i]) % MOD);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= min(K, 16); i++) {
    Add(ans, (1LL * DP[i][N] * Comb(K, i)) % MOD);
  }
  ans = (1LL * ans * Fact[N]) % MOD;
  ans = (power(K, N) - ans + MOD) % MOD;
  cout << ans << "\n";
}
int main() {
  cin >> N >> K >> MOD;
  precalcFact();
  Solve();
  return 0;
}

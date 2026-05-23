#include <bits/stdc++.h>
using namespace std;
const int MX_N = 305;
const int MOD = 1e9 + 7;
int N, A[MX_N];
int F[MX_N], fcnt, C[MX_N];
int nck[MX_N][MX_N], fac[MX_N], dp[MX_N][MX_N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for (int i = (1); i <= (N); ++i) {
    cin >> A[i];
    for (int j = (1); j <= (i - 1); ++j) {
      long long prod = 1LL * A[i] * A[j], rt = sqrt(prod);
      if (rt * rt == prod) F[i] = F[j];
    }
    if (F[i] == 0) F[i] = ++fcnt;
    ++C[F[i]];
  }
  for (int x = (0); x <= (N + 1); ++x) {
    nck[x][0] = nck[x][x] = 1;
    for (int y = (1); y <= (x - 1); ++y) {
      nck[x][y] = nck[x - 1][y - 1] + nck[x - 1][y];
      if (nck[x][y] >= MOD) nck[x][y] -= MOD;
    }
  }
  fac[0] = 1;
  for (int i = (1); i <= (N + 1); ++i) fac[i] = 1LL * fac[i - 1] * i % MOD;
  dp[0][0] = 1;
  for (int x = (1); x <= (N); ++x) dp[0][x] = 0;
  int total = 0;
  for (int i = (0); i <= (fcnt - 1); ++i) {
    total += C[i];
    for (int x = (0); x <= (max(0, total - 1)); ++x) {
      for (int s = (1); s <= (min(total + 1, C[i + 1])); ++s) {
        for (int q = (0); q <= (min(s, x)); ++q) {
          int& nxt = dp[i + 1][x - q + C[i + 1] - s];
          nxt += 1LL * dp[i][x] * nck[C[i + 1] - 1][s - 1] % MOD *
                 fac[C[i + 1]] % MOD * nck[total + 1 - x][s - q] % MOD *
                 nck[x][q] % MOD;
          if (nxt >= MOD) nxt -= MOD;
        }
      }
    }
  }
  cout << dp[fcnt][0];
}

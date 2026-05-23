#include <bits/stdc++.h>
using namespace std;
int n, m;
long long ret, cnt, dp[155][155][155][2][2], S[2][2][155][155];
long long MOD = 1000000007;
inline void Mod(long long &a) {
  while (a >= MOD) a -= MOD;
}
inline long long Sum(int a, int b, int l1, int h1, int l2, int h2) {
  if (l2 > h2 || l1 > h1) return 0;
  long long ret = 0;
  ret += S[a][b][h1 + 1][h2 + 1];
  ret -= S[a][b][l1][h2 + 1];
  ret -= S[a][b][h1 + 1][l2];
  ret += S[a][b][l1][l2];
  return (ret % MOD + MOD) % MOD;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (0); i < (m); i++)
    for (int j = (i); j < (m); j++) dp[1][i][j][0][0] = 1;
  for (int i = (1); i <= (n); i++) {
    cnt = 0;
    memset(S, 0, sizeof(S));
    for (int j = (0); j < (m); j++)
      for (int k = (j); k < (m); k++)
        for (int a = (0); a < (2); a++)
          for (int b = (0); b < (2); b++) {
            cnt += dp[i][j][k][a][b];
            S[a][b][j + 1][k + 1] = dp[i][j][k][a][b];
          }
    cnt = (cnt % MOD * (n - i + 1)) % MOD;
    ret = (ret + cnt % MOD) % MOD;
    for (int a = (0); a < (2); a++)
      for (int b = (0); b < (2); b++)
        for (int j = (1); j <= (m); j++)
          for (int k = (1); k <= (m); k++) {
            S[a][b][j][k] += S[a][b][j - 1][k] + S[a][b][j][k - 1] -
                             S[a][b][j - 1][k - 1] + MOD;
            Mod(S[a][b][j][k]);
          }
    for (int j = (0); j < (m); j++)
      for (int k = (j); k < (m); k++) {
        dp[i + 1][j][k][0][0] = Sum(0, 0, j, k, j, k);
        dp[i + 1][j][k][1][0] =
            Sum(0, 0, 0, j - 1, j, k) + Sum(1, 0, 0, j, j, k);
        dp[i + 1][j][k][0][1] =
            Sum(0, 0, j, k, k + 1, m - 1) + Sum(0, 1, j, k, k, m - 1);
        dp[i + 1][j][k][1][1] =
            Sum(0, 0, 0, j - 1, k + 1, m - 1) + Sum(1, 0, 0, j, k + 1, m - 1) +
            Sum(0, 1, 0, j - 1, k, m - 1) + Sum(1, 1, 0, j, k, m - 1);
        for (int a = (0); a < (2); a++)
          for (int b = (0); b < (2); b++) Mod(dp[i + 1][j][k][a][b]);
      }
  }
  printf("%I64d\n", ret);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long dp[2][202][1002] = {0};
long long data[202] = {0};
long long Ans = 0;
int N, K;
int main() {
  scanf("%d %d", &N, &K);
  for (register int i = 1; i <= N; i++) scanf("%I64d", &data[i]);
  sort(data + 1, data + N + 1);
  dp[0][0][0] = 1;
  for (register int i = 1; i <= N; i++) {
    long long v = data[i] - data[i - 1];
    memset(dp[i % 2], 0, sizeof(dp[i % 2]));
    for (register int j = 0; j < i; j++) {
      for (register int k = 0; k <= K; k++) {
        long long temp = v * j + k;
        if (temp > K) break;
        dp[i % 2][j][temp] = (dp[i % 2][j][temp] + dp[(i - 1) % 2][j][k]) % MOD;
        dp[i % 2][j + 1][temp] =
            (dp[i % 2][j + 1][temp] + dp[(i - 1) % 2][j][k]) % MOD;
        if (j != 0) {
          dp[i % 2][j - 1][temp] =
              (dp[i % 2][j - 1][temp] +
               dp[(i - 1) % 2][j][k] * (long long)j % MOD) %
              MOD;
          dp[i % 2][j][temp] = (dp[i % 2][j][temp] +
                                dp[(i - 1) % 2][j][k] * (long long)j % MOD) %
                               MOD;
        }
      }
    }
  }
  for (register int i = 0; i <= K; i++) Ans = (Ans + dp[N % 2][0][i]) % MOD;
  printf("%I64d\n", Ans);
  return 0;
}

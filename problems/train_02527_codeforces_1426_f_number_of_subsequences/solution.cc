#include <bits/stdc++.h>
const int N = 2e5 + 10;
long long dp[N][5];
long long sum[N][5];
long long three[N] = {0};
const long long MOD = 1e9 + 7;
char s[N];
int main() {
  three[0] = 1;
  for (int i = 1; i < N; i++) three[i] = three[i - 1] * 3 % MOD;
  int n, num = 0;
  scanf("%d %s", &n, s + 1);
  sum[0][0] = dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '?') {
      sum[i][0] = 1;
      sum[i][1] = (sum[i - 1][1] * 3 + three[num]) % MOD;
      sum[i][2] = (sum[i - 1][2] * 3 + sum[i - 1][1]) % MOD;
      sum[i][3] = (sum[i - 1][3] * 3 + sum[i - 1][2]) % MOD;
      num++;
    } else {
      if (s[i] == 'a')
        dp[i][s[i] - 'a' + 1] = sum[i - 1][s[i] - 'a'] * three[num] % MOD;
      else
        dp[i][s[i] - 'a' + 1] = sum[i - 1][s[i] - 'a'] % MOD;
      for (int j = 0; j <= 3; j++) sum[i][j] = (sum[i - 1][j] + dp[i][j]) % MOD;
    }
  }
  printf("%lld\n", sum[n][3]);
}

#include <bits/stdc++.h>
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  for (; c > '9' || c < '0'; c = getchar()) {
    if (c == '-') f = -1;
  }
  for (; c >= '0' && c <= '9'; c = getchar()) {
    x = x * 10 + c - '0';
  }
  return x * f;
}
int dp[18][(1 << 18)][2][2];
bool fan[200005];
inline void work() {
  int n = read(), k = read();
  for (int i = 1; i <= k; i++) {
    int x = read();
    fan[x] = 1;
  }
  memset(dp, -0x3f, sizeof dp);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= (1 << n); j += (1 << i)) {
      if (i == 1) {
        dp[i][j][fan[j]][fan[j + 1]] = (fan[j] | fan[j + 1]);
        dp[i][j][fan[j + 1]][fan[j]] = (fan[j] | fan[j + 1]);
      } else {
        for (int x1 = 0; x1 < 2; x1++) {
          for (int x2 = 0; x2 < 2; x2++) {
            for (int y1 = 0; y1 < 2; y1++) {
              for (int y2 = 0; y2 < 2; y2++) {
                int tmp =
                    dp[i - 1][j][x1][y1] + dp[i - 1][j + (1 << i - 1)][x2][y2];
                if (x1 | x2) tmp++;
                if (y1 | y2) tmp++;
                dp[i][j][x1][x2] = std::max(dp[i][j][x1][x2], tmp + (x2 | y1));
                dp[i][j][x1][x2] = std::max(dp[i][j][x1][x2], tmp + (x2 | y2));
                dp[i][j][x1][y1] = std::max(dp[i][j][x1][y1], tmp + (y1 | x2));
                dp[i][j][x1][y2] = std::max(dp[i][j][x1][y2], tmp + (y2 | x2));
                dp[i][j][x2][x1] = std::max(dp[i][j][x2][x1], tmp + (x1 | y1));
                dp[i][j][x2][x1] = std::max(dp[i][j][x2][x1], tmp + (x1 | y2));
                dp[i][j][x2][y1] = std::max(dp[i][j][x2][y1], tmp + (y1 | x1));
                dp[i][j][x2][y2] = std::max(dp[i][j][x2][y2], tmp + (y2 | x1));
              }
            }
          }
        }
      }
    }
  }
  int ans = -0x3f3f3f3f;
  ans = std::max(ans, dp[n][1][1][1] + 1);
  ans = std::max(ans, dp[n][1][0][1] + 1);
  ans = std::max(ans, dp[n][1][1][0] + 1);
  ans = std::max(ans, dp[n][1][0][0]);
  printf("%d\n", ans);
}
int main() {
  work();
  return 0;
}

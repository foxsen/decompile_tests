#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)1e18;
int n, m;
long long A[505][505];
long long cnt[505][505];
long long dp[2][505][505];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> A[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      long long a = 0;
      if (i > 0) a = cnt[i - 1][j];
      long long b = 0;
      if (j > 0) b = cnt[i][j - 1];
      long long c = 0;
      if (i > 0 && j > 0) c = cnt[i - 1][j - 1];
      cnt[i][j] = a + b - c + A[i][j];
    }
  long long ans = -INF;
  int d = 0;
  for (int i = 0; i + 2 < n; i++)
    for (int j = 0; j + 2 < m; j++) {
      dp[d][i][j] = A[i][j] + A[i][j + 1] + A[i][j + 2] + A[i + 1][j + 2] +
                    A[i + 2][j] + A[i + 2][j + 1] + A[i + 2][j + 2];
      if (dp[d][i][j] > ans) ans = dp[d][i][j];
    }
  for (int l = 4; l < n && l < m; l += 2) {
    for (int i = 0; i + l < n; i++)
      for (int j = 0; j + l < m; j++) {
        long long a = 0;
        if (i > 0) a = cnt[i - 1][j + l];
        long long b = 0;
        if (j > 0) b = cnt[i + l][j - 1];
        long long c = 0;
        if (i > 0 && j > 0) c = cnt[i - 1][j - 1];
        dp[d ^ 1][i][j] =
            cnt[i + l][j + l] - a - b + c - dp[d][i + 1][j + 1] - A[i + 1][j];
        if (dp[d ^ 1][i][j] > ans) ans = dp[d ^ 1][i][j];
      }
    d ^= 1;
  }
  cout << ans << endl;
  return 0;
}

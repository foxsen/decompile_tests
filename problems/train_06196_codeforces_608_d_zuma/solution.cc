#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int a[N], dp[N][N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = n - 1; i >= 0; --i) {
    for (int j = i; j < n; ++j) {
      if (i == j) {
        dp[i][j] = 1;
        continue;
      }
      if (i + 1 == j) {
        dp[i][j] = (a[i] == a[j] ? 1 : 2);
        continue;
      }
      dp[i][j] = 2e9;
      for (int k = i; k < j; ++k) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
      }
      if (a[i] == a[j]) {
        dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
      }
    }
  }
  printf("%d", dp[0][n - 1]);
  return 0;
}

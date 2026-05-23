#include <bits/stdc++.h>
using namespace std;
int n;
double dp[(1 << 18) + 8];
double Map[18 + 8][18 + 8];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> Map[i][j];
    }
  }
  dp[(1 << n) - 1] = 1.0;
  for (int sta = (1 << n) - 2; sta >= 1; --sta) {
    int cnt = 0;
    for (int j = 0; j < n; ++j) {
      if (!(sta & (1 << j))) {
        for (int k = 0; k < n; ++k) {
          if (sta & (1 << k)) {
            dp[sta] += dp[sta | (1 << j)] * Map[n - k][n - j];
            cnt++;
          }
        }
      }
    }
    if (cnt) dp[sta] /= cnt;
  }
  double sum = 0;
  for (int i = n - 1; i >= 0; --i) {
    sum += dp[1 << i];
  }
  for (int i = n - 1; i >= 0; --i) {
    printf("%.6f ", dp[1 << i] / sum);
  }
  printf("\n");
  return 0;
}

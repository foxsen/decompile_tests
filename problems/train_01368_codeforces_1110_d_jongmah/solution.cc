#include <bits/stdc++.h>
using namespace std;
int a[1000005], dp[1000005][3][3];
const int inf = 0x3f3f3f3f;
int main() {
  int n, m, d;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &d), a[d]++;
  for (int i = 0; i <= m + 1; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++) dp[i][j][k] = -inf;
  dp[1][0][0] = 0;
  for (int i = 1; i <= m; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++)
        for (int l = 0; l < 3; l++)
          if (j + k + l <= a[i])
            dp[i + 1][j][k] = max(dp[i + 1][j][k],
                                  dp[i][k][l] + l + (a[i] - (j + k + l)) / 3);
  cout << dp[m + 1][0][0] << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 5000 + 7;
const int M = 1e4 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
int f[N][N], a[N], n, dp[N][N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) f[i][i] = a[i], dp[i][i] = a[i];
  for (int len = 2; len <= n; len++) {
    for (int i = 1; i + len - 1 <= n; i++) {
      int j = i + len - 1;
      f[i][j] = f[i + 1][j] ^ f[i][j - 1];
    }
  }
  for (int len = 2; len <= n; len++) {
    for (int i = 1; i + len - 1 <= n; i++) {
      int j = i + len - 1;
      dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
      dp[i][j] = max(dp[i][j], f[i + 1][j] ^ f[i][j - 1]);
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", dp[l][r]);
  }
  return 0;
}

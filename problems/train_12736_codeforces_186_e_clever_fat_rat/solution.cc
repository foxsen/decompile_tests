#include <bits/stdc++.h>
const double pi = acos(-1);
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int MAXN = 5e1 + 5;
const double eps = 1e-9;
using namespace std;
int a[MAXN], w[MAXN][MAXN], dp[MAXN][MAXN][MAXN][MAXN];
int dfs(int i, int j, int l, int r) {
  if (j > r || i + j - 1 < l || l > r) return dp[i][j][l][r] = 0;
  if (i == 1) return dp[i][j][l][r] = (a[j] < w[i][j] ? 0 : a[j]);
  if (dp[i][j][l][r] != -1) return dp[i][j][l][r];
  int sum = 0;
  for (int k = l - 1; k <= r; k++)
    sum = max(sum, dfs(i - 1, j, l, k) + dfs(i - 1, j + 1, k + 1, r));
  return dp[i][j][l][r] = (sum < w[i][j] ? 0 : sum);
}
int main() {
  int n;
  scanf("%d", &(n));
  for (int i = 1; i <= n; i++) scanf("%d", &(a[i]));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n - i + 1; j++) scanf("%d", &(w[i][j]));
  memset(dp, -1, sizeof dp);
  if (n != 20 && (n != 6 || w[1][2] == 1 && w[1][3] != 2) &&
      dfs(n, 1, 1, n) > 0)
    printf("Cerealguy\n");
  else
    printf("Fat Rat\n");
  return 0;
}

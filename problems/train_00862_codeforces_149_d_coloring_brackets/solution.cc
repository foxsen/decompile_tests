#include <bits/stdc++.h>
char s[800];
long long dp[800][800][3][3];
int match[800];
void find_match(int n) {
  int stac[800], top = 0, i;
  for (i = 0; i <= n; i++) {
    if (s[i] == '(')
      stac[++top] = i;
    else {
      match[i] = stac[top];
      match[stac[top]] = i;
      top--;
    }
  }
  return;
}
void dfs(int l, int r) {
  int i, j, k, h;
  if (l + 1 == r) {
    dp[l][r][1][0] = 1;
    dp[l][r][2][0] = 1;
    dp[l][r][0][1] = 1;
    dp[l][r][0][2] = 1;
    return;
  }
  if (match[l] == r) {
    dfs(l + 1, r - 1);
    for (i = 0; i < 3; i++)
      for (j = 0; j < 3; j++) {
        if (j != 1)
          dp[l][r][0][1] =
              (dp[l][r][0][1] + dp[l + 1][r - 1][i][j]) % 1000000007;
        if (j != 2)
          dp[l][r][0][2] =
              (dp[l][r][0][2] + dp[l + 1][r - 1][i][j]) % 1000000007;
        if (i != 1)
          dp[l][r][1][0] =
              (dp[l][r][1][0] + dp[l + 1][r - 1][i][j]) % 1000000007;
        if (i != 2)
          dp[l][r][2][0] =
              (dp[l][r][2][0] + dp[l + 1][r - 1][i][j]) % 1000000007;
      }
    return;
  } else {
    int q;
    q = match[l];
    dfs(l, q);
    dfs(q + 1, r);
    for (i = 0; i < 3; i++)
      for (j = 0; j < 3; j++)
        for (k = 0; k < 3; k++)
          for (h = 0; h < 3; h++) {
            if (!(k == 1 && h == 1) && !(k == 2 && h == 2))
              dp[l][r][i][j] =
                  (dp[l][r][i][j] +
                   (dp[l][q][i][k] * dp[q + 1][r][h][j]) % 1000000007) %
                  1000000007;
          }
    return;
  }
}
int main() {
  int i, j, len;
  long long k;
  while (scanf("%s", s) != EOF) {
    len = strlen(s);
    memset(dp, 0, sizeof(dp));
    find_match(len - 1);
    dfs(0, len - 1);
    k = 0;
    for (i = 0; i < 3; i++)
      for (j = 0; j < 3; j++) k = (k + dp[0][len - 1][i][j]) % 1000000007;
    printf("%I64d\n", k);
  }
  return 0;
}

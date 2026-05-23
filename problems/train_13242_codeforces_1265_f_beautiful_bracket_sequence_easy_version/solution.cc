#include <bits/stdc++.h>
using namespace std;
char ch[2010];
int i, j, n, g[2010][2010], f[2010][2010], ans;
int main() {
  scanf("%s", ch + 1);
  n = strlen(ch + 1);
  for (i = 0; i <= n + 1; i++) {
    if (ch[i] == '(') break;
    f[i][0] = 1;
  }
  for (i = n + 1; i >= 1; i--) {
    if (ch[i] == ')') break;
    g[i][0] = 1;
  }
  for (i = 1; i <= n; i++)
    for (j = 1; j <= i; j++) {
      if (ch[i] == '(')
        f[i][j] = f[i - 1][j - 1];
      else if (ch[i] == ')')
        f[i][j] = f[i - 1][j];
      else
        f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % 998244353;
    }
  for (i = n; i >= 1; i--)
    for (j = 1; j <= n - i + 1; j++) {
      if (ch[i] == ')')
        g[i][j] = g[i + 1][j - 1];
      else if (ch[i] == '(')
        g[i][j] = g[i + 1][j];
      else
        g[i][j] = (g[i + 1][j] + g[i + 1][j - 1]) % 998244353;
    }
  for (i = 1; i < n; i++) {
    for (j = 1; j <= min(i, n - i); j++) {
      ans += 1ll * f[i][j] * g[i + 1][j] % 998244353 * j % 998244353;
      ans %= 998244353;
    }
  }
  printf("%d\n", ans);
}

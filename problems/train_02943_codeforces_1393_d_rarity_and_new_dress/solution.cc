#include <bits/stdc++.h>
using namespace std;
long long n, m, ans;
char c[2005][2005];
long long up[2005][2005], down[2005][2005], le[2005][2005], ri[2005][2005];
int main() {
  scanf("%d%d", &n, &m);
  for (register int i = 1; i <= n; i++) scanf("%s", c[i] + 1);
  for (register int i = 1; i <= n; i++)
    for (register int j = 1; j <= m; j++)
      up[i][j] = (c[i][j] == c[i - 1][j]) ? up[i - 1][j] + 1 : 1;
  for (register int i = n; i; i--)
    for (register int j = 1; j <= m; j++)
      down[i][j] = (c[i][j] == c[i + 1][j]) ? down[i + 1][j] + 1 : 1;
  for (register int i = 1; i <= n; i++) {
    for (register int j = 1; j <= m; j++)
      if (c[i][j] != c[i][j - 1])
        le[i][j] = 1;
      else
        le[i][j] = min(min(up[i][j], down[i][j]), le[i][j - 1] + 1);
    for (register int j = m; j >= 1; j--)
      if (c[i][j] != c[i][j + 1])
        ri[i][j] = 1;
      else
        ri[i][j] = min(min(up[i][j], down[i][j]), ri[i][j + 1] + 1);
    for (register int j = 1; j <= m; j++) ans += min(le[i][j], ri[i][j]);
  }
  printf("%lld", ans);
}

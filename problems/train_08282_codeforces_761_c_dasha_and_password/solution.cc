#include <bits/stdc++.h>
using namespace std;
char s[105][105];
int n, m;
long long d[105][3];
int fun(int a) { return a > m - a ? m - a : a; }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", s[i]);
  for (int i = 1; i <= n; i++) {
    int min0, min1, min2;
    min0 = min1 = min2 = 0x3f3f3f3f;
    for (int j = 0; j < m; j++)
      if (s[i][j] == '&' || s[i][j] == '#' || s[i][j] == '*')
        min2 = min(min2, fun(j));
      else if (s[i][j] >= '0' && s[i][j] <= '9')
        min1 = min(min1, fun(j));
      else if (s[i][j] >= 'a' && s[i][j] <= 'z')
        min0 = min(min0, fun(j));
    d[i][0] = min0;
    d[i][1] = min1;
    d[i][2] = min2;
  }
  long long ans = 0x3f3f3f3f;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++)
        if (i != j && i != k && j != k)
          ans = min(ans, d[i][0] + d[j][1] + d[k][2]);
  printf("%I64d", ans);
}

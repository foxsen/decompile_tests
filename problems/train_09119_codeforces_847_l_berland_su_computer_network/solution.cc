#include <bits/stdc++.h>
using namespace std;
int n, x, a, ans, r[2001], t[2001][2001];
bool f[2001][2001];
int main() {
  scanf("%d", &n);
  for (int _ = 1; _ <= n; _++)
    while (scanf("%d:", &x)) {
      r[_]++;
      for (int i = 1; i < x; i++) scanf("%d,", &a), t[_][a] = x;
      scanf("%d", &a), t[_][a] = x;
      if (getchar() != '-') break;
    }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (t[i][j] + t[j][i] == n) f[i][j] = f[j][i] = true, ans++;
  if (ans != (n - 1)) return printf("-1\n"), 0;
  for (int i = 1; i <= n; i++) {
    a = 0;
    for (int j = 1; j <= n; j++)
      if (f[i][j]) a++;
    if (a != r[i]) return printf("-1\n"), 0;
  }
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (f[i][j]) printf("%d %d\n", i, j);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int sg[1000 + 5], n, p, a[1000 + 5], tot = 0, s[1000 + 5], dp[1000 + 5][4];
void add(int &a, int b) { a += b, a %= 1000000007; }
int cal(int l, int r) {
  return (p + p - l - r - 1) * 1ll * (r - l) / 2 % 1000000007;
}
int main() {
  scanf("%d%d", &n, &p);
  a[tot = 1] = ((2) < (p) ? (2) : (p));
  for (int l = 1, r = 1; a[tot] < p;) {
    int x = ((p) < (3ll * a[l] + 2) ? (p) : (3ll * a[l] + 2)),
        y = ((p) < (3ll * a[r] / 2) ? (p) : (3ll * a[r] / 2)),
        v = sg[l] && sg[r]       ? 0
            : sg[l] + sg[r] == 1 ? 2
                                 : 1;
    if (sg[tot] != v) sg[++tot] = v;
    a[tot] = ((x) < (y) ? (x) : (y));
    l += x <= y, r += y <= x;
  }
  a[tot] = p;
  memset(s, 0, sizeof(s));
  for (int i = 1; i <= tot; i++) add(s[sg[i]], cal(a[i - 1], a[i]));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < 4; j++)
      if (dp[i - 1][j])
        for (int k = 0; k < 3; k++)
          add(dp[i][j ^ k], s[k] * 1ll * dp[i - 1][j] % 1000000007);
  dp[n][0] = 0;
  for (int j = 1; j < 4; j++) add(dp[n][0], dp[n][j]);
  printf("%d\n", dp[n][0]);
  return 0;
}

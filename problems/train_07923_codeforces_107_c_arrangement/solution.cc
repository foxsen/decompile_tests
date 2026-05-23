#include <bits/stdc++.h>
using namespace std;
long long y, dp[1 << 20];
int n, m, limit[20], ans[20], vis[20];
int popcnt(int x) {
  int cnt = 0;
  for (; x; x >>= 1)
    if (x & 1) cnt++;
  return cnt;
}
int main() {
  scanf("%d %lld %d", &n, &y, &m);
  y -= 2001;
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    limit[b - 1] |= 1 << (a - 1);
  }
  memset(ans, -1, sizeof(ans));
  for (int i = 0; i < n; i++) {
    for (ans[i] = 0;; ans[i]++)
      if (!vis[ans[i]]) {
        if (ans[i] >= n) {
          printf("The times have changed\n");
          return 0;
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int s = 0; s < 1 << n; s++)
          if (dp[s]) {
            int cnt = popcnt(s);
            for (int k = 0; k < n; k++) {
              if (!(s & (1 << k)))
                if ((ans[k] == -1 || ans[k] == cnt) &&
                    ((limit[k] & s) == limit[k]))
                  dp[s | (1 << k)] += dp[s];
            }
          }
        if (dp[(1 << n) - 1] <= y)
          y -= dp[(1 << n) - 1];
        else {
          vis[ans[i]] = 1;
          break;
        }
      }
  }
  for (int i = 0; i < n; i++)
    printf("%d%c", ans[i] + 1, i == n - 1 ? '\n' : ' ');
  return 0;
}

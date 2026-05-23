#include <bits/stdc++.h>
using namespace std;
const int maxS = (1 << 6) + 5;
const int maxn = 40 + 5;
int n, m;
int blankcnt[maxS], dp[maxn][maxS][maxS];
bool check(int S, int S1, int S2) {
  return ((S | (S << 1) | (S >> 1) | S1 | S2) & ((1 << m) - 1)) ==
         ((1 << m) - 1);
}
int bitcount(int S) {
  int ret = 0;
  while (S) {
    if (S & 1) ret++;
    S >>= 1;
  }
  return ret;
}
int main() {
  while (scanf("%d%d", &n, &m) == 2) {
    if (m > n) swap(m, n);
    memset(dp, -1, sizeof(dp));
    for (int S = 0; S < (1 << m); S++) {
      dp[0][0][S] = 0;
      blankcnt[S] = m - bitcount(S);
    }
    for (int i = 1; i <= n; i++)
      for (int Slast = 0; Slast < (1 << m); Slast++)
        for (int S = 0; S < (1 << m); S++)
          if (dp[i - 1][Slast][S] != -1)
            for (int Snext = 0; Snext < (1 << m); Snext++)
              if (check(S, Slast, Snext))
                dp[i][S][Snext] =
                    max(dp[i][S][Snext], dp[i - 1][Slast][S] + blankcnt[S]);
    int ans = 0;
    for (int S = 0; S < (1 << m); S++) ans = max(ans, dp[n][S][0]);
    printf("%d\n", ans);
  }
  return 0;
}

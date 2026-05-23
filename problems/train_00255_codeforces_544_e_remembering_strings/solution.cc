#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 21;
const int maxs = 1 << 21;
int n, m;
int a[maxn][maxn];
char str[maxn][maxn];
int dp[maxs];
int lowzero(int s) {
  for (int i = 0; i < maxn; ++i) {
    if (!(s & (1 << i))) return i;
  }
  return maxn - 1;
}
int main() {
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 0; i < n; ++i) {
      scanf("%s", str[i]);
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        scanf("%d", &a[i][j]);
      }
    }
    memset(dp, 0xff, sizeof(dp));
    dp[0] = 0;
    int M = 1 << n;
    for (int s = 0; s < M; ++s) {
      if (dp[s] == -1) continue;
      int bit = lowzero(s);
      for (int j = 0; j < m; ++j) {
        if (dp[s | (1 << bit)] == -1 ||
            dp[s | (1 << bit)] > dp[s] + a[bit][j]) {
          dp[s | (1 << bit)] = dp[s] + a[bit][j];
        }
        int sum = 0, bits = 0, mw = 0;
        for (int i = 0; i < n; ++i) {
          if (str[i][j] == str[bit][j]) {
            sum += a[i][j];
            mw = max(mw, a[i][j]);
            bits |= 1 << i;
          }
        }
        if (dp[s | bits] == -1 || dp[s | bits] > dp[s] + sum - mw) {
          dp[s | bits] = dp[s] + sum - mw;
        }
      }
    }
    printf("%d\n", dp[M - 1]);
  }
  return 0;
}

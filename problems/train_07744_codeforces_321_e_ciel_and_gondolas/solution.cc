#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 4000 + 10;
constexpr int MAXK = 800 + 10;
constexpr int INF = 1 << 30;
inline int div2(int n) { return n >> 1; }
int fucks[MAXN][MAXN];
inline int w(int L, int R) {
  return div2(fucks[R][R] + fucks[L][L]) - fucks[L][R];
}
inline int read() {
  while (true) {
    int c = getchar() - '0';
    if (0 <= c and c <= 9) return c;
  }
}
int *dp, *f;
int main() {
  int n, K;
  scanf("%d %d\n", &n, &K);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) fucks[i][j] = read();
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) fucks[i][j] += fucks[i][j - 1];
    for (int j = 1; j <= n; ++j) fucks[i][j] += fucks[i - 1][j];
  }
  static int dp[MAXK][MAXN], ks[MAXK][MAXN];
  for (int i = 1; i <= n; ++i) dp[1][i] = div2(fucks[i][i]), ks[1][i] = 0;
  for (int i = 2; i <= K; ++i) {
    ks[i][n + 1] = n;
    for (int j = n; j > 0; --j) {
      pair<int, int> ans{INF, 0};
      for (int k = ks[i - 1][j]; k <= ks[i][j + 1]; ++k)
        ans = min(ans, {dp[i - 1][k] + w(k, j), k});
      tie(dp[i][j], ks[i][j]) = ans;
    }
  }
  printf("%d\n", dp[K][n]);
  return 0;
}
